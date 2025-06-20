#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 4e18;
int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 4; i < s.length(); i++)
    {
        if (s[i - 4] != s[i - 3] && s[i - 4] == s[i - 2] && s[i - 2] == s[i] && s[i - 3] == s[i - 1])
            ans++;
    }

    cout << ans;
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