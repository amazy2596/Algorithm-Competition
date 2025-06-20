#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    // int n;
    // cin >> n;
    for (int n = 2; n <= 10; n += 2)
    {
        vector<int> a(n + 1);
        iota(a.begin(), a.end(), 0);
        // for (int i = 1; i <= n; i++)
            // cin >> a[i];

        vector<int> b(n + 1);
        iota(b.begin(), b.end(), 0);
        int ans = 0;
        do
        {
            int temp = 0;
            for (int i = 1; i <= n; i++)
                temp += (a[i] ^ b[i]);
            ans = max(ans, temp);
        } while (next_permutation(b.begin() + 1, b.end()));

        cout << ans << "\n";
        iota(b.begin(), b.end(), 0);
        do
        {
            int temp = 0;
            for (int i = 1; i <= n; i++)
                temp += (a[i] ^ b[i]);
            if (ans == temp)
            {
                for (int i = 1; i <= n; i++)
                    cout << b[i] << " ";
                cout << "\n";
            }
        } while (next_permutation(b.begin() + 1, b.end()));
    }
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