#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e6 + 5;
vector<int> minp(N), prime;

void init()
{
    for (int i = 2; i < N; i++)
    {
        if (minp[i] == 0)
        {
            minp[i] = i;
            prime.push_back(i);
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
    
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    init();
    // cin >> T;
    while (T--)
        solve();
    return 0;
}