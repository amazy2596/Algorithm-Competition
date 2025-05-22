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
    vector<int> a;
    a.push_back(-inf);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (a.back() != x)
            a.push_back(x);
    }
    a.push_back(-inf);

    int ans = 0;
    for (int i = 1; i < a.size() - 1; i++)
        ans += (a[i - 1] < a[i] && a[i] > a[i + 1]);
    cout << ans << "\n";
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