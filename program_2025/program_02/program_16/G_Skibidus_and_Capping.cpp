#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 2e5 + 5;
vector<int> minp(N), prime;
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
            if (i * p > N)
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
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int sum = 0, ans = 0;
    sort(a.begin(), a.end());
    vector<int> cnt(n + 1);
    for (auto x : a)
    {
        int p = minp[x];
        if (p == x)
        {
            ans += sum - cnt[x];
            sum++;
            cnt[x]++;
        }
        else 
        {
            int q = minp[x / p];
            if (x != p * q)
                continue;
            
            ans++;
            if (p == q)
            {
                ans += cnt[x];
                ans += cnt[p];
            }
            else 
            {
                ans += cnt[x];
                ans += cnt[p];
                ans += cnt[q];
            }
            cnt[x]++;
        }
    }

    cout << ans << "\n";
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