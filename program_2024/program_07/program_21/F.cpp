#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

intt fact[N], ifact[N];

intt fast_pow(intt a, intt b)
{
    intt res = 1 % mod;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

void init()
{
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
        ifact[i] = ifact[i - 1] * fast_pow(i, mod - 2) % mod;
    }
}

intt c(intt n, intt m)
{
    return (fact[n] * ifact[m]) % mod * ifact[n - m] % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    init();
    intt n;
    cin >> n;
    string s;
    cin >> s;
    intt num = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            num++;
        else if (s[i] == ')')
            num--;
        else 
            cnt++;
    }
    if (abs(num + cnt) % 2 == 1)
        cout << "0\n";
    else 
        cout << c(cnt, (cnt + num) / 2) % mod << "\n";
    return 0;
}