#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    map<int, int> mp;
    bool f = 1;
    int i = 0, j = 0;
    while (j < m)
    {
        if (i < n)
        {
            if (a[i] == b[j])
                mp[a[i]]++, i++;
            else if (mp.find(b[j]) == mp.end())
            {
                f = 0;
                break;
            }
        }
        else 
        {
            if (mp.find(b[j]) == mp.end())
            {
                f = 0;
                break;
            }
        }
        j++;
    }
    cout << (f ? "YA\n" : "TIDAK\n");
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}