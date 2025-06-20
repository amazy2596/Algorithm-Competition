#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, m, p, x;
    cin >> n >> m >> p >> x;
    intt ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i * j < x && j <= m; j++)
        {
            int temp = x - i * j;
            if (temp % (i + j) == 0)
            {
                int cnt = temp / (i + j);
                if (cnt % 2 == 0)
                {
                    ans += (cnt <= 2 * p);
                }
            }
        }
    }
    cout << ans;
    return 0;
}