#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int len = to_string(n).size();

    int a = n / 10 + n % 10;
    int b = n % (int)(pow(10, len - 1)) + n / (int)(pow(10, len - 1));

    cout << max(a, b) << "\n";
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