#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

struct node
{
    int l, r, id;
    
    const bool operator<(const node other) const 
    {
        return r > other.r;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }

    sort(a.begin() + 1, a.end());

    // for (int i = 1; i <= n; i++)
        // cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << "\n";

    vector<int> ans;
    priority_queue<node> q;
    int sum = 0, i = 1;
    while (true)
    {
        while (i <= n && a[i][0] <= sum)
        {
            q.push({a[i][0], a[i][1], a[i][2]});
            i++;
        }

        while (!q.empty() && q.top().r < sum)
            q.pop();

        if (q.empty())
            break;

        ans.push_back(q.top().id);
        q.pop();
        sum++;
    }

    cout << ans.size() << "\n";

    for (auto a : ans)
        cout << a << " ";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}