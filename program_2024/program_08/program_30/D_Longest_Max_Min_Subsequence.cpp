#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node_mn
{
    pair<int, int> data;
};

struct node_mx
{
    pair<int, int> data;
};

operator<(const node_mn a, const node_mn b)
{
    if (a.data.first == b.data.first)
        return a.data.second < b.data.second;
    return a.data.first < b.data.first;
}

operator<(const node_mx a, const node_mx b)
{
    if (a.data.first == b.data.first)
        return a.data.second < b.data.second;
    return a.data.first > b.data.first;    
}

const operator<()

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), l(n + 1, INT32_MAX);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        l[a[i]] = i;
    }
    priority_queue<int, vector<int>, greater<int>> ls(l.begin(), l.end());
    priority_queue<pair<int, int>> mx;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mn;
    for (int i = 1; i <= ls.top(); i++)
    {
        mx.push({a[i], i});
        mn.push({a[i], i});
    }
    vector<int> ans;
    int i = 1;
    vector<int> used(n + 1, 0);
    while (!mn.empty())
    {
        auto [x, pos] = (ans.size() % 2 == 0 ? mx.top() : mn.top());
        if (ans.size() % 2 == 0)
            mx.pop();
        else 
            mn.pop();
        ans.push_back(x);
        i = pos, used[x] = 1;
        while (ls.top() != INT32_MAX && used[a[ls.top()]])
        {
            int j = ls.top();
            ls.pop();
            for (int k = j; k <= min(ls.top(), n); k++)
            {
                mx.push({a[k], k});
                mn.push({a[k], k});
            }
        }
        while (!mx.empty() && (used[mx.top().first] || mx.top().second < i))
            mx.pop();
        while (!mn.empty() && (used[mn.top().first] || mn.top().second < i))
            mn.pop();
    }
    cout << ans.size() << "\n";
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