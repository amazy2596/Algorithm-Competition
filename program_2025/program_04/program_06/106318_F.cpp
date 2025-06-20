#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int pos = 0;
    if (a[0] == 0)
    {
        while (pos < n && a[pos] == 0)
            pos++;

        if (pos == n)
        {
            for (int i = 0; i < n; i++)
                a[i] = i + 1;
        }
        else 
        {
            for (int i = pos - 1; i >= 0; i--)
                a[i] = (a[i + 1] == 1 ? 2 : a[i + 1] - 1);
        }
    }

    for (int i = pos; i < n; i++)
    {
        if (a[i] == 0)
        {
            int j = i;
            while (j < n && a[j] == 0)
                j++;

            if (j == n)
                a[i] = (a[i - 1] == 1 ? 2 : a[i - 1] - 1);
            else 
            {
                if (a[i - 1] < a[j])
                    a[i] = a[i - 1] + 1;
                else 
                    a[i] = a[i - 1] - 1;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (abs(a[i - 1] - a[i]) != 1)
        {
            cout << "-1\n";
            return;
        }
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
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