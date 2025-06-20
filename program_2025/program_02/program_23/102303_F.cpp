#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> ans;
    map<int, int> mp;
    ans.push_back(1);
    mp[1]++;
    for (int i = 2; ans.size() < n; i++)
    {
        int k = ans.size();
        ans.push_back(i);
        mp[i]++;
        for (int j = 0; j < k && ans.size() < n; j++)
            ans.push_back(ans[j]), mp[ans[j]]++;
    }
    cout << mp.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    // 1 2 1 3 1 2 1 4 
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