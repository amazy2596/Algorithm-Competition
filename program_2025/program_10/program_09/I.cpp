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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i - 1] > a[i]) cnt++;
    }

    map<int, int> mp;
    vector<vector<int>> control(n + 1);
    vector<int> num(n + 1);
    for (int k = 1; k <= n; k++)
    {
        for (int pos = 1; pos <= n; pos += k)
        {
            control[pos].push_back(k);
            num[k] += (a[pos] - 1 > a[pos]);
        }
    }
    for (int k = 1; k <= n; k++)
        mp[num[k]]++;

    auto update = [&](int pos, int val)
    {
        cnt += val;
        for (auto k : control[pos])
        {
            mp[num[k]]--;
            num[k] += val;
            mp[num[k]]++;
        }
    };

    cout << mp[cnt] << "\n";
    while (q--)
    {
        int p, v;
        cin >> p >> v;

        if (a[p - 1] > a[p] && a[p - 1] <= v)
            update(p, -1);
        if (a[p - 1] <= a[p] && a[p - 1] > v)
            update(p, 1);
        if (p + 1 <= n && a[p] > a[p + 1] && v <= a[p + 1])
            update(p + 1, -1);
        if (p + 1 <= n && a[p] <= a[p + 1] && v > a[p + 1])
            update(p + 1, 1);
        a[p] = v;

        cout << mp[cnt] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}