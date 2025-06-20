#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    // function f(k, a, l, r):   
        // ans := 0   
        // for i from l to r (inclusive):      
        // while k is divisible by a[i]:         
            // k := k/a[i]      
            // ans := ans + k   
        // return ans

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    while (q--)
    {
        int k, l, r;
        cin >> k >> l >> r;
        int ans = 0;
        for (int i = l; i <= r; i++)
        {
            while (k % a[i] == 0)
                k = k / a[i];
                
            ans = ans + k;
        }
        cout << ans << "\n";
    }
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