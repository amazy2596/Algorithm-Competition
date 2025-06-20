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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int tar = (n + 1) / 2 - 1, mn1 = 0, mn2 = 0, mx1 = 0, mx2 = 0;
    for (int i = 1; i < n; i++)
    {
        mn1 += (a[i] < a[0] && -a[i] < a[0] ? 1 : 0);
        mx1 += (a[i] < a[0] || -a[i] < a[0] ? 1 : 0);
    }
    for (int i = 1; i < n; i++)
    {
        mn2 += (a[i] < -a[0] && -a[i] < -a[0] ? 1 : 0);
        mx2 += (a[i] < -a[0] || -a[i] < -a[0] ? 1 : 0);
    }

    if ((tar >= mn1 && tar <= mx1) || (tar >= mn2 && tar <= mx2))
        cout << "YES\n";
    else 
        cout << "NO\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init()
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}