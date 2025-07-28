    #include <bits/stdc++.h>
    #define uint uint64_t
    #define int long long
    using namespace std;

    const double eps = 1e-12;
    const int inf = 1e18;

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



    void solve()
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, inf));
        for (int i = 1; i <= m; i++)
        {
            int u, v, c;
            cin >> u >> v >> c;
            dp[u][v] = min(dp[u][v], c);
            dp[v][u] = min(dp[v][u], c);
        }
        for (int i = 1; i <= n; i++)
            dp[i][i] = 0;

        int p, t;
        cin >> p >> t;
        vector<int> airports;
        for (int i = 0; i < p; i++)
        {
            int x;
            cin >> x;
            airports.push_back(x);
        }

        for (int k = 1; k <= n; k++)
        {
            for (int u = 1; u <= n; u++)
            {
                for (int v = 1; v <= n; v++)
                {
                    dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);
                }
            }
        }

        int q;
        cin >> q;
        while (q--)
        {
            int op;
            cin >> op;

            if (op == 1)
            {
                int x, y, c;
                cin >> x >> y >> c;

                if (c < dp[x][y])
                {
                    dp[x][y] = min(dp[x][y], c);
                    dp[y][x] = min(dp[y][x], c);

                    for (int u = 1; u <= n; u++)
                    {
                        for (int v = 1; v <= n; v++)
                        {
                            dp[u][v] = min(dp[u][v], dp[u][x] + c + dp[y][v]);
                            dp[u][v] = min(dp[u][v], dp[u][y] + c + dp[x][v]);
                        }
                    }
                }
            }
            else if (op == 2)
            {
                int x;
                cin >> x;
                airports.push_back(x);
            }
            else 
            {
                vector<int> dist(n + 1, inf);
                for (int u = 1; u <= n; u++) 
                {
                    for (int airport : airports) 
                    {
                        dist[u] = min(dist[u], dp[u][airport]);
                    }
                }
                
                int ans = 0;
                for (int u = 1; u <= n; u++) 
                {
                    for (int v = 1; v <= n; v++) 
                    {
                        int road_path = dp[u][v];

                        int airport_path = inf;
                        if (dist[u] != inf && dist[v] != inf)
                            airport_path = dist[u] + t + dist[v];
                        
                        int final_dist = min(road_path, airport_path);
                        
                        if (final_dist != inf)
                            ans += final_dist;
                    }
                }
                cout << ans << "\n";
            }
        }
    }

    signed main()
    {
        ios::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--)
            solve();
        return 0;
    }