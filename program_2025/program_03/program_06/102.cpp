#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<double> price(n + 1);
    vector<int> num(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> price[i];
    double ans = 0;
    while (true)
    {
        int id, cnt;
        cin >> id >> cnt;
        if (id == 0)
            break;
        num[id] += cnt;
        ans += cnt * price[id];
    }

    for (int i = 1; i <= n; i++)
        cout << num[i] << "\n";
    cout << fixed << setprecision(2) << ans;
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