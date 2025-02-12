#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

struct node
{
    int val, type, i, j;

    bool operator<(node other) const
    {
        return val < other.val;
    }
};

void solve()
{
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i] %= p;
    
    sort(a.begin(), a.end());
    vector<int> j_max(n, -1);
    for (int i = 0; i < n; i++)
    {
        auto j = lower_bound(a.begin() + i + 1, a.end(), p - a[i]) - a.begin() - 1;
        j_max[i] = (j > i ? j : -1);
    }

    vector<int> j_min(n, -1);
    for (int i = 0; i < n; i++)
    {
        auto j = lower_bound(a.begin() + i + 1, a.end(), p - a[i]) - a.begin();
        j_min[i] = (j > i ? j : -1);
    }

    priority_queue<node> q;
    for (int i = 0; i < n; i++)
    {
        if (j_max[i] != -1)
            q.push({a[i] + a[j_max[i]], 0, i, j_max[i]});
        if (j_min[i] != -1)
        {
            int cur_j = n - 1;
            if (cur_j > i && cur_j >= j_min[i])
                q.push({a[i] + a[cur_j] - p, 1, i, cur_j});
        }
    }

    vector<int> ans;
    while (k > 0 && !q.empty())
    {
        auto [val, type, i, j] = q.top();
        q.pop();
        ans.push_back(val);
        k--;
        if (type == 0)
        {
            int ne_j = j - 1;
            if (ne_j > i)
                q.push({a[i] + a[ne_j], 0, i, ne_j});
        }
        else 
        {
            int ne_j = j - 1;
            if (ne_j > i && ne_j >= j_min[i])
                q.push({a[i] + a[ne_j] - p, 1, i, ne_j});
        }
    }

    while (k > 0)
    {
        ans.push_back(-1);
        k--;
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i == ans.size() - 1];
}

signed main()
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