#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    x--;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (i != x)
            mx = max(mx, a[i]);
    for (int i = 0; i < n; i++)
        if (i != x)
            ans += a[i] == mx;
    cout << ans;
    return 0;
}