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
        intt n, k, sum = 0;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i], sum += a[i];
        int bg = 0, ed = n - 1, ans = 0;
        if (k >= sum)
            ans = n;
        else 
        {
            while (k > 0 && sum > k)
            {
                int cnt = min(a[bg], a[ed]);
                if (k >= 2 * cnt)
                {
                    a[bg] -= cnt, a[ed] -= cnt;
                    k -= 2 * cnt;
                    if (a[bg] == 0 && a[ed] == 0)
                        ans += 2;
                    else 
                        ans++;
                }
                else if (k > cnt) 
                {
                    k -= cnt;
                    ans++;
                }
                else
                    break;
                bg += a[bg] == 0;
                ed -= a[ed] == 0;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}