#include <bits/stdc++.h>
using intt = long long;
using namespace std;

intt fast_pow(intt a, intt b, int mod)
{
    intt res = 1 % mod;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

intt c[5005][5005];
void init(int mod)
{
    c[0][0] = 1;
    for (int i = 0; i <= 5000; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= 5000; j++)
            if (i >= 1 && j >= 1)
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, m, mod;
    cin >> n >> m >> mod;
    init(mod);
    intt ans = 0;
    for (int k = 1; k <= n; k++)
    {
        intt temp = c[n][k];
        temp = (temp * fast_pow(fast_pow(2, k, mod) - 1, m - 1, mod) % mod);
        temp = (temp * fast_pow(2, (n - k) * (m - 1), mod) % mod);
        ans = (ans + temp) % mod;
    }
    cout << ans % mod << "\n";
    return 0;
}