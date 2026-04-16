// Problem: L1-2 不行，还不能笑（憋笑.jpg）
// URL: https://ac.nowcoder.com/acm/contest/130247/B
// Author: amazy
// Date: 2026-03-14 14:01:32

// Problem: L1-1 胜利宣誓
// URL: https://ac.nowcoder.com/acm/contest/130247/A
// Author: amazy
// Date: 2026-03-14 14:00:07

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n;
    cin >> n;
    int x, y, z;
    cin >> x >> y >> z;
    cout << min(n * y, z - x) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}