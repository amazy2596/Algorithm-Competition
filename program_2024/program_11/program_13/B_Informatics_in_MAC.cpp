#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1), suf(n + 2);
    set<int> s;
    int mex = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
        while (s.count(mex))
            mex++;
        pre[i] = mex;
    }
    s.clear();
    mex = 0;
    for (int i = n; i >= 1; i--)
    {
        s.insert(a[i]);
        while (s.count(mex))
            mex++;
        suf[i] = mex;
    }
    for (int i = 1; i < n; i++)
    {
        int x = pre[i], y = suf[i + 1];
        if (x == y)
        {
            cout << 2 << "\n";
            cout << 1 << " " << i << "\n";
            cout << i + 1 << " " << n << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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