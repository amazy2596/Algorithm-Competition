#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int x, y, z;
    x = n, y = m, z = k;
    string s;
    cin >> s;
    int len = s.length();
    len -= len & 1;

    if (len == 0)
    {
        cout << "0\n";
        return;
    }

    string tar = s + s;

    int ans = 0;
    auto update = [&](int pos, int x)
    {
        if (tar[pos - 1] == '0' && tar[pos] == '0')
        {
            if (n + x >= 0)
            {
                n += x;
                return true;
            }
        }
        else if ((tar[pos - 1] == '0' && tar[pos] == '1') || (tar[pos - 1] == '1' && tar[pos] == '0'))
        {
            if (m + x >= 0)
            {
                m += x;
                return true;
            }
        }
        else if (tar[pos - 1] == '1' && tar[pos] == '1')
        {
            if (k + x >= 0)
            {
                k += x;
                return true;
            }
        }

        return false;
    };

    int l = 0, r = 1;
    while (r < tar.length())
    {
        if (r - l - 1 > len)
        {
            ans = len;
            break;
        }

        if (update(r, -1))
        {
            r += 2;
            ans = max(ans, r - l - 1);
        }
        else if (l + 2 <= r)
        {
            ans = max(ans, r - l - 1);
            update(l + 1, 1);
            l += 2;
        }
        else if (r + 2 < tar.length())
            r += 2, l += 2;
        else 
            break;
    }

    n = x, m = y, k = z;
    l = 1, r = 2;
    while (r < tar.length())
    {
        if (r - l - 1 > len)
        {
            ans = len;
            break;
        }

        if (update(r, -1))
        {
            r += 2;
            ans = max(ans, r - l - 1);
        }
        else if (l + 2 <= r)
        {
            ans = max(ans, r - l - 1);
            update(l + 1, 1);
            l += 2;
        }
        else if (r + 2 < tar.length())
            r += 2, l += 2;
        else 
            break;
    }

    // reverse(s.begin(), s.end());
    // tar = s + s;

    // n = x, m = y, k = z;
    // l = 0, r = 1;
    // while (r < tar.length())
    // {
    //     if (r - l - 1 > len)
    //     {
    //         ans = len;
    //         break;
    //     }

    //     if (update(r, -1))
    //         r += 2;
    //     else if (l + 2 <= r)
    //     {
    //         ans = max(ans, r - l - 1);
    //         update(l + 1, 1);
    //         l += 2;
    //     }
    //     else if (r + 2 < tar.length())
    //         r += 2, l += 2;
    //     else 
    //         break;
    // }

    // n = x, m = y, k = z;
    // l = 1, r = 2;
    // while (r < tar.length())
    // {
    //     if (r - l - 1 > len)
    //     {
    //         ans = len;
    //         break;
    //     }

    //     if (update(r, -1))
    //         r += 2;
    //     else if (l + 2 <= r)
    //     {
    //         ans = max(ans, r - l - 1);
    //         update(l + 1, 1);
    //         l += 2;
    //     }
    //     else if (r + 2 < tar.length())
    //         r += 2, l += 2;
    //     else 
    //         break;
    // }

    cout << min(ans, len) << "\n";
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