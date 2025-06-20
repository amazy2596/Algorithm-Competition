#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    auto get_sum = [&](int start, int d, int t)
    {
        return t * start - (t * (t - 1) / 2) * d;
    };

    auto get_num = [&](int start, int d, int t, int x) -> int
    {
        if (x > start)
            return 0;
        return max(start - x, start - (t - 1) * d) / d + 1;
    };

    auto count = [&](int x)
    {
        int res = 0;
        int i = 1;
        while (i <= n && k > 0)
        {
            int v = n / i;
            int ed = n / v;
            int cnt = ed - i + 1;
            int start = n - i * v;
            res += get_num(start, v, cnt, x);

            i = ed + 1;
        }

        return res;  
    };

    int l = 0, r = n;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        int temp = count(mid);
        if (temp >= k)
            l = mid;
        else 
            r = mid - 1;
    }

    int ans = 0;
    int i = 1;
    int num = 0;
    while (i <= n && k > 0)
    {
        int v = n / i;
        int ed = n / v;
        int cnt = ed - i + 1;
        int start = n - i * v;

        cnt = get_num(start, v, cnt, l);

        // 1 2 3 4 5 6 7 8 9 10 11 12 13 14
        // 0 0 2 2 4 2 0 6 5 4  3  2  1  0
        if (cnt >= k)
        {
            ans += get_sum(start, v, k);
            k = 0;
            break;
        }
        else 
        {
            ans += get_sum(start, v, cnt);
            if (start - (cnt - 1) * v == l)
            {
                ans -= l;
                cnt--;
                num++;
            }
            k -= cnt;
            i = ed + 1;
        }

        if (i >= n)
        {
            ans += min(k, num) * l;
            k = 0;
            break;
        }
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