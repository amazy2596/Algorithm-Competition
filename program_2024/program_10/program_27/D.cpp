#include <bits/stdc++.h>
#define int long long
using namespace std;

map<int, int> mp;
int dfs(int mask, const vector<int> &medicine)
{
    if (mask == 0)
        return 0;
    if (mp.count(mask))
        return mp[mask];
    int mn = INT32_MAX;
    for (int i = 0; i < medicine.size(); i++)
    {
        int new_mask = mask & ~medicine[i];
        if (new_mask != mask)
            mn = min(mn, dfs(new_mask, medicine) + 1);
    }
    mp[mask] = mn;
    return mn;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        a[i] = stoi(temp, nullptr, 2);
    }
    int k;
    cin >> k;
    vector<int> b(k);
    for (int i = 0; i < k; i++)
    {
        string temp;
        cin >> temp;
        b[i] = stoi(temp, nullptr, 2);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        mp.clear();
        int mn = dfs(a[i], b);
        ans.push_back(mn == INT32_MAX ? -1 : mn);
    }
    for (auto cur : ans)
        cout << cur << "\n";
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