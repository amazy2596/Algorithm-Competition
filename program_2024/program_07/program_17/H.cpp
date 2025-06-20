#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    intt ans = 0, cur = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], ans += a[i], cur += a[i];
    for (int i = 0; i < n; i++)
        ans = max({ans, cur - a[i] + a[i] * n, cur + n});
    cout << ans << "\n";
    return 0;
}