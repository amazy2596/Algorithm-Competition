#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> minp(n + 1), prime;
    for (int i = 2; i <= n; i++)
    {
        if (minp[i] == 0)
        {
            minp[i] = i;
            prime.push_back(i);
        }
        for (auto &p : prime)
        {
            if (i * p > n) break;
            minp[i * p] = p;
            if (minp[i] == p) break;
        }
    }

    auto isp = [&](int x) 
    {
        return minp[x] == x;
    };

    int ans = 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            if (!isp(i)) ans += i;
        }
    }
    cout << ans + 1 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}