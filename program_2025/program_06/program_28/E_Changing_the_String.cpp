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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    map<pair<int, int>, set<int>> mp;
    for (int i = 0; i < q; i++)
    {
        char x, y;
        cin >> x >> y;
        mp[{x, y}].insert(i);
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'b')
        {
            if (mp[{'b', 'a'}].size())
            {
                mp[{'b', 'a'}].erase(mp[{'b', 'a'}].begin());
                s[i] = 'a';
            }
            else if (mp[{'b', 'c'}].size() && mp[{'c', 'a'}].size())
            {
                int id = *mp[{'b', 'c'}].begin();
                auto it = mp[{'c', 'a'}].lower_bound(id);
                if (it != mp[{'c', 'a'}].end())
                {
                    mp[{'b', 'c'}].erase(id);
                    mp[{'c', 'a'}].erase(it);
                    s[i] = 'a';
                }
            }
        }
        else if (s[i] == 'c')
        {
            if (mp[{'c', 'a'}].size())
            {
                mp[{'c', 'a'}].erase(mp[{'c', 'a'}].begin());
                s[i] = 'a';
                continue;
            }
            else if (mp[{'c', 'b'}].size() && mp[{'b', 'a'}].size())
            {
                int id = *mp[{'c', 'b'}].begin();
                auto it = mp[{'b', 'a'}].lower_bound(id);
                if (it != mp[{'b', 'a'}].end())
                {
                    mp[{'c', 'b'}].erase(id);
                    mp[{'b', 'a'}].erase(it);
                    s[i] = 'a';
                    continue;
                }
            }

            if (mp[{'c', 'b'}].size())
            {
                mp[{'c', 'b'}].erase(mp[{'c', 'b'}].begin());
                s[i] = 'b';
            }
        }
    }

    cout << s << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}