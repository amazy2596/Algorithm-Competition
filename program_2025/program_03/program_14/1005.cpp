#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k % 2 == 1)
    {
        cout << "0\n";
        return;
    }

    int p = k / 2;

    if (n <= p)
    {
        cout << "0\n";
        return;
    }

    int cnt = (n - p - 1) / k;
    cout << (cnt + 1) * n - p * (cnt + 1) * (cnt + 1) << "\n";

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