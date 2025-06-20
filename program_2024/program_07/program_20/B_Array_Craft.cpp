#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n + 1);
        for (int i = 1; i <= x; i++)
        {
            if (i < y && (y - 1) % 2 == 1)
                a[i] = (i % 2 == 1 ? -1 : 1);
            else if (i < y && (y - 1) % 2 == 0)
                a[i] = (i % 2 == 1 ? 1 : -1);
            else if (i <= x)
                a[i] = 1;
        }
        for (int i = n, k = 1; i > x; i--, k++)
            if ((n - x) % 2 == 1)
                a[i] = (k % 2 == 1 ? -1 : 1);
            else    
                a[i] = (k % 2 == 1 ? 1 : -1);
        vector<int> prefixsum(n + 1), suffixsum(n + 2);
        for (int i = 1; i <= n; i++)
            prefixsum[i] = prefixsum[i - 1] + a[i];
        for (int i = n; i >= 1; i--)
            suffixsum[i] = suffixsum[i + 1] + a[i];
        for (int i = 1; i <= n; i++)
            cout << a[i] << " \n"[i == n];
    }
    return 0;
}