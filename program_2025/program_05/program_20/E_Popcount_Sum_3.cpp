#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;
const int mod = 998244353;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

struct node
{
    int cnt, sum;
};

void solve()
{
    int n, k;
    cin >> n >> k;
    int N = 70;
    vector<int> bits;
    while (n)
    {
        bits.push_back(n & 1);
        n >>= 1;
    }
    if(bits.empty()) 
        bits.push_back(0);
    reverse(bits.begin(), bits.end());
    int L = bits.size();

    vector<vector<vector<node>>> dp(L + 1, vector<vector<node>>(k + 2, vector<node>(2, node(0, 0))));
    dp[0][0][1] = node(1, 0);
    for (int i = 0; i < L; i++)
    {
        int bit = bits[i];
        for (int j = 0; j <= k; j++)
        {
            for (int t = 0; t <= 1; t++)
            {
                if (dp[i][j][t].cnt == 0)
                    continue;

                for (int b = 0; b <= 1; b++)
                {
                    if (t == 1 && b > bit)
                        break;

                    int nt = ((t == 1) && (b == bit) ? 1 : 0);
                    int nj = j + b;

                    dp[i + 1][nj][nt].cnt = (dp[i + 1][nj][nt].cnt + dp[i][j][t].cnt) % mod;

                    int add = dp[i][j][t].sum % mod;
                    if (b == 1)
                        add = (add + (1ll << (L - i - 1)) * dp[i][j][t].cnt) % mod;

                    dp[i + 1][nj][nt].sum = (dp[i + 1][nj][nt].sum + add) % mod;
                }
            }
        }
    }

    // for (int i = 0; i < L; i++)
    // {
    //     for (int j = 0; j <= k; j++)
    //     {
    //         cout << dp[i][j][0].cnt + dp[i][j][1].cnt << " ";
    //     }
    //     cout << "\n";
    // }

    int ans = (dp[L][k][0].sum + dp[L][k][1].sum) % mod;
    cout << ans % mod << "\n";
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