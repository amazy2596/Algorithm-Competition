#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r)
{ return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

// ** -> 失败
// 红 -> 彩
// 彩 -> 红
// 彩 -> 彩
char last_move[205][205][30][2][2];
int last_from_op[205][205][30][2][2];
bool vis[205][205][30][2][2];

struct state
{
    int a, b, n, p, op;
};

void init()
{
    for (int a = 0; a < 205; a++)
    {
        for (int b = 0; b < 205; b++)
        {
            for (int c = 0; c < 30; c++)
            {
                for (int d = 0; d < 2; d++)
                {
                    for (int e = 0; e < 2; e++)
                    {
                        last_move[a][b][c][d][e] = '#';
                        last_from_op[a][b][c][d][e] = -1;
                        vis[a][b][c][d][e] = 0;
                    }
                }
            }
        }
    }
    
    queue<state> q;
    q.push({0, 0, 21, 0, 0});
    vis[0][0][21][0][0] = 1;

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        if (u.a > 200 || u.b > 200) continue;
        if (u.n == 0) continue;

        auto v = u;
        v.p = 1 - u.p;
        v.op = 0;

        if (!vis[v.a][v.b][v.n][v.p][v.op]) 
        {
            vis[v.a][v.b][v.n][v.p][v.op] = 1;
            last_move[v.a][v.b][v.n][v.p][v.op] = '/';
            last_from_op[v.a][v.b][v.n][v.p][v.op] = u.op;
            q.push(v);
        }

        if (u.op == 0)
        {
            if (u.n > 6)
            {
                auto v = u;
                if (v.p == 0) v.a++;
                else v.b++;
                v.n--;
                v.op = 1;

                if (v.a <= 200 && v.b <= 200 && !vis[v.a][v.b][v.n][v.p][v.op]) 
                {
                    vis[v.a][v.b][v.n][v.p][v.op] = 1;
                    last_move[v.a][v.b][v.n][v.p][v.op] = '1';
                    last_from_op[v.a][v.b][v.n][v.p][v.op] = u.op;
                    q.push(v);
                }
            }
            else 
            {
                int c = 8 - u.n;
                auto v = u;
                if (v.p == 0) v.a += c; 
                else v.b += c;
                v.n -= 1;
                v.op = 0;

                if (v.a <= 200 && v.b <= 200 && !vis[v.a][v.b][v.n][v.p][v.op]) 
                {
                    vis[v.a][v.b][v.n][v.p][v.op] = 1;
                    last_move[v.a][v.b][v.n][v.p][v.op] = char('0' + c);
                    last_from_op[v.a][v.b][v.n][v.p][v.op] = u.op;
                    q.push(v);
                }
            }
        }
        else 
        {
            for (int c = 2; c <= 7; c++)
            {
                auto v = u;
                if (v.p == 0) v.a += c;
                else v.b += c;
                v.op = 0;

                if (v.a <= 200 && v.b <= 200 && !vis[v.a][v.b][v.n][v.p][v.op]) 
                {
                    vis[v.a][v.b][v.n][v.p][v.op] = 1;
                    last_move[v.a][v.b][v.n][v.p][v.op] = char('0' + c);
                    last_from_op[v.a][v.b][v.n][v.p][v.op] = u.op;
                    q.push(v);
                }
            }
        }
    }
}

void solve()
{
    int a, b, n, p;
    cin >> a >> b >> n >> p;

    int tar = -1;
    if (vis[a][b][n][p][0]) tar = 0;
    else if (vis[a][b][n][p][1]) tar = 1;

    if (tar == -1)
    {
        cout << "NA\n";
        return;
    }

    string ans;
    int ca = a, cb = b, cn = n, cp = p, cop = tar;
    while (!(ca == 0 && cb == 0 && cn == 21 && cp == 0 && cop == 0))
    {
        char move = last_move[ca][cb][cn][cp][cop];
        int prev_op = last_from_op[ca][cb][cn][cp][cop];

        ans += move;

        if (move == '/')
        {
            cp = 1 - cp;
            cop = prev_op;
        }
        else 
        {
            int val = move - '0';
            if (cp == 0) ca -= val;
            else cb -= val;
            if (val == 1 || prev_op == 0) cn++;
            cop = prev_op;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}