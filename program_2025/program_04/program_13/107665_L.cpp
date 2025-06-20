#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

auto isPrime = [](int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)            
            return false;
    }

    return true;
};

bool isLucky(long long n) 
{
    if (n <= 1) 
        return false;
    int maxE = floor(log(n) / log(2));

    for (int e = 2; e <= maxE; e++) 
    {
        if(!isPrime(e + 1)) 
            continue;
        double p_d = pow(n, 1.0 / e);
        long long p = (long long)(p_d + 1e-9);

        if (pow(p, e) == n || pow(p+1, e) == n) 
        {
            if (pow(p, e) != n)
                p = p + 1;
            if (isPrime(p))
                return true;
        }
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (isLucky(x))
            ans += x;
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