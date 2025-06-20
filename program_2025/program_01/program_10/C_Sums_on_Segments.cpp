#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> seg({{0, 0}}), can({{0, 0}});
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        bool f = 0;
        for (auto& [l, r] : can)
        {
            if (a == 1)
            {
                if (l == 0)
                    r++;
                else
                    l++, r++;
                seg.push_back({l, r});
            }
            else if (a == -1)
            {
                if (r == 0)
                    l--;
                else
                    l--, r--;
                seg.push_back({l, r});
            }
            else
            {
                seg.push_back({l + a, r + a});
                f = 1;
                l = 0, r = 0;
            }
        }
        if (f)
            can.push_back(seg.back());
    }

    sort(seg.begin(), seg.end());
    seg.erase(unique(seg.begin(), seg.end()), seg.end());
    auto [last_l, last_r] = *seg.begin();
    seg.erase(seg.begin());
    vector<pair<int, int>> ans;
    for (auto [l, r] : seg)
    {
        if (l > last_r)
        {
            ans.push_back({last_l, last_r});
            last_l = l, last_r = r;
        }
        last_r = max(last_r, r);
    }
    ans.push_back({last_l, last_r});
    queue<int> q;
    for (auto [l, r] : ans)
    {
        for (int i = l; i <= r; i++)
        {
            q.push(i);
        }
    }
    cout << q.size() << "\n";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
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