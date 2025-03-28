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
        if ((a + b + c) % 2 == 1)
            cout << -1 << "\n";
        else if (a + b <= c)
            cout << a + b << "\n";
        else 
        {
            int ans = c;
            for (int i = 1; i <= c; i++)
            {
                int p1 = a, p2 = b;
                p1 -= i;
                p2 -= (c - i);
                ans = max(ans, c + min(p1, p2));
            }
            cout << ans << "\n";
        }
    }
    return 0;
}