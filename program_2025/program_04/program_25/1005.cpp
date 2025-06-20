#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    int best = 0;
    for (int l = 1; l + n - 1 < m; l++)
    {
        for (int i = 0; i < n; i++)
        {
            char cur = ((a[i] - '0') ^ (b[l + i] - '0'));
            char bst = ((a[i] - '0') ^ (b[best + i] - '0'));

            if (cur > bst)
            {
                best = l;
                break;
            }
            else if (cur < bst)
                break;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (((a[i] - '0') ^ (b[best + i] - '0')) == 1)
            ans++;
    }

    cout << ans << "\n";
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