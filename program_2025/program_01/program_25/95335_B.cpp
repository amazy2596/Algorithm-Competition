#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e5 + 5;
vector<int> minp(N), prime(N);

void sieve()
{
    for (int i = 2; i < N; i++)
    {
        if (minp[i] == 0)
        {
            minp[i] = i;
            prime[i] = 1;
        }

        for (auto p : prime)
        {
            if (i * p >= N)
                break;
            minp[i] = p;
            if (minp[i] == p)
                break;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int sum = 0, idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (prime[a[i] + a[(i + 1) % n]] == 1)
        {
            sum++;
            idx = i;
        }
    }

    if (sum != 1)
    {
        cout << "No\n";
        return;
    }

    vector<int> ans;
    
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