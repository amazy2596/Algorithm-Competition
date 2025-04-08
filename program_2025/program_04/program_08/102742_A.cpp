#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    array<int, 3> v;
    for (int i = 0; i < 3; i++)
        cin >> v[i];
    int cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        int a;
        cin >> a;
        bool f = 0;
        for (int j = 0; j < 3; j++)
            f |= (a > v[j]);

        cnt += f;
    }

    cout << (cnt >= 2 ? "Yes\n" : "No\n");
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