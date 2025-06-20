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
    vector<int> a(n), b(n);
    intt cur = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        cur += a[i];
    }
    for (int i = 0; i < n; i++)
        ans = max(ans, cur - a[i] + b[i]);
    cout << ans;
    return 0;
}