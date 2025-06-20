#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    string ans[2];
    ans[0] = "even";
    ans[1] = "odd";
    while (q--)
    {
        int i, j;
        cin >> i >> j;
        if (i != j)
            cout << ans[++m % 2] << "\n";
        else 
            cout << ans[m % 2] << "\n";
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