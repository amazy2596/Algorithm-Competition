#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + (s[i] == '1');
    
    int ans = 0;
    for (int k = 1; k <= n; k++)
    {
        int temp = 1;
        for (int i = 1; i <= n; i += k)
        {
            int l = i, r = min(n, i + k - 1);
            temp += (pre[r] - pre[l - 1] < (r - l + 1) && (pre[r] - pre[l - 1] > 0));
        }

        ans ^= temp;
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