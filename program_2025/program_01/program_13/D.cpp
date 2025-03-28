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
    int sum = 0, a = 0, b = 0;
    int l = 0, r = 0;
    while (r < n)
    {
        while (r < n && sum < k)
        {
            if (s[r] == '1')
                b++, sum += a;
            else if (s[r] == '0')
                a++;

            r++;
        }

        if (sum == k)
        {
            cout << l + 1 << " " << r << "\n";
            return;
        }

        while (sum > k)
        {
            if (s[l] == '1')
                b--;
            else if (s[l]== '0')
                a--, sum -= b;

            l++;
        }
    }
    cout << -1;
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