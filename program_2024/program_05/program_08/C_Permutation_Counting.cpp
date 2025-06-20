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
        intt n, k;
        cin >> n >> k;
        vector<intt> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        intt l = 0, r = 1e12;
        while (l < r)
        {
            intt mid = l + r + 1 >> 1;
            intt need = 0;
            for (int i = 0; i < n; i++)
                if (mid > a[i])
                    need += mid - a[i];
            if (need > k)
                r = mid - 1;
            else 
                l = mid;
        }
        for (int i = 0; i < n; i++)
            if (l > a[i])
                k -= l - a[i], a[i] = l;
        intt ans = 1 + (l - 1) * n + k;
        for (int i = 0; i < n; i++)
            if (a[i] > l)
                ans++;
        cout << ans << endl;
    }
    return 0;
}