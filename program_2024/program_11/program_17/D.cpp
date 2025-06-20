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
        count[a][b][c]++;
    }
    int ans = 0;
    for (int a1 = 0; a1 <= 2; a1++)
    {
        for (int b1 = 0; b1 <= 1; b1++)
        {
            for (int c1 = 0; c1 <= 1; c1++)
            {
                for (int a2 = 0; a2 <= 2; a2++)
                {
                    for (int b2 = 0; b2 <= 1; b2++)
                    {
                        for (int c2 = 0; c2 <= 1; c2++)
                        {
                            int e3 = a1 + a2, e5 = b1 + b2, e11 = c1 + c2;
                            if (e3 >= 2 && e5 >= 1 && e11 >= 1)
                            {
                                int cnt1 = count[a1][b1][c1];
                                int cnt2 = count[a2][b2][c2];

                                if (a1 == a2 && b1 == b2 && c1 == c2)
                                {
                                    ans += cnt1 * (cnt1 - 1) / 2;
                                }
                                else
                                {
                                    ans += cnt1 * cnt2;
                                }
                            }
                        }
                    }
                }
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
        count[a][b][c]--;
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
        count[x][y][z]++;
        int pairs = 0;
        for (int a1 = 0; a1 <= 2; a1++)
        {
            for (int b1 = 0; b1 <= 1; b1++)
            {
                for (int c1 = 0; c1 <= 1; c1++)
                {
                    for (int a2 = 0; a2 <= 2; a2++)
                    {
                        for (int b2 = 0; b2 <= 1; b2++)
                        {
                            for (int c2 = 0; c2 <= 1; c2++)
                            {
                                int e3 = a1 + a2, e5 = b1 + b2, e11 = c1 + c2;
                                if (e3 >= 2 && e5 >= 1 && e11 >= 1)
                                {
                                    int cnt1 = count[a1][b1][c1];
                                    int cnt2 = count[a2][b2][c2];

                                    if (a1 == a2 && b1 == b2 && c1 == c2)
                                    {
                                        pairs += cnt1 * (cnt1 - 1) / 2;
                                    }
                                    else
                                    {
                                        pairs += cnt1 * cnt2;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        ans = max(ans, pairs / 2);
        count[a][b][c]++;
        count[x][y][z]--;
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