#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    int n;
    cin >> n;
    vector<map<string, int>> mp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        string s;
        for (int j = 0; j < m; j++)
        {
            cin >> s;
            mp[i][s]++;
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        for (int i = 1; i <= n; i++)
        {
            if (mp[i].find(s) != mp[i].end())
            {
                cout << i << " ";
            }
        }

        cout << "\n";
    }
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