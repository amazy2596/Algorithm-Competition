#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    vector<int> a;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
        if (i == 1)
            a.push_back(0);
    }

    int ans = 0;
    for (int i = -1000; i <= 1000; i++)
    {
        a[2] = i;
        int temp = 0;
        for (int j = 2; j < 5; j++)
            temp += (a[j] == a[j - 1] + a[j - 2]);
        ans = max(ans, temp);
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