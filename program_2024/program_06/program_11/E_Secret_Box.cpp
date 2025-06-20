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
        intt x, y, z, s;
        cin >> x >> y >> z >> s;
        intt ans = 0;
        for (intt i = 1; i <= x; i++)
            for (intt j = 1; j <= y; j++)
            {
                if ((s * 1.0 / i / j) == (s / i / j))
                {
                    intt k = s / i / j;
                    ans = max(ans, (x - i + 1) * (y - j + 1) * (z - k + 1));
                }
            }
        cout << ans << "\n";
    }
    return 0;
}