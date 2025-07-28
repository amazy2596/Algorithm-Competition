#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct LinearSieve 
{
    int n;
    vector<int> minp;
    vector<int> primes;
    vector<int> phi;
    vector<int> mu;

    LinearSieve(int n = 2e6 + 5, bool enable_phi = false, bool enable_mu = false)
    {
        minp.resize(n + 1);
        if (enable_phi) phi.resize(n + 1);
        if (enable_mu) mu.resize(n + 1);
        
        for (int i = 2; i <= n; i++) 
        {
            if (minp[i] == 0) 
            {
                minp[i] = i;
                primes.push_back(i);

                if (enable_phi) phi[i] = i - 1;
                if (enable_mu) mu[i] = -1;
            }
            for (int p : primes) 
            {
                if (1LL * i * p >= n || p > minp[i])
                    break;

                minp[i * p] = p;
                
                if (p == minp[i])
                {
                    if (enable_phi) phi[i * p] = 1LL * p * phi[i];
                    if (enable_mu) mu[i * p] = 0;
                    break;
                }
                else 
                {
                    if (enable_phi) phi[i * p] = 1LL * (p - 1) * phi[i];
                    if (enable_mu) mu[i * p] = -mu[i];
                }
            }
        }

        if (enable_phi) phi[1] = 1;
        if (enable_mu) mu[1] = 1;
    }

    vector<pair<int, int>> factorize(int x) 
    {
        vector<pair<int, int>> facts;

        if (x <= n)
        {
            while (x > 1)
            {
                int p = minp[x];
                int count = 0;
                while (x % p == 0)
                {
                    x /= p;
                    count++;
                }
                facts.push_back({p, count});
            }

            return facts;
        }

        for (int p : primes) 
        {
            if (1LL * p * p > x) break;

            if (x % p == 0) 
            {
                int count = 0;
                while (x % p == 0) 
                {
                    x /= p;
                    count++;
                }
                facts.push_back({p, count});
            }
        }

        if (x > 1) facts.push_back({x, 1});

        return facts;
    }

    bool is_prime(int x) 
    {
        if (x < 2 || x > n) return false;
        return minp[x] == x;
    }
} LS(2e6 + 5, false, true);

// 单点修改 + 区间查询 + 第k小值
struct Fenwick
{
    int n;
    vector<int> a;

    Fenwick(int _n) : n(_n), a(_n + 1) {}

    int lowbit(int x)
    {
        return x & -x;
    }

    void update(int x, int k)
    {
        while (x >= 1 && x <= n)
        {
            a[x] += k;
            x += lowbit(x);
        }
    }

    int pre(int r)
    {
        int res = 0;   

        while (r > 0)
        {
            res += a[r];
            r -= lowbit(r);
        }

        return res;
    }

    int query(int l, int r)
    {
        return pre(r) - pre(l - 1);
    }

    int kth(int k)
    {
        int ans = 0;
        for (int p = log2l(n); p >= 0; p--)
        {
            int step = 1ll << p;
            if (ans + step <= n && a[ans + step] < k)
            {
                k -= a[ans + step];
                ans += step;
            }
        }

        return ans + 1;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    
    int ans = 0;
    Fenwick fw(n);
    for (int i = 1; i <= n; i++)
    {
        if (LS.mu[i] == 0)
            continue;
        int g = 0;
        vector<int> tmp;
        for (int k = 1; k * i <= n; k++)
        {
            int p = pos[k * i];
            g += fw.query(p + 1, n);
            fw.update(p, 1);
            tmp.push_back(p);
        }

        for (auto p : tmp)
            fw.update(p, -1);

        ans += LS.mu[i] * g;
    }

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}