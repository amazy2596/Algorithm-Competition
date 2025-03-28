#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    priority_queue<pair<int, int>> q;
    for (int i = 1; i < n; i += 2)
    {
        int cur = abs(a[i - 1] - a[i]);
        q.push({cur, i});
    }
    int sum = 0;
    while (sum < k && !q.empty())
    {
        auto top = q.top();
        if (sum + top.first > k)
        {
            a[top.second] += k - sum;
            sum += k - sum;
        }
        else 
        {
            sum += top.first;
            a[top.second] += top.first;
        }
        q.pop();
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (i % 2 == 1)
            ans -= a[i];
        else 
            ans += a[i];
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