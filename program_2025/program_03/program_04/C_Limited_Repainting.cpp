#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    auto check = [&](int x)
    {
        char ch = 'R';
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > x)
            {
                if (s[i] == 'B' && ch != 'B')
                    cnt++;
                ch = s[i];
            }
        }

        return cnt <= k;
    };
    
    int l = 0, r = 1e9;
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
    cin >> T;
    while (T--)
        solve();
    return 0;
}