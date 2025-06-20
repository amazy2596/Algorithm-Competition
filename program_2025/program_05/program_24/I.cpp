#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

const int N = 1e6 + 5;
int pre[N][65];

void init()
{
    for (int i = 1; i <= 1e6; i++)
    {
        pre[i][0] = 1;
        for (int j = 1; j <= 64; j++)
        {
            pre[i][j] = pre[i][j - 1] * i;
            if (pre[i][j] > 1e18){
                pre[i][0] = j;
                break;
            }
                // break;
        }
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;

    for (int a = 1; a <= 1e6; a++)
    {
        int x = pre[a][k];

        int l = 1, r = a;
        int y;
        while (l < r)
        {
            int b = l + r >> 1;
            y = pre[b][k];
            
            if (y >= x - n)
                r = b;
            else 
                l = b + 1;
        }

        if (x - n == y)
            ans++;
    }

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}