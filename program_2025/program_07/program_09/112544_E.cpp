#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int last = inf, ed = 0;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] < last && a[i] >= i)
            last = a[i];
        else 
        {
            ed = i;
            break;
        }
    }

    set<int> s;
    for (int i = ed; i >= 1; i--)
    {
        if (a[i] != i)
        {
            s.insert(a[i]);
        }
    }

    for (int i = n; i > ed; i--)
    {
        if (s.count(a[i]))
        {
            for (int k = i; k > ed; k--)
            {
                if (a[k] != k)
                {
                    s.insert(a[k]);
                }
            }
            break;
        }
    }

    cout << s.size() << "\n";
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