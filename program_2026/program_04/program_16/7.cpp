#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

struct node
{
    int i, j, val;

    bool operator<(node o) const 
    {
        return val < o.val;
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    priority_queue<node> pq;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int val;
            cin >> val;
            pq.push({i, j, val});
        }
    }

    vector<int> row(n + 1), col(m + 1);
    while (pq.size() && k > 0)
    {
        auto [i, j, val] = pq.top();
        pq.pop();
        if (row[i] || col[j]) continue;
        k--;
        row[i] = 1, col[j] = 1;
    }
    while (pq.size())
    {
        auto [i, j, val] = pq.top();
        pq.pop();
        if (row[i] || col[j]) continue;
        g[i][j] = val;
    }

    for (int i = 1; i <= n; i++)
    {
        bool f = 0;
        int ed = m;
        for (int j = m; j >= 1; j--)
        {
            if (g[i][j] != 0)
            {
                ed = j;
                break;
            }
        }
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] != 0)
            {
                cout << g[i][j];
                if (j != ed) cout << " ";
                f = 1;
            }
        }
        if (f) cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}