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
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = max(pre[i - 1], a[i - 1]);
    }

    for (int i = n; i >= 1; i--)
        suf[i] = suf[i + 1] + a[i];

    for (int k = 1; k <= n; k++)
    {
        int pos = n - k + 1;
        if (pre[pos] > a[pos])
            cout << suf[pos] - a[pos] + pre[pos] << " ";
        else 
            cout << suf[pos] << " ";
    }

    cout << "\n";
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