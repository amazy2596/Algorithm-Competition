#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    int ans = 0;
    vector<int> a(n + 2);
    for (int l = 1; l + k - 1 <= n; l++)
    {
        int r = l + k - 1;
        // for (int i = l + 1; i <= r; i++)
            // ans += abs(s[i] - s[i - 1]);
        a[l + 1]++;
        a[r + 1]--;
    }
    int sum = 0;
    for (int i = 2; i <= n; i++)
    {
        sum += a[i];
        ans += abs(s[i] - s[i - 1]) * sum;
    }

    cout << ans << "\n";
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