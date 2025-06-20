#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];

    vector<int> l(sum + 1, -1), r(sum + 1, -1);
    int tot = 1, idx = 1;
    queue<int> q, p;
    q.push(tot);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        if (idx < n && a[idx] > 0)
            l[node] = ++tot, p.push(tot), a[idx]--;
        if (idx < n && a[idx] > 0)
            r[node] = ++tot, p.push(tot), a[idx]--;

        if (q.empty())
        {
            q = p;
            p = queue<int>();
            idx++;
        }
    }

    cout << "1\n";
    for (int i = 1; i <= tot; i++)
        cout << l[i] << " " << r[i] << "\n";
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