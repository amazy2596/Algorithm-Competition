#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> temp(n);
    for (int i = 0; i < n; i++)
        cin >> temp[i].first;
    for (int i = 0; i < n; i++)
        cin >> temp[i].second;
    map<int, int> pos;
    for (auto [p, d] : temp)
        pos[p] = d;

    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;

        map<pair<int, int>, int> vis;
        int dir = 0, t = 0;
        bool ok = 1;
        while (true)
        {
            bool redir = 0;
            auto it = pos.lower_bound(a);
            if (dir == 0)
            {
                if (vis.find({dir ^ 1, (*it).first}) != vis.end() && next(it) != pos.end())
                    it = next(it);
                while (it != pos.end())
                {
                    auto [p, d] = *it;
                    int cur = t + abs(p - a);
                    if (cur % k == d)
                    {
                        if (vis[{dir, p}])
                            ok = 0;
                        vis[{dir, p}] = 1;
                        redir = 1;
                        t = cur;
                        dir ^= 1;
                        a = p;
                        break;
                    }
                    it++;
                }
            }
            else 
            {
                if (vis.find({dir ^ 1, (*it).first}) != vis.end())
                {
                    if (it != pos.begin())
                    {
                        it--;
                        while (it != pos.begin())
                        {
                            auto [p, d] = *it;
                            int cur = t + abs(p - a);
                            if (cur % k == d)
                            {
                                if (vis[{dir, p}])
                                    ok = 0;
                                vis[{dir, p}] = 1;
                                redir = 1;
                                t = cur;
                                dir ^= 1;
                                a = p;
                                break;
                            }
                            it--;
                        }

                        if (it == pos.begin())
                        {
                            auto [p, d] = *it;
                            int cur = t + abs(p - a);
                            if (cur % k == d)
                            {
                                if (vis[{dir, p}])
                                    ok = 0;
                                vis[{dir, p}] = 1;
                                redir = 1;
                                t = cur;
                                dir ^= 1;
                                a = p;
                            }
                        }

                    }
                }
            }

            if (!ok)
            {
                cout << "NO\n";
                break;
            }
            else if (!redir)
            {
                cout << "YES\n";
                break;
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}