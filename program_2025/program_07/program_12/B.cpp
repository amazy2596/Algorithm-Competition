#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> r(n), c(n);
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> r[i] >> c[i];
        sum += c[i];
        cnt += (r[i] == 1);
    }

    cout << (cnt >= ceil(n * 1.0 / 2) ? 1 : 0) << " " << (sum >= s + 50 ? 1 : 0) << "\n";
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