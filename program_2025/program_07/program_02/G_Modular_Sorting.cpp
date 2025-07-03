#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    auto get = [&](int g)
    {
        int cnt = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            if ((a[i] % g) > (a[i + 1] % g))
                cnt++;
        }

        return cnt;
    };

    map<int, int> mp;
    for (int i = 1; i * i <= m; i++)
    {
        if (m % i == 0)
        {
            mp[i] = get(i);
            mp[m / i] = get(m / i);
        }
    }

    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int i, x;
            cin >> i >> x;
            
            for (auto &[g, val] : mp)
            {
                if (i >= 2 && a[i - 1] % g > a[i] % g)
                    val--;
                if (i <= n - 1 && a[i] % g > a[i + 1] % g)
                    val--;

                if (i >= 2 && a[i - 1] % g > x % g)
                    val++;
                if (i <= n - 1 && x % g > a[i + 1] % g)
                    val++;
            }

            a[i] = x;

        }
        else if (op == 2)
        {
            int k;
            cin >> k;

            int g = __gcd(k, m);
            // int cnt = 0;
            // for (int i = 1; i <= n - 1; i++)
            // {
                // if ((a[i] % g) > (a[i + 1] % g))
                    // cnt++;
            // }

            cout << (a[n] % g + mp[g] * g < m ? "YES\n" : "NO\n");
        }
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}