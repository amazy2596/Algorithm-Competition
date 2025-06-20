#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    const intt mod = 998244353;
    intt t;
    cin >> t;
    while (t--)
    {
        intt l, r;
        cin >> l >> r;
        auto calc = [&](intt x)
        {
            intt res = 0;
            for (int i = 0; i < 63; i++)
            {
                intt a = ((x >> (i + 1)) % mod * (1ll << i) % mod) % mod;
                intt b = ((x & ((1ll << i) - 1)) + 1) % mod;
                res = (res + a) % mod;
                if ((x >> i) & 1)
                    res = (res + b) % mod;
            }
            return res;
        };
        cout << (calc(r) - calc(l - 1) + mod) % mod << "\n";
    }
    return 0;
}