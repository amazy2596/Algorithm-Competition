#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt x;
    cin >> x;
    intt ans = 1e18;
    for (int i = 1; i <= 1e7; i++)
    {
        intt k = 1ll * i * i;
        if (abs(x - k) % 2 == 0)
            ans = min(ans, abs(x - k) / 2);
    }
    cout << ans << "\n";
    return 0;
}