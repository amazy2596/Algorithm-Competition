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
        int ans = 1e9;
        for (int i = 0; i < n - 1; i++)
            ans = min(ans, max(a[i], a[i + 1]));
        cout << ans - 1 << "\n";
    }
    return 0;
}