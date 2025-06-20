#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    const int mod = 1e8;
    int n;
    cin >> n;
    vector<intt> a(n);
    intt ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += (n - 1) * a[i];
    }
    sort(a.begin(), a.end());
    intt cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i + 1, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (a[i] + a[mid] >= mod)
                r = mid;
            else 
                l = mid + 1;
        }
        cnt += n - l;
    }
    ans -= mod * cnt;
    cout << ans << "\n";
    return 0;
}