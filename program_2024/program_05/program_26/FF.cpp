#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int x, a, b;
    cin >> x >> a >> b;
    int ans = 1e9;
    for (int i = 0; i < 1005; i++)
    {
        for (int j = 0; j < 1005; j++)
        {
            if (x >= i * a + j * b)
                ans = min(ans, x - i * a - j * b);
        }
    }
    cout << ans;
    return 0;
}