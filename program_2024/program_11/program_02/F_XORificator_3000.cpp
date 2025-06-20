#include <bits/stdc++.h>
#define int long long
using namespace std;

// int XOR(int n, int i, int k)
// {
//     int64_t f = n >> i;
//     if ((f << i) + k > n)
//         f--;
//     if (f % 4 == 0)
//         return ((f << i) + k);
//     if (f % 4 == 1)
//         return ((f << i) + k) ^ ((f - 1 << i) + k);
//     if (f % 4 == 2)
//         return ((f << i) + k) ^ ((f - 1 << i) + k) ^ ((f - 2 << i) + k);
//     if (f % 4 == 3)
//         return ((f << i) + k) ^ ((f - 1 << i) + k) ^ ((f - 2 << i) + k) ^ ((f - 3 << i) + k);
// }

int64_t XOR(int64_t i, int64_t k, int64_t r) {
  int64_t ans = 0, cool = r >> i;
  if ((cool << i) + k > r) cool--;
  if (cool % 4 == 0) {
    return ((cool << i) + k);
  } else if (cool % 4 == 1) {
    return ((cool << i) + k) ^ ((cool - 1 << i) + k);
  } else if (cool % 4 == 2) {
    return ((cool << i) + k) ^ ((cool - 1 << i) + k) ^ ((cool - 2 << i) + k);
  } else {
    return ((cool << i) + k) ^ ((cool - 1 << i) + k) ^ ((cool - 2 << i) + k) ^ ((cool - 3 << i) + k);
  }
}

int XOR(int l, int r, int i, int k)
{
    return XOR(i, k, r) ^ XOR(i, k, l - 1);
}

void solve()
{
    int l, r, i, k;
    cin >> l >> r >> i >> k;
    int ans = XOR(l, r, 0, 0) ^ XOR(l, r, i, k);
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