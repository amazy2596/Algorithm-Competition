#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

struct node
{
    int val, start, end;
};

void solve()
{
    int n;
    cin >> n;
    vector<node> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].val >> a[i].start >> a[i].end;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    sort(p.begin(), p.end(), [&](int i, int j){
        return a[i].start < a[j].start;
    });

    sort(a.begin(), a.end(), [&](node &a, node &b){
        return a.start < b.start;
    });

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        while (!q.empty())
        {
            auto [val, end] = q.top();
            if (end <= a[i].start)
            {
                q.pop();
                continue;
            }

            if (val <= a[i].val)
                ans[p[i]] = max(0ll, a[i].val - val);
            break;
        }
        q.push({a[i].val, a[i].end});
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
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