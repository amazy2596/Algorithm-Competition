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

struct node
{
    int u, op, t;
};

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<array<int, 2>> dist_R(n + 1, {inf, inf});
    queue<node> q;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int r;
        cin >> r;
        q.push({r, 0, 0});
        dist_R[r][0] = 0;
    }

    while (!q.empty())
    {
        auto [u, op, t] = q.front();
        q.pop();

        if (t == d)
            continue;
        
        for (auto v : adj[u])
        {
            if (t + 1 < dist_R[v][op ^ 1])
            {
                dist_R[v][op ^ 1] = t + 1;
                q.push({v, op ^ 1, t + 1});
            }
        }
    }

    vector<array<int, 2>> dist(n + 1, {inf, inf}), rev(n + 1, {-1, -1});
    dist[1][0] = 0;
    q.push({1, 0, 0});

    while (!q.empty())
    {
        auto [u, op, t] = q.front();
        q.pop();

        if (u == n)
        {
            vector<int> ans;
            ans.push_back(n);
            int current_op = op;
            while (ans.back() != 1 || (ans.back() == 1 && current_op != 0))
            {
                int prev_node = rev[ans.back()][current_op];
                ans.push_back(prev_node);
                current_op ^= 1;
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() - 1 << "\n";
            for (auto x : ans)
                cout << x << " ";
            cout << "\n";
            return;
        }

        for (auto v : adj[u])
        {
            if (t + 1 < dist[v][op ^ 1])
            {
                if (t + 1 < dist_R[v][op ^ 1])
                {
                    rev[v][op ^ 1] = u;
                    dist[v][op ^ 1] = t + 1; 
                    q.push({v, op ^ 1, t + 1});
                }
            }
        }
    }

    cout << "-1\n";
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