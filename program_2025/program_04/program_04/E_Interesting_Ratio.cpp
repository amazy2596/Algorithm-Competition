#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e7 + 5;
vector<int> minp(N), prime;

void init()
{
    prime.push_back(0);
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
    int n;
    cin >> n;

    int ans = 0;
    for (int a = 1; a * 2 <= n; a++)
    {
        int l = 0, r = prime.size() - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (prime[mid] * a > n)
                r = mid - 1;
            else 
                l = mid;
        }

        ans += l;
    }

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    init();
    cin >> T;
    while (T--)
        solve();
    return 0;
}