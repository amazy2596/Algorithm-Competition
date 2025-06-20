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
        intt n;
        cin >> n;
        intt sum = 0, mx = 0;
        intt ans = 0;
        vector<intt> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
            sum += a[i];
            if (sum - mx == mx)
                ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}