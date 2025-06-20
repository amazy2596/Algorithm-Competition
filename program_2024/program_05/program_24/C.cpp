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
    vector<intt> a(n + 2), prefixsum(n + 2), suffixsum(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefixsum[i] = prefixsum[i - 1] + a[i]; 
    }
    for (int i = n; i >= 1; i--)
        suffixsum[i] = suffixsum[i + 1] + a[i];
    intt ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max({ans, (prefixsum[i - 1] - a[i]), (suffixsum[i + 1] - a[i])});
    cout << ans;
    return 0;
}