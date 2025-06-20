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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    vector<int> pre(m + 1), suf(m + 1);
    int j = 1, ok = 1;
    for (int i = 1; i <= m; i++)
    {
        pre[i] = j - 1;
        while (j <= n && a[j] < b[i])
            j++;
        if (j > n && i <= m)
            ok = 0;
        j++;
    }

    if (ok)
    {
        cout << "0\n";
        return;
    }

    j = n;
    for (int i = m; i >= 1; i--)
    {
        suf[i] = j + 1;
        while (j > 0 && a[j] < b[i])
            j--;
        j--;
    }

    int ans = INT32_MAX;
    for (int i = 1; i <= m; i++)
    {
        int l = pre[i], r = suf[i];
        if (l >= r)
            continue;
        
        ans = min(ans, b[i]);
    }

    cout << (ans == INT32_MAX ? -1 : ans) << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}