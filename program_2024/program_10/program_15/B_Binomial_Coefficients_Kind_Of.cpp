#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

int fast_pow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res % mod * a % mod % mod;
        b >>= 1;
        a = a % mod * a % mod % mod;
    }
    return res % mod;
}

void solve()
{
    int t;
    cin >> t;
    vector<int> n(t), k(t);
    for (int i = 0; i < t; i++)
        cin >> n[i];
    for (int i = 0; i < t; i++)
        cin >> k[i];
    for (int i = 0; i < t; i++)
        cout << fast_pow(2, k[i]) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    // init();
    while (T--)
        solve();
    return 0;
}