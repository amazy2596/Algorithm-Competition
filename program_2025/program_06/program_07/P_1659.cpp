#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

const int N = 1e6 + 5;
const int mod = 19930726;
int fact[N], ifact[N], p[N];

int fast_pow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        
        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

vector<vector<int>> matrix_mul(vector<vector<int>> a, vector<vector<int>> b)
{
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
                res[i][j] += a[i][k] * b[k][j], res[i][j] %= mod;
        }
    }
    
    return res;
}

vector<vector<int>> matrix_pow(vector<vector<int>> a, int b)
{
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    while (b)
    {
        if (b & 1)
            res = matrix_mul(res, a);
        a = matrix_mul(a, a);
        b >>= 1;
    }

    return res;
}

void init()
{
    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = (p[i - 1] * 2) % mod;

    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    
    ifact[N - 1] = fast_pow(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--)
        ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
}

int C(int n, int m)
{
    if (n < m)
        return 0;
    return (fact[n] % mod * ifact[m] % mod * ifact[n - m] % mod) % mod;
}

int A(int n, int m)
{
    if (n < m)
        return 0;
    return (fact[n] % mod * ifact[n - m] % mod) % mod;
}

/*
start = (i - p[i]) / 2;
end = (i + p[i]) / 2 - 1 = start + p[i] - 1;
[start, end] 代表原始字符串中以 (i) 或者 (i - 1 和 i) 为中心的回文串
*/
vector<int> manacher(string &t)
{
    string s = "#";
    for (auto c : t)
    {
        s += c;
        s += '#';
    }

    int n = s.length();
    vector<int> p(n);
    int center = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        int mr = 2 * center - i;
        if (i < r)
            p[i] = min(p[mr], r - i);

        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && s[i - p[i] - 1] == s[i + p[i] + 1])
            p[i]++;

        if (i + p[i] - 1 > r)
        {
            center = i;
            r = i + p[i] - 1;
        }
    }

    return p;
}

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    auto p = manacher(s);

    vector<int> b(n + 2);
    for (int i = 0; i < p.size(); i++)
    {
        if (i & 1)
        {
            int l = 1, r = p[i];
            if (r < l)
                continue;
            
            b[l]++, b[r + 1]--;
        }
    }

    vector<int> count(n + 1);
    for (int i = 1; i <= n; i++)
        count[i] = count[i - 1] + b[i];

    int ans = 1;
    for (int i = n; i >= 1; i--)
    {
        if (i % 2 == 0)
            continue;

        if (k >= count[i])
        {
            ans = (ans * fast_pow(i, count[i])) % mod;
            k -= count[i];
        }
        else 
        {
            ans = (ans * fast_pow(i, k)) % mod;
            k = 0;
            break;
        }
    }

    if (k > 0)
    {
        cout << "-1\n";
        return;
    }

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}