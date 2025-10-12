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

map<int, int> val = {{1, 8}, {2, 4}, {3, 2}, {4, 1}, {5, 12}, {6, 3}, {7, 10}, {8, 5}, {9, 15}};
map<i64, set<int>> mp;

int convert(array<string, 2> &a)
{
    int res = 0;
    res += (a[0][0] - '0') * (1 << 3);
    res += (a[0][1] - '0') * (1 << 2);
    res += (a[1][0] - '0') * (1 << 1);
    res += (a[1][1] - '0');
    return res;
}

void init()
{
    for (int mask = 0; mask < (1 << 4); mask++)
    {
        set<int> used;
        auto dfs = [&](auto self, int now, i64 op)
        {
            if (now == 15)
            {
                mp[op].insert(mask);
                return;
            }

            for (int cur = 1; cur <= 9; cur++)
            {
                if (used.count(cur)) continue;
                op = op * 10 + cur;
                now += val[cur];
                used.insert(cur);
                self(self, now, op);
                op /= 10;
                now -= val[cur];
                used.erase(cur);
            }
        };
        dfs(dfs, mask, 0ll);
    }
}

vector<int> a(4);

void solve()
{
    int m;
    cin >> m;
    set<int> has;
    for (int i = 0; i < m; i++)
    {
        array<string, 2> cur;
        cin >> cur[0] >> cur[1];
        has.insert(convert(cur));
    }

    i64 ans = INF;
    for (auto &[key, s] : mp)
    {
        bool f = 1;
        for (auto x : has)
        {
            if (!s.count(x))
            {
                f = 0;
                break;
            }
        }

        if (f)
        {
            i64 cost = 0;
            i64 tmp = key;
            while (tmp)
            {
                int back = tmp % 10;
                if (back == 9) cost += a[3];
                if (back >= 7 && back <= 8) cost += a[2];
                if (back >= 5 && back <= 6) cost += a[1];
                if (back >= 1 && back <= 4) cost += a[0];
                tmp /= 10;
            }

            ans = min(ans, cost);
        }
    }

    cout << ans + *min_element(a.begin(), a.end()) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    for (int i = 0; i < 4; i++) cin >> a[i];
    while (T--)
        solve();
    return 0;
}
