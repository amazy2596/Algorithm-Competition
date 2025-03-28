#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const intt mod = 1e9 + 7;

intt fast_pow(intt a, intt b)
{
    intt res = 1 % mod;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        intt l, r, k;
        cin >> l >> r >> k;
        int t = 0;
        for (t = 0; ; t++)
            if (t * k >= 10)
                break;
        intt ans1 = fast_pow(t, r);
        intt ans2 = fast_pow(t, l);
        cout << (ans1 - ans2 + mod) % mod << "\n";
    }
    return 0;
}