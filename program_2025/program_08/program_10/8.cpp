#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<i64> a(n);
    map<i64, i64> mp;
    priority_queue<i64, vector<i64>, greater<i64>> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        q.push(a[i]);
    }

    if (x == 0 || y == 0)
    {
        cout << "0\n";
        return;
    }

    map<i64, set<i64>> mp1;
    for (auto [key, val] : mp)
        mp1[val].insert(key);

    i64 ans = (n - mp1.rbegin()->first) * y;
    i64 pre = 0;
    while (!q.empty())
    {
        i64 cur = q.top();
        q.pop();

        mp1[mp[cur]].erase(cur);
        if (mp1[mp[cur]].size() == 0)
            mp1.erase(mp[cur]);
        mp[cur]--;
        if (mp[cur] == 0)
            mp.erase(cur);
        cur -= pre;
        mp[cur]++;
        mp1[mp[cur]].insert(cur);
        ans = min(ans, (n - mp1.rbegin()->first) * y + pre * x);

        mp1[mp[cur]].erase(cur);
        if (mp1[mp[cur]].size() == 0)
            mp1.erase(mp[cur]);
        mp[cur]--;
        if (mp[cur] == 0)
            mp.erase(cur);
        pre += cur;
        cur = 0;
        mp[cur]++;
        mp1[mp[cur]].insert(cur);
        ans = min(ans, (n - mp1.rbegin()->first) * y + pre * x);
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}