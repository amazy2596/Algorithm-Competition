#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[k - 1])
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
        cout << n - 1 << "\n";
    else if (k - 1 < idx)
        cout << idx - 1 << "\n";
    else
    {
        int x = idx - 1, y = 0;
        for (int i = idx + 1; i < n; i++)
        {
            if (a[i] < a[k - 1])
                y++;
            else 
                break;
        }
        y += (idx != 0);
        cout << max(x, y) << "\n";
    }
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