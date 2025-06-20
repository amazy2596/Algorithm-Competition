#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b;
    bool f = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (f && a[i] == 0)
            f = 0, b.push_back(a[i]);
        else if (a[i] != 0)
            b.push_back(a[i]);

        cnt += (a[i] == 0);
    }

    if (f)
    {
        cout << n << "\n";
        return;
    }

    vector<int> pre(n), suf(n);
    for (int i = 0; i < b.size(); i++)
        pre[i] = (i == 0 ? b[i] : min(pre[i - 1], b[i]));
    
    set<int> s;
    int mex = 0;
    for (int i = b.size() - 1; i >= 0; i--)
    {
        s.insert(b[i]);
        while (s.count(mex))
            mex++;
        suf[i] = mex;
    }

    for (int i = 0; i < b.size() - 1; i++)
    {
        if (pre[i] < suf[i + 1])
        {
            cout << n - cnt << "\n";
            return;
        }
    }

    cout << n - cnt + 1 << "\n";
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