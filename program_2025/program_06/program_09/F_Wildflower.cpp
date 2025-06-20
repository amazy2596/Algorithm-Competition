#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int N = 1e6 + 5;
const int mod = 1000000007;
int fact[N], ifact[N], p[N];

int fast_pow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        
        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

vector<vector<int>> matrix_mul(vector<vector<int>> a, vector<vector<int>> b)
{
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
                res[i][j] += a[i][k] * b[k][j], res[i][j] %= mod;
        }
    }
    
    return res;
}

vector<vector<int>> matrix_pow(vector<vector<int>> a, int b)
{
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    while (b)
    {
        if (b & 1)
            res = matrix_mul(res, a);
        a = matrix_mul(a, a);
        b >>= 1;
    }

    return res;
}

void init()
{
    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = (p[i - 1] * 2) % mod;

    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    
    ifact[N - 1] = fast_pow(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--)
        ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
}

int C(int n, int m)
{
    if (n < m)
        return 0;
    return (fact[n] % mod * ifact[m] % mod * ifact[n - m] % mod) % mod;
}

int A(int n, int m)
{
    if (n < m)
        return 0;
    return (fact[n] % mod * ifact[n - m] % mod) % mod;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int leaf = 0;
    vector<int> depth(n + 1);
    int node = -1, x = -1, y = -1, node_leaf = -1;
    auto dfs = [&](auto dfs, int u, int p) -> int
    {
        if (u != 1 && adj[u].size() == 1)
            leaf++, node_leaf = u, depth[u] = 1;

        if (adj[u].size() == 3 || (u == 1 && adj[u].size() == 2))
            node = u;
        
        int mx = 0;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            if (u == node)
            {
                if (x == -1)
                    x = v;
                else if (y == -1)
                    y = v;
            }
            mx = max(mx, dfs(dfs, v, u));
        }

        depth[u] = mx + 1;
        return depth[u];
    };

    dfs(dfs, 1, 0);

    if (leaf >= 3)
    {
        cout << "0\n";
        return;
    }

    if (leaf == 1)
        node = node_leaf;

    int ans = 0;

    if (x != -1 && y != -1)
    {
        int X = depth[x], Y = depth[y];
        if (X < Y)
            swap(X, Y);
        if (X != Y)
        {
            ans = (ans + fast_pow(2, X - Y - 1)) % mod;
            ans = (ans + fast_pow(2, X - Y)) % mod;
        }
        else 
            ans = 2;
    }

    if (ans != 0)
        ans = (ans * fast_pow(2, depth[1] - depth[node] + 1));
    else 
        ans = fast_pow(2, depth[1] - depth[node] + 1);
    cout << ans % mod << "\n";
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