#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };



void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x % k]++;
    }

    for (int i = 0; i < n; i++)
    {
        int x = a[i] % k;
        int y = abs(k - (a[i] - a[i] / k * k));
        if (mp.find(x) != mp.end())
        {
            mp[x]--;
            if (mp[x] == 0)
                mp.erase(x);
        }
        else if (mp.find(y) != mp.end())
        {
            mp[y]--;
            if (mp[y] == 0)
                mp.erase(y);
        }
    }

    cout << (mp.size() == 0 ? "YES\n" : "NO\n");
}

int main()
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