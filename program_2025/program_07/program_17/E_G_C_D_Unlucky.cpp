#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    vector<int> p(n), s(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 1; i < n; i++)
    {
        if (p[i - 1] % p[i] != 0)
        {
            cout << "NO\n";
            return;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i + 1] % s[i] != 0)
        {
            cout << "NO\n";
            return;
        }
    }

    if (p[n - 1] != s[0])
    {
        cout << "NO\n";
        return;
    }

    for (int i = 1; i < n; i++)
    {
        if (__gcd(p[i - 1], s[i]) != p[n - 1])
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}