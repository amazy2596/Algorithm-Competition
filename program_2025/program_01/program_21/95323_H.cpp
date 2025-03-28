#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    vector<int> ans(n + 1), p(n + 1), fa(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
        fa[i] = i;
    }

    iota(p.begin(), p.end(), 0);
    sort(p.begin() + 1, p.end(), [&](int &i, int &j)
    {
        if (a[i].second == a[j].second)
            return a[i].first < a[j].first;
        
        return a[i].second < a[j].second;
    });
    sort(a.begin() + 1, a.end(), [&](pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        
        return a.second < b.second;
    });

    auto find = [&](auto find, int x) -> int
    {
        if (x > n)
            return n + 1;
        return fa[x] == x ? x : fa[x] = find(find, fa[x]);
    };
    
    for (int i = 1; i <= n; i++)
    {
        int l = find(find, a[i].first), r = a[i].second;

        if (l <= r)
        {
            ans[p[i]] = l;
            fa[l] = l + 1;
        }
        else 
        {
            cout << -1 << "\n";
            return;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
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