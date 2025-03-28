#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
vector<int> a(N), pre(N + 1);

void solve()
{
    int l, r;
    cin >> l >> r;
    cout << pre[r] - pre[l - 1] + a[l] << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    for (int i = 1; i <= N; i++)
    {
        int cur = i;
        while (cur)
        {
            cur /= 3;
            a[i]++;
        }
        pre[i] = pre[i - 1] + a[i];
    }
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}