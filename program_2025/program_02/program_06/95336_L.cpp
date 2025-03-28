#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int mod = 1e9 + 7;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector pre_a(32, vector<int>(n + 1)), pre_b(32, vector<int>(n + 1)), s_all0(32, vector<int>(n + 1)), s_all1(32, vector<int>(n + 1)), idx(32, vector<int>(n + 1));
    for (int k = 0; k < 32; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            pre_a[k][i] = pre_a[k][i - 1] + (a[i] >> k & 1);
            pre_b[k][i] = pre_b[k][i - 1] + (b[i] >> k & 1);
            if ((b[i] >> k & 1) == 0)
            {
                s_all0[k][i] = s_all0[k][i - 1] + pre_a[k][i];
                s_all1[k][i] = s_all1[k][i - 1];
            }
            else
            {
                s_all0[k][i] = s_all0[k][i - 1];
                s_all1[k][i] = s_all1[k][i - 1] + pre_a[k][i];
                idx[k][i] = idx[k][i - 1] + (i + 1);
            } 

        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        int len = r - l + 1;
        for (int k = 0; k < 32; k++)
        {
            int part1 = s_all0[k][r] - s_all0[k][l - 1] - (s_all1[k][r] - s_all1[k][l - 1]);
            int b1 = pre_b[k][r] - pre_b[k][l - 1];

            

            int part3 = idx[k][r] - idx[k][l - 1] - l * b1;

        }

        cout << ans << "\n";
    }
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