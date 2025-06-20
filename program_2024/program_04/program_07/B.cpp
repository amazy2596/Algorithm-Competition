#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt n, k, sum = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] %= k;
        sum += a[i];
    }
    sort(a.begin(), a.end());
    int t = sum % k, ans = 0, num = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (num < t)
        {
            ans++;
            num += a[i];
        }
        else 
            break;
    }
    cout << ans;
    return 0;
}