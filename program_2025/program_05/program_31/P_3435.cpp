#include <bits/stdc++.h>
#define uint uint64_t
// #define int long long
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
    string s;
    cin >> s;
    vector<int> pi(n);
    int len = 0;
    for (int i = 1; i < n; i++)
    {
        while (len && s[len] != s[i])
            len = pi[len - 1];
        if (s[len] == s[i])
            len++;
        pi[i] = len;
    }

    int maxLog = 20;
    vector up(n + 1, vector<int>(maxLog, 0));
    for (int i = 1; i <= n; i++)
    {
        up[i][0] = pi[i - 1];
        for (int j = 1; j < maxLog; j++)
            up[i][j] = up[up[i][j - 1]][j - 1];
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int half = (i + 1) / 2;
        int r = pi[i];

        if (r == 0)
            continue;
        
        for (int j = maxLog - 1; j >= 0; j--)
        {
            if (up[r][j] != 0)
                r = up[r][j];
        }

        if (r <= half)
            ans += i + 1 - r;
    }

    cout << ans << "\n";
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