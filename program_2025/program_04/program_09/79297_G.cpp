#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    priority_queue<int> q, p;
    for (int i = 0; i < n; i++)
    {
        while (q.size() && q.top() > a[i])
            q.pop();
        b[i] += q.size();
        q.push(a[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (p.size() && p.top() > a[i])
            p.pop();
        b[i] += p.size();
        p.push(a[i]);
    }

    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
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