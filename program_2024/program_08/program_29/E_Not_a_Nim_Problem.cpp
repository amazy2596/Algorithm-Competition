#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e7 + 10;
vector<int> minp(N), prime, idx(N);

void sieve()
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
    for (int i = 0; i < prime.size(); i++)
        idx[prime[i]] = i + 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a;
    int cnt = 0;
    auto get = [&](int x) -> int
    {
        if (x == 1)
            return 1;
        x = minp[x];
        if (x % 2 == 0)
            return 0;
        return idx[x];
    };
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt ^= get(x);
    }
    if (cnt == 0)
        cout << "Bob\n";
    else 
        cout << "Alice\n";
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