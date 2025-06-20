#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    map<tuple<int, int, int>, int> mp;
    int count[3][2][2] = {};
    for (int i = 0; i < n; i++)
    {
        int cur = v[i];
        int a = 0, b = 0, c = 0;
        while (cur % 3 == 0)
        {
            a++;
            cur /= 3;
        }
        while (cur % 5 == 0)
        {
            b++;
            cur /= 5;
        }
        while (cur % 11 == 0)
        {
            c++;
            cur /= 11;
        }
        a = min(a, 2ll);
        b = min(b, 1ll);
        c = min(c, 1ll);
        mp[{a, b, c}]++;
    }
    int ans = 0;
    for (auto [t1, v1] : mp)
    {
        for (auto [t2, v2] : mp)
        {
            auto [a3, a5, a11] = t1;
            auto [b3, b5, b11] = t2;
            if (a3 + b3 >= 2 && a5 + b5 >= 1 && a11 + b11 >= 1)
            {
                if (t1 == t2)
                    ans += v1 * (v1 - 1);
                else
                    ans += (v1 * v2);
            }
        }
    }
    ans /= 2;
    for (int i = 0; i < n; i++)
    {
        int cur1 = v[i], cur2 = v[i] + 1;
        int a = 0, b = 0, c = 0;
        while (cur1 % 3 == 0)
        {
            a++;
            cur1 /= 3;
        }
        while (cur1 % 5 == 0)
        {
            b++;
            cur1 /= 5;
        }
        while (cur1 % 11 == 0)
        {
            c++;
            cur1 /= 11;
        }
        a = min(a, 2ll);
        b = min(b, 1ll);
        c = min(c, 1ll);
        mp[{a, b, c}]--;
        int x = 0, y = 0, z = 0;
        while (cur2 % 3 == 0)
        {
            x++;
            cur2 /= 3;
        }
        while (cur2 % 5 == 0)
        {
            y++;
            cur2 /= 5;
        }
        while (cur2 % 11 == 0)
        {
            z++;
            cur2 /= 11;
        }
        x = min(x, 2ll);
        y = min(y, 1ll);
        z = min(z, 1ll);
        mp[{x, y, z}]++;
        int pairs = 0;
        for (auto [t1, v1] : mp)
        {
            for (auto [t2, v2] : mp)
            {
                auto [a3, a5, a11] = t1;
                auto [b3, b5, b11] = t2;
                if (a3 + b3 >= 2 && a5 + b5 >= 1 && a11 + b11 >= 1)
                {
                    if (t1 == t2)
                        pairs += v1 * (v1 - 1);
                    else
                        pairs += (v1 * v2);
                }
            }
        }
        ans = max(ans, pairs / 2);
        mp[{a, b, c}]++;
        mp[{x, y, z}]--;
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}