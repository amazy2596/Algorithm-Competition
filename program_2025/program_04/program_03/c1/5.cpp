#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e5 + 5;
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
    int n;
    cin >> n;
    vector<int> a(n);
    vector cnt(N, vector<int>());
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= sqrtl(a[i]); j++)
        {
            if (a[i] % j == 0)
            {
                int k = a[i] / j;
                if (j == k)
                    cnt[j].push_back(a[i]);
                else 
                {
                    cnt[j].push_back(a[i]);
                    cnt[k].push_back(a[i]);
                }
            }
        }
    }

    for (int i = N - 1; i >= 1; i--)
    {
        if (cnt[i].size() >= 3)
        {
            sort(cnt[i].begin(), cnt[i].end());
            cout << cnt[i][0] << " " << cnt[i][1] << " " << cnt[i][2] << "\n";
            return;
        }
    }
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