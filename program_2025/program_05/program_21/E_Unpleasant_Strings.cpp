#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;

    vector nxt(n + 1, vector<int>(k, -1));
    vector<int> position(k, -1);
    for (int i = n; i >= 0; i--)
    {
        nxt[i] = position;
        if (i != 0)
            position[s[i] - 'a'] = i;
    }

    vector dp(n + 1, vector<int>(k, inf));
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j < k; j++)
        {
            if (nxt[i][j] == -1)
            {
                dp[i][j] = min(dp[i][j], 1ll);
                continue;
            }

            int mn = *min_element(dp[nxt[i][j]].begin(), dp[nxt[i][j]].end());
            dp[i][j] = min(dp[i][j], mn + 1);
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        string t;
        cin >> t;
        t = " " + t;

        int pos = 0, i = 1;
        while (i < t.length())
        {
            pos = nxt[pos][t[i] - 'a'];

            if (pos == -1)
                break;

            i++;
        }

        if (pos != -1)
            cout << *min_element(dp[pos].begin(), dp[pos].end()) << "\n";
        else 
            cout << "0\n";
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