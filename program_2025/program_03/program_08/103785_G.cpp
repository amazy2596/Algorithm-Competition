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
    int l = -1, r = -1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '3')
        {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '3')
        {
            r = i;
            break;
        }
    }

    if (l == -1 || r == -1)
    {
        cout << "0\n";
        return;
    }

    if (l == r)
    {
        int rr = r;
        for (int i = n - 1; i > r; i--)
        {
            if (s[i] == '8')
            {
                rr = i;
                break;
            }
        }

        int ll = l;
        for (int i = l; i < n; i++)
        {
            if (s[i] == '8')
            {
                ll = i;
                break;
            }
        }
        ans = max(ans, rr - ll);
    }
    else 
    {
        ans = max(ans, r - l);
        int tar = r;
        for (int i = n - 1; i > r; i--)
        {
            if (s[i] == '8')
            {
                tar = i;
                break;
            }
        }

        ans = max(ans, tar - l);
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