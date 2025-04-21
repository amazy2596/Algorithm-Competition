#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

struct node
{
    int val, i, j;

    const bool operator<(const node other) const
    {
        if (i == other.i)
            return j > other.j;
        
        return val > other.val;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector a(n, vector<int>());
    priority_queue<node> q;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            cin >> a[i][j];
            q.push({a[i][j], i, j});
        }
    }

    vector<int> v;
    while (!q.empty())
    {
        if (v.empty())
            v.push_back(q.top().val), q.pop();
        else 
        {
            if (q.top().val != v.back() + 1)
            {
                cout << "NO\n";
                return;
            }
            else 
                v.push_back(q.top().val), q.pop();
        }
    }

    cout << "YES\n";
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