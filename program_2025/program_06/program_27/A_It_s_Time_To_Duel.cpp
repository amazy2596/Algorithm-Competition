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
    int n;
    cin >> n;
    vector<int> a(n + 2), cnt(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i] == 0)
        {
            if (cnt[i] > 0)
            {
                cout << "YES\n";
                return;
            }
            else 
                cnt[i + 1]++;
        }
        else if (a[i] == 1)
        {
            if (cnt[i] == 0)
                cnt[i]++;
            else 
            {
                if (a[i + 1] == 0)
                    cnt[i]++;
                else if (a[i + 1] == 1)
                    cnt[i + 1]++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if ((a[i] == 0 && cnt[i] > 0) || (a[i] == 1 && cnt[i] == 0))
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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