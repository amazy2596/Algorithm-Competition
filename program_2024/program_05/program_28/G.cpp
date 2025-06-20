#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int N = 1e7 + 5;
vector<int> minp(N), primes;

void sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (minp[i] == 0)
        {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes)
        {
            if (i * p > N)
                break;
            minp[i * p] = p;
            if (minp[i] == p)
                break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    sieve();
    int n;
    cin >> n;
    vector<int> ans(N);
    for (int i = 1; i <= N; i++)
        ans[i] = ans[i - 1] + (minp[i] == i);
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        cout << ans[r] - ans[l - 1] << "\n";
    }
    return 0;
}