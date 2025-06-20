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
        int n, k;
        cin >> n >> k;
        if (n == 1)
            cout << 0 << "\n";
        else 
        {
            int cur = 1;
            int ans = 0;
            while (cur < n)
            {
                cur--;
                cur += k;
                ans++;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}