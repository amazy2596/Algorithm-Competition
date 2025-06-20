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
        int x;
        cin >> x;
        int ans = 0, cur = 0;
        for (int i = 1; i < x; i++)
            if (__gcd(x, i) + i >= cur)
                ans = i, cur = __gcd(x, i) + i;
        cout << ans << "\n";
    }
    return 0;
}