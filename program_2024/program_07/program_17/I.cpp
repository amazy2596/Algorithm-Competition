#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<intt> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    intt cur = a[1] * a[1];
    int ans = 0;
    for (int i = n, k = 1; i > 1 && k <= t; i--, k++)
    {
        if (a[i] * a[i] > cur)
            ans = k, cur = a[i] * a[i];
    }
    cout << ans << "\n";
    return 0;
}