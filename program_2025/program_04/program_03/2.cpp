#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e7 + 5;
vector<int> minp(N), prime;
void sieve()
{
    for (int i = 2; i < N; i++)
    {
        if (minp[i] == 0)
        {
            prime.push_back(i);
            minp[i] = i;
        }
        
        for (auto p : prime)
        {
            if (i * p >= N)
                break;
            minp[i * p] = p;
            if (minp[i] == p)
                break;
        }
    }
}

void solve()
{
    int ans = 0;
    // cout << prime.size() << "\n";    
    for (int p : prime)
    {
        for (int q : prime)
        {
            if (p == q)
                continue;
            int cur = p * p * q * q;
            if (cur >= 2333)
            {
                if (cur <= 23333333333333)
                    ans++;
                else 
                    break;
            }
        }
    }

    cout << ans / 2 << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    sieve();
    // cin >> T;
    while (T--)
        solve();
    return 0;
}