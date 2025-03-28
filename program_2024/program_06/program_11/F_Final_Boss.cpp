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
        intt h, n;
        cin >> h >> n;
        vector<intt> a(n), c(n);
        map<intt, intt> mp;
        intt sum = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i], sum += a[i];
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            mp[c[i]] += a[i];
        }
        intt l = 0, r = 1e14;
        while (l < r)
        {
            intt mid = (r - l) / 2 + l;
            intt cur = 0;
            bool f = 0;
            for (auto [key, value] : mp)
            {
                cur += ceill(mid * 1.0 / key) * value;
                if (h - cur <= 0)
                {
                    f = 1;
                    break;
                }
            }
            if (f)
                r = mid;
            else 
                l = mid + 1;
        }
        cout << l << "\n";
    }
    return 0;
}