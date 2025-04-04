#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    auto get = [&](int x)
    {
        int sum = m, can = 0, cur = x;
        if (sum >= cur)
        {
            can += cur;
            sum -= cur;
            can += sum / (cur + 1) * cur;
            sum -= sum / (cur + 1) * (cur + 1);
        }
        else 
            return can;

        cur = sum - 1;

        while (sum > cur && cur > 0)
        {
            if (sum >= cur)
            {
                can += sum / (cur + 1) * cur;
                sum -= sum / (cur + 1) * (cur + 1);
            }
            cur = sum - 1;
        }
        
        can *= n;

        return can;
    };

    int l = 1, r = m;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        int temp = get(mid);
        if (temp >= k)
            r = mid - 1;
        else 
            l = mid;
    }

    while (get(l) < k)
        l++;

    cout << l << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}