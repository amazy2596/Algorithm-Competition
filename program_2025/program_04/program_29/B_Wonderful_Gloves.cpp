#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> l(n + 1), r(n + 1), preL(n + 1), preR(n + 1), sufL(n + 2), sufR(n + 2), max();
    for (int i = 1; i <= n; i++)
        cin >> l[i];
    for (int i = 1; i <= n; i++)
        cin >> r[i];

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());


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