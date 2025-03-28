#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    while (m--)
    {
        char op;
        int l, r;
        cin >> op >> l >> r;
        if (op == '+' && mx >= l && mx <= r)
            mx++;
        else if (op == '-' && mx >= l && mx <= r)
            mx--;
        cout << mx << " ";
    }
    cout << "\n";
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
