#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6;
vector<int> minp(N), prime;

void sieve()
{
    for (int i = 2; i <= N; i++)
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
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    for (int i = 0; i < prime.size(); i++)
    {
        if (mp.find(prime[i]) == mp.end())
        {
            cout << prime[i] << "\n";
            return;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    sieve();
    while (T--)
        solve();
    return 0;
}