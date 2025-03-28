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
        int n;
        cin >> n; 
        vector<int> a(n), b(n + 1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n + 1; i++)
            cin >> b[i];
        intt ans = 1;
        bool ok = 0;
        for (int i = 0; i < n; i++)
        {
            ans += abs(a[i] - b[i]);
            if ((a[i] >= b[n] && b[i] <= b[n]) || (a[i] <= b[n] && b[i] >= b[n]))
                ok = 1;
        }
        if (ok)
        {
            cout << ans << "\n";
        }
        else 
        {
            int cnt = INT32_MAX;
            for (int i = 0; i < n; i++)
                cnt = min(cnt, abs(a[i] - b[n]));
            for (int i = 0; i < n; i++)
                cnt = min(cnt, abs(b[i] - b[n]));
            ans += cnt;
            cout << ans << "\n";
        }
    }
    return 0;
}