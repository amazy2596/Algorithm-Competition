#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct node
{
    int dist, l, r;
    bool operator<(node o)
    {
        return dist < o.dist;
    }
};

void solve()
{
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    s = " " + s;

    int cnt = 0, idx;
    vector<node> all;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
        {
            vis[i] = 1;
            if (cnt == 0)
                idx = i;
            cnt++;
            for (int j = i + 1; j <= n; j++)
            {
                if (s[j] == '1')
                {
                    all.push_back({j - i - 1, i, j});
                    break;
                }
            }
        }
    }

    if (cnt == 0)
    {
        cout << n << "\n";
        return;
    }

    int ans = 0;
    if (cnt == 1)
    {
        if (idx != n)
            vis[idx + 1] = 1;        
        else 
            vis[idx - 1] = 1;

        for (int k = 1; k <= n; k++)
        {
            if (s[k] == '1')
            {
                int l = (k - 2 + n) % n + 1;
                int r = k % n + 1;
                for (int time = 0; time < t; time++)
                {
                    if (!vis[l])
                    {
                        vis[l] = 1;
                        l = (l - 2 + n) % n + 1;
                    }
                    else 
                        break;
                }

                for (int time = 0; time < t; time++)
                {
                    if (!vis[r])
                    {
                        vis[r] = 1;
                        r = r % n + 1;
                    }
                    else 
                        break;
                }
            }
        }
    }
    else if (cnt > 1)
    {
        int first = 1, last = n;
        while (first <= n && s[first] == '0')
            first++;
        while (last >= 1 && s[last] == '0')
            last--;

        all.push_back({first - 1 + n - last, first, last});
        if (cnt == 2)
            all.push_back({last - first - 1, first, last});
        sort(all.rbegin(), all.rend());
        auto [dist, i, j] = all[0];

        if (j - i - 1 == dist)
            vis[i + 1] = 1;
        else if (i - 1 + n - j == dist)
        {
            if (i != 1)
                vis[i - 1] = 1;
            else if (j != n)
                vis[j + 1] = 1;
        }
        for (int k = 1; k <= n; k++)
        {
            if (s[k] == '1')
            {
                int l = (k - 2 + n) % n + 1;
                int r = k % n + 1;
                for (int time = 0; time < t; time++)
                {
                    if (!vis[l])
                    {
                        vis[l] = 1;
                        l = (l - 2 + n) % n + 1;
                    }
                    else 
                        break;
                }

                for (int time = 0; time < t; time++)
                {
                    if (!vis[r])
                    {
                        vis[r] = 1;
                        r = r % n + 1;
                    }
                    else 
                        break;
                }
            }
        }
        
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            ans++;
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