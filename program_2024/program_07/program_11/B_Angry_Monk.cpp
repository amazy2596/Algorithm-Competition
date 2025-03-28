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
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        int mx = 0;
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        int ans = 0;
        sort(a.begin(), a.end());
        for (int i = 0; i < k - 1; i++)
            ans += a[i] - 1;
        cout << ans + n - mx << "\n";
    }
    return 0;
}