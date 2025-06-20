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
    int n, x;
    cin >> n >> x;
    if (x == 0)
    {
        if (n == 1)
            cout << "-1\n";
        else if (n % 2 == 0)
            cout << n << "\n";
        else 
            cout << n - 2 + 5 << "\n";
        return;
    }
    else if (x == 1)
    {
        if (n % 2 == 0)
            cout << n - 2 + 5 << "\n";
        else 
            cout << n << "\n";
        return;
    }

    int ans = 0, cnt = 0;
    for (int k = 31; k >= 1; k--)
    {
        if ((x >> k) & 1 == 1)
            ans += 1 << k, cnt++;
    }

    for (int i = min(cnt, n); i >= 0; i--)
    {
        if ((n - i) % 2 == x % 2)
        {
            ans += n - i;
            break;
        }
    }

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