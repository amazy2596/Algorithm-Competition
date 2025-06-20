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
        int n;
        cin >> n;
        int ans = 0, temp = 0;
        for (int i = 2; i <= n; i++)
        {
            int cur = 0;
            for (int k = 1; k <= n; k++)
            {
                if (k * i <= n)
                    cur += k * i;
                else 
                    break;
            }
            if (cur > temp)
            {
                ans = max(ans, i);
                temp = cur;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}