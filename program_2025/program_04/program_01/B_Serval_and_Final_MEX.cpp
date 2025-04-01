#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<array<int, 2>> ans;
    int pos = 1;
    while (pos < a.size() - 1)
    {
        if (a[pos] == 0)
        {
            ans.push_back({pos, pos + 1});
            a[pos] = a[pos + 1] == 1 ? 2 : 1;
            a.erase(a.begin() + pos + 1);
        }
        else 
            pos++;
    }

    if (a.back() == 0)
    {
        cout << ans.size() + 2 << "\n";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i][0] << " " << ans[i][1] << "\n";
        
        cout << a.size() - 2 << " " << a.size() - 1 << "\n";
        a.pop_back();
        cout << 1 << " " << a.size() - 1 << "\n";
    }
    else
    {
        cout << ans.size() + 1 << "\n";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i][0] << " " << ans[i][1] << "\n";
        
        cout << 1 << " "  << a.size() - 1 << "\n";
    }
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