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
        intt a, b;
        cin >> a >> b;
        intt ans = 0;
        for (int i = 1; i <= b; i++)
            ans += 1ll * ((a / i) + 1) / i;
        cout << ans - 1 << "\n";
    }
    return 0;
}