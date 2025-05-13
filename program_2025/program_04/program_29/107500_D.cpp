#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto check = [&](int x) -> bool
    {
        int res = 0;
        int cur = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            string s = to_string(a[i]);
            for (int j = 0; j < s.length(); j++)
            {
                if (s[j] == '5')
                    cur += cnt;
                else if (s[j] == '2')
                    cnt++;
            }

            if (cur > x)
            {
                res++;
                cur = 0;
                cnt = 0;
                i--;
            }

            if (i == n - 1)
                res++;
        }

        return res <= k;
    };

    int l = 0, r = 1e18l;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else 
            l = mid + 1;
    }

    cout << l << "\n";
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