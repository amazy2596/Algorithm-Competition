#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int N = 1e5 + 5;
vector<int> minp(N), primes;

void sieve()
{
    for (int i = 2; i < N; i++)
    {
        if (minp[i] == 0)
        {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes)
        {
            if (i * p >= N)
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), num(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        map<int, int> mp;
        mp[1]++;
        int temp = a[i];
        while (temp != 1)
        {
            mp[minp[temp]]++;
            mp[temp]++;
            temp /= minp[temp];
        }
        num[i] = mp.size();
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        intt ans = 0;
        for (int i = l; i <= r; i++)
            for (int j = i + 1; j <= r; j++)
                if (num[i] == num[j])
                    ans++;
        cout << ans << "\n";
    }
    return 0;
}