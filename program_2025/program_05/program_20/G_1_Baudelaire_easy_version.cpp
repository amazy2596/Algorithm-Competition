#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto query = [&](int u)
    {
        cout << "? 1 1 " << u << endl;

        int res;
        cin >> res;

        return res;
    };

    vector<int> ans(n + 1);
    int root = 0;
    int res1 = query(1);
    if (res1 == -2)
        ans[1] = root = -1;
    else if (res1 == 2)
        ans[1] = root = 1;
    else if (res1 == 0) 
    {
        cout << "? 2 1" << endl;
        int res2 = query(1);
        if (res2 == -2)
            ans[1] = root = -1;
        else if (res2 == 2)
            ans[1] = root = 1;
    }
    else 
    {
        ans[1] = res1;
        for (int i = 2; i <= n; i++)
        {
            int res = query(i);
            ans[i] = res - ans[1];
        }

        cout << "! ";
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
        return;
    }

    cout << "? 2 1" << endl;
    ans[1] = (ans[1] == 1 ? -1 : 1);

    for (int i = 2; i <= n; i++)
    {
        int res = query(i);
        // root -> root;
        // other -> root + ans[1] + ans[i];
        ans[i] = res - ans[1] - root;
    }

    // -1 1 -1
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
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