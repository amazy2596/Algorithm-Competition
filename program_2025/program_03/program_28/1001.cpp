#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, u, k, hq;
    cin >> n >> u >> k >> hq;
    vector<int> hurt(n), ehq(n);
    multiset<int> s;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
    for (int i = 0; i < n; i++)
    {
        cin >> hurt[i] >> ehq[i];
        s.insert(hurt[i]);
        q.push({ehq[i], hurt[i], i});
    }

    int ans = 0;
    vector<int> vis(n);
    while (!q.empty())
    {
        auto [__, _, idx] = q.top();
        q.pop();

        if (vis[idx] < k)
        {
            if (vis[idx] == 0)
                ehq[idx] -= u;
            else 
                ehq[idx] -= u / 2;
            vis[idx]++;
        }

        if (ehq[idx] <= 0)
            s.extract(hurt[idx]), ans++;
        else 
            q.push({ehq[idx], hurt[idx], idx});

        if (!s.empty())
            hq -= *s.rbegin();
        
        if (hq <= 0)
        {
            cout << ans << "\n";
            return;
        }
    }

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