#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int idx = 1, beg = 1;
    while (idx + ceill((n - beg + 1) * 1.0l / (beg << 1)) <= k)
    {
        idx += ceill((n - beg + 1) * 1.0l / (beg << 1));
        beg <<= 1;
    }
    cout << beg + (beg * 2) * (k - idx) << "\n";
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