#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    unordered_map<int, int> mp_a, mp_b;
    int sum_a = 0, sum_b = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum_a += a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i], sum_b += b[i];
    for (int i = 0; i < n; i++)
        mp_a[sum_a - a[i]]++;
    for (int i = 0; i < m; i++)
        mp_b[sum_b - b[i]]++;
    while (q--)
    {
        int x;
        cin >> x;
        bool f = 0;
        for (int k = 1; k <= sqrt(abs(x)); k++)
        {
            if (abs(x) % k == 0)
            {
                int l = k;
                int r = x / l;
                if (mp_a.find(l) != mp_a.end() && mp_b.find(r) != mp_b.end())
                    f = 1;
                if (mp_a.find(r) != mp_a.end() && mp_b.find(l) != mp_b.end())
                    f = 1;

                l = -k;
                r = x / l;
                if (mp_a.find(l) != mp_a.end() && mp_b.find(r) != mp_b.end())
                    f = 1;
                if (mp_a.find(r) != mp_a.end() && mp_b.find(l) != mp_b.end())
                    f = 1;
            }
        }
        cout << (f ? "YES\n" : "NO\n");
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