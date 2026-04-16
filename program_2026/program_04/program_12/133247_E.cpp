// Problem: 其实你吃鹅翅膀时，它也在肘击你
// URL: https://ac.nowcoder.com/acm/contest/133247/E
// Author: amazy
// Date: 2026-04-12 16:39:16

#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    // cout << (1LL << 63) - 1 << "\n";
    i64 l, r;
    cin >> l >> r;
    int ans = 0;
    if (l == 0)
    {
        for (int y = 62; y >= 0; y--)
        {
            i64 base = 1LL << y;        
            if (base <= r)
            {
                l = base;
                ans++;
                break;
            }
        }
    }
    while (l != r)
    {
        ans++;
        for (int y = 62; y >= 0; y--)
        {
            i64 base = 1LL << y;
            if (l % base == 0)
            {
                i64 x = l / base;
                if ((__int128_t)(x + 1) * base <= r)
                {
                    l = (x + 1) * base;
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}