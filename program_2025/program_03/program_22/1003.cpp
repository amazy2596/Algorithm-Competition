#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    vector w(n, vector<int>(m));
    vector<int> beg(m);
    queue<int> cand;
    vector cnt(m, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>());
    vector<int> dist(n);
    for (int i = 0; i < m; i++)
        cin >> beg[i];
    for (int i = 0; i < n; i++)
    {
        bool ok = 1;
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] > beg[j])
            {
                dist[i]++;
                cnt[j].push({a[i][j], i});
                ok = 0;
            }
        }

        if (ok)
            cand.push(i);
        for (int j = 0; j < m; j++)
            cin >> w[i][j];
    }

    while (!cand.empty())
    {
        auto i = cand.front();
        cand.pop();
        for (int j = 0; j < m; j++)
        {
            beg[j] += w[i][j];

            while (!cnt[j].empty())
            {
                auto [val, idx] = cnt[j].top();
                if (val <= beg[j])
                {
                    cnt[j].pop();
                    dist[idx]--;
                    if (dist[idx] == 0)
                        cand.push(idx);
                }
                else 
                    break;
            }
        }
    }

    bool ok = 1;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] != 0)
        {
            ok = 0;
            break;
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
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