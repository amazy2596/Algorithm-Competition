#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    int cnt_1 = 0;
    int sum = 0;
    for (auto &[key, val] : mp)
    {
        if (val == 1)
            cnt_1++;
        else
            sum += val - 2;
    }

    if (sum >= cnt_1)
    {
        cout << sum << "\n";
    }
    else 
    {
        cout << sum + (cnt_1 - sum) / 2 << "\n";
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