#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    long double n, k, t;
    cin >> n >> k >> t;
    vector<long double> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long double time = 0, pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (pos >= t)
            break;
        if (pos < a[i])
        {
            a[i] = max(pos,a[i] - time);
            if (i == 0)
            {
                time += a[i] - pos;
                pos += k;
            }
            else if (i == n - 1)
            {
                time += (a[i] - pos) / 2;
                pos = pos + (a[i] - pos) / 2 + k;
            }
            else
            {
                time += (a[i] - pos) / 2;
                pos = pos + (a[i] - pos) / 2 + k;
            }
        }
        else
        {
            a[i] = min(pos, a[i] + time);
            pos = a[i] + k;
            if (pos >= t)
                break;
        }
    }

    if (pos < t)
        time += t - pos;

    cout << (int)(time * 2) << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}