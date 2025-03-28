#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), suf(n + 1, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<int> all;    
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            if (a[i][j] != 1)
                break;    
            sum++;
        }
        all.push_back(sum);
    }
    sort(all.begin(), all.end());
    int mex = 0;
    for (int i = 0; i < all.size(); i++)
    {
        if (all[i] >= mex)
            mex++;
    }

    cout << min(mex, n) << "\n";
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