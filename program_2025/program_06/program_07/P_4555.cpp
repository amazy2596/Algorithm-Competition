#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    string s;
    cin >> s;

    string t = "#";
    for (int i = 0; i < s.length(); i++)
    {
        t.push_back(s[i]);
        t.push_back('#');
    }

    int n = t.length();
    vector<int> p(n);

    int center = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        int mirror = 2 * center - i;

        if (i < r)
            p[i] = min(p[mirror], r - i);

        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1])
            p[i]++;

        if (i + p[i] - 1 > r)
        {
            center = i;
            r = i + p[i] - 1;
        }
    }

    vector<int> L(s.length()), R(s.length());
    for (int i = 0; i < n; i++)
    {
        if (p[i] == 0)
            continue;

        int len = p[i];
        int s = (i - len) / 2;
        int e = s + len - 1;

        L[e] = max(L[e], p[i]);
        R[s] = max(R[s], p[i]);
    }

    for (int i = 1; i < s.length(); i++)
        R[i] = max(R[i], R[i - 1] - 2);
    for (int i = s.length() - 2; i >= 0; i--)
        L[i] = max(L[i], L[i + 1] - 2);

    int ans = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (L[i] && R[i + 1])
            ans = max(ans, L[i] + R[i + 1]);
    }

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}