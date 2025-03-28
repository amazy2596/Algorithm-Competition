#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[s[i]]++;
    if (mp.size() == 1)
    {
        cout << s << "\n";
        return;
    }
    priority_queue<pair<int, char>> q;
    for (auto [k, v] : mp)
        q.push({v, k});
    string ans;
    auto t1 = q.top();
    q.pop();
    auto t2 = q.top();
    int num = t1.first - t2.first;
    while (num-- > 0)
        ans += t1.second;
    q.push({t2.first, t1.second});
    while (!q.empty())
    {
        auto a = q.top();
        q.pop();
        ans += a.second;
        a.first--;
        if (a.first > 0)
            q.push({a.first, a.second});
    }
    cout << ans << "\n";
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