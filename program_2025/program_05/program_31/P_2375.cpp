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
const int mod = 1e9 + 7;


void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    uint ans = 1;
    vector<int> pi(n), dp(n + 1);
    for (int i = 1, j = 0; i < n; i++)
    {
        while (j && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;

        dp[i] = dp[pi[i - 1]] + 1;
    }

    for (int i = 1, j = 0; i < n; i++)
    {
        while (j && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
            
        int half = (i + 1) / 2;
        while (j && j > half)
            j = pi[j - 1];
        ans = (ans * (dp[j] + 1)) % mod;
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