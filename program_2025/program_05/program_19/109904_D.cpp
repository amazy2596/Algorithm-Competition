#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 4e18;
int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), vis(n, 1);
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i)
            q.push({a[i], i});
    }

    int cnt = 0;
    while (cnt++ < k)
    {
        a[0] += q.top().first;
        vis[q.top().second] = 0;
        q.pop();
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            cout << a[i] << " ";
    }
    cout << "\n";
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