#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; i++)
        cin >> a[i], s.insert(a[i]);

    if (s.size() == 1)
    {
        cout << "0\n";
        return;
    }

    ranges::sort(a);

    if (a[0] != 0)
    {
        cout << "-1\n";
        return;
    }

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] != a[i])
            ans += a[i] - a[i - 1] - 1;
    }
    cout << ans + 1 << "\n";

    // 0 1 3 4 7 9
    // 0 0 1 2 5 7
    // 0 0 0 0 2 4
    // 0 0 0 0 1 3
    // 0 0 0 0 0 1
    // 0 0 0 0 0 0
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