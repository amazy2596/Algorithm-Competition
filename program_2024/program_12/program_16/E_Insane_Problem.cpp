#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    vector<int> temp;
    for (int i = 0; i <= 32; i++)
        temp.push_back(pow(k, i));
    
    int ans = 0;
    for (auto tar : temp)
    {
        if (tar * r1 < l2 || tar * l1 > r2)
            continue;
        
        int mx = min(r1, r2 / tar);
        int mn = max(l1, (int)ceil(l2 * 1.0 / tar));

        if (mx >= mn)
            ans += mx - mn + 1;
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