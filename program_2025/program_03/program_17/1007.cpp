#include <bits/stdc++.h>
#define uint uint64_t
// #define int long long
using namespace std;

const int mod = 1e9 + 7;
int f[105][105][8005], tar[128][8005];
char s[155][155];

void init()
{
    for (int i = 0; i < 128; i++)
        for (int j = 0; j < 8005; j++)
            tar[i][j] = 0;
    for (int i = 0; i < 105; i++)
        for (int j = 0; j < 105; j++)
            for (int k = 0; k < 8005; k++)
                f[i][j][k] = 0;
    for (int i = 0; i < 128; i++)
        for (int j = 0; j < 8005; j++)
            s[i][j] = '\0';
    return;
}

void solve()
{
    init();
    int n, m, k;
    cin >> n >> m >> k;

    auto E = [&](int sum, int mul, int cur)
    {
        return (sum * k + mul) * k + cur;
    };

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> s[i][j];

    s[n][m + 1] = '+';

    for (int sum = 0; sum < k; sum++)
    {
        for (int mul = 0; mul < k; mul++)
        {
            for (int cur = 0; cur < k; cur++)
            {
                int state = E(sum, mul, cur);

                for (char dig = '0'; dig <= '9'; dig++)
                {
                    int nx = (cur * 10 + (dig - '0')) % k;
                    tar[(int)dig][state] = E(sum, mul, nx);
                }

                tar['+'][state] = E((sum + mul * cur) % k, 1ll, 0ll);
                tar['*'][state] = E(sum, (mul * cur) % k, 0ll);
                tar['-'][state] = E((sum + mul * cur) % k, k - 1, 0ll);
            }
        }
    }

    int initState = E(0, 1, (s[1][1] - '0') % k);
    int MxS = k * k * k;
    f[1][1][initState] = 1;

    for (int x = 1; x <= n; x++)
    {
        for (int y = 1 + (x == 1); y <= m + (x == n); y++)
        {
            char ch = s[x][y];
            for (int st = 0; st < MxS; st++)
            {
                if (x > 1 && (isdigit(ch) || isdigit(s[x - 1][y])))
                    f[x][y][tar[ch][st]] = (f[x][y][tar[ch][st]] + f[x - 1][y][st]) % mod;
                
                if (y > 1 && (isdigit(ch) || isdigit(s[x][y - 1])))
                    f[x][y][tar[ch][st]] = (f[x][y][tar[ch][st]] + f[x][y - 1][st]) % mod;
            }
        }
    }

    cout << f[n][m + 1][E(0, 1, 0)] << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}