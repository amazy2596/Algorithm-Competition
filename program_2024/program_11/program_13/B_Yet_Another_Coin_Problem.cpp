#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ans = 1e9;
    for (int one = 0; one < 3; one++)
    {
        for (int three = 0; three < 2; three++)
        {
            for (int six = 0; six < 5; six++)
            {
                for (int ten = 0; ten < 4; ten++)
                {
                    int sum = one * 1 + three * 3 + six * 6 + ten * 10;
                    if (sum <= n && (n - sum) % 15 == 0)
                    {
                        ans = min(ans, one + three + six + ten + (n - sum) / 15);
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}