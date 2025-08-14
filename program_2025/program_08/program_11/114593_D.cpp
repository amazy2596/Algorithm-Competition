#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 1; i < n; i++)
        cnt += (s[i - 1] != s[i]);

    if (cnt >= 3)
        cout << "0\n";
    else if (cnt == 2)
    {
        if (s == "0110" || s == "1001")
            cout << 2 << "\n";
        else 
            cout << 1 << "\n";
    }
    else if (cnt == 1)
    {
        if (s == "1100" || s == "0011")
            cout << 2 << "\n";
        else 
            cout << 1 << "\n";
    }
    else 
        cout << 2 << "\n";
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