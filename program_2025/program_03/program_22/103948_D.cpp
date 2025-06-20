#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt_0 = 0, cnt_1 = 0;
    bool f1 = 0, f2 = 0, f3 = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        cnt_0 += s[i] == '0';
        cnt_1 += s[i] == '1';
        if (cnt_0 % 2 == 1 && cnt_1 % 2 == 1)
        {
            ans += f1;
            f1 = 1;
        }
        else if (cnt_0 % 2 == 1)
        {
            ans += f2;
            f2 = 1;
        }
        else if (cnt_1 % 2 == 1)
        {
            ans += f3;
            f3 = 1;
        }
    }

    cout << fixed << setprecision(6) << ans * 1.0 / n << "\n";
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