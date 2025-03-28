#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack<int> sta;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        if (sta.empty() || sta.top() <= a[i])
            sta.push(a[i]);
        else
        {
            while (!sta.empty() && sta.top() > a[i])
            {
                s.insert(sta.top());
                sta.pop();
            }
            sta.push(a[i]);
        }
    }
    while (!s.empty())
    {
        int fro = *s.begin() + 1;
        s.erase(s.begin());
        if (sta.top() <= fro)
            sta.push(fro);
        else
        {
            while (!sta.empty() && sta.top() > fro)
            {
                s.insert(sta.top());
                sta.pop();
            }
            sta.push(fro);
        }
    }
    vector<int> ans;
    while (!sta.empty())
    {
        ans.push_back(sta.top());
        sta.pop();
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " \n"[i == 0];
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