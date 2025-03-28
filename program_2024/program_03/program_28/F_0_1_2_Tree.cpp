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
        int a, b, c;
        cin >> a >> b >> c;
        if (c != a + 1)
            cout << -1 << "\n";
        else 
        {
            int ans = 0;
            int sum = 0;
            bool ok = 1;
            for (int i = 1; sum < a; i *= 2)
            {
                sum += i;
                ans++;
            }
            if (b > sum - a)
                ans += ceil((b - sum + a) * 1.0 / ((pow(2, ans - 1) - sum + a) * 2 + sum - a));
            cout << ans << "\n";
        }
    }
    return 0;
}