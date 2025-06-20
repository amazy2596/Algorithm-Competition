#include <bits/stdc++.h>
using intt = long long;
using namespace std;

void solve()
{
    intt n, x;
    cin >> n >> x;
    intt ans = 0;
    for (intt a = 1; a <= x; a++)
    {
        for (intt b = 1; b <= min(n / a, x); b++)
        {
            intt l = 1, r = x - a - b;
            if (r <= 0)
                break;
            while (l < r)
            {
                int mid = (l + r + 1) >> 1;
                if (a * b + a * mid + b * mid <= n)
                    l = mid;
                else 
                    r = mid - 1;
            }
            if (a * b + a * l + b * l <= n)
                ans += l;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}