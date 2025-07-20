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
    string s;
    cin >> s;
    s = " " + s;
    vector<vector<int>> adj(n + 1);
    vector<int> fa(n + 1);
    for (int u = 2; u <= n; u++)
    {
        int p;
        cin >> p;
        adj[p].push_back(u);
        fa[u] = p;
    }

    vector<int> ans(n + 1), count(n + 1);
    stack<int> st;
    auto dfs = [&](auto dfs, int u) -> void
    {
        int node = -1;
        if (s[u] == '(')
            st.push(u);
        else if (!st.empty())
        {
            node = st.top();
            st.pop();
            count[u] = 1 + count[fa[node]];
        }

        ans[u] = ans[fa[u]] + count[u];
        for (auto v : adj[u])
            dfs(dfs, v);

        if (s[u] == '(')
            st.pop();
        if (node != -1)
            st.push(node);
    };
    dfs(dfs, 1);

    int out = 0;
    for (int i = 1; i <= n; i++)
        out ^= (i * ans[i]);

    cout << out << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}