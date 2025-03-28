#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n);
    int count = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
        count += a[i] == 1;
    }
    cout << count % 2 << " " << (count > n ? 2 * n - count : count) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}