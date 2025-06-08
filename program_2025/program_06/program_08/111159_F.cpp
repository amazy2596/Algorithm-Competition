#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

void solve()
{   
    int q;
    cin >> q;

    map<int, pair<int, int>> internals;
    int N = 1e5 + 5;
    internals[1] = {N, 0};

    auto split = [&](int pos)
    {
        auto it = internals.lower_bound(pos);

        if (it == internals.begin())
            return;
        it--;

        int L = (*it).first;

        if (L == pos)
            return;

        auto [R, x] = (*it).second;

        if (pos > R)
            return ;

        internals[L] = {pos - 1, x};
        internals[pos] = {R, x};
    };

    unordered_map<int, int> vis;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;

        split(l);
        split(r + 1);

        unordered_set<int> toerase;
        auto it = internals.lower_bound(l);
        
        while (it != internals.end())
        {
            int L = (*it).first;
            auto [R, val] = (*it).second;
            if (L > r)
                break;

            if (val != 0)
            {
                vis[val] -= R - L + 1;
                if (vis[val] == 0)
                    vis.erase(val);
            }
            toerase.insert(L);
            it++;
        }

        for (auto temp : toerase)
            internals.erase(temp);

        vis[x] += r - l + 1;
        internals[l] = {r, x};

        cout << vis.size() + 1 << "\n";
    }
}

signed main()
{
	// ios::sync_with_stdio(false);
	// cout.tie(nullptr);
	// cin.tie(nullptr);
	// init();
	int T = 1;
	// cin >> T;
	while (T--)
		solve();
	return 0;
}