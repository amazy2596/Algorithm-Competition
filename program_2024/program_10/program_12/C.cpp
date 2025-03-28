#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4;

void solve()
{
    int n, target, sum = 0;
    cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int dis = target - sum;
    if (dis > 0)
    {
        priority_queue<int> q;
        for (int i = 0; i < n; i++)
            q.push(N - a[i]);
        int ans = 0;
        while (!q.empty())
        {
            ans++;
            auto top = q.top();
            q.pop();
            if (top >= dis)
                break;
            dis -= top;
        }
        cout << ans << "\n";
    }
    else if (dis < 0)
    {
        dis = -dis;
        priority_queue<int> q;
        for (int i = 0; i < n; i++)
            q.push(N + a[i]);
        int ans = 0;
        while (!q.empty())
        {
            ans++;
            auto top = q.top();
            q.pop();
            if (top >= dis)
                break;
            dis -= top;
        }
        cout << ans << "\n";
    }
    else 
        cout << 0 << "\n";
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