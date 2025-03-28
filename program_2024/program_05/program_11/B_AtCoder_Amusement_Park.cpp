#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int ans = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (count + a[i] <= k)
            count += a[i];
        else 
        {
            count = 0;
            count += a[i];
            ans++;
        }
    }
    if (count)
        ans++;
    cout << ans << "\n";
    return 0;
}