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

/*
start = (i - p[i]) / 2;
end = (i + p[i]) / 2 - 1 = start + p[i] - 1;
[start, end] 代表原始字符串中以 (i) 或者 (i - 1 和 i) 为中心的回文串
*/
vector<int> manacher(string &s)
{
    int n = s.length();
    vector<int> p(n);
    int center = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        int mr = 2 * center - i;
        if (i < r)
            p[i] = min(p[mr], r - i);

        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && s[i - p[i] - 1] == s[i + p[i] + 1])
            p[i]++;

        if (i + p[i] - 1 > r)
        {
            center = i;
            r = i + p[i] - 1;
        }
    }

    return p;
}

void solve()
{
    
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