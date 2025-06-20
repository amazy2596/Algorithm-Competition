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
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = 1; i < r; i++)
            if (pow(2, i) <= r)
                ans = max(ans, i);
            else 
                break;
        cout << ans << "\n";
    }
    return 0;
}