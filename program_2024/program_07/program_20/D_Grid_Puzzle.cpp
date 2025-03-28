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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        bool r1 = 0, r2 = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!r1 && !r2)
            {
                if (a[i] == 0)
                    continue;
                ans++;
                if (a[i] <= 2)
                    r1 = 1;
            }
            else if (r1)
            {
                r1 = 0;
                if (a[i] <= 2)
                    continue;
                ans++;
                if (a[i] <= 4)
                    r2 = 1;
            }
            else 
            {
                r2 = 0;
                if (a[i] == 0)
                    continue;
                ans++;
                if (a[i] <= 4)
                    r1 = 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}