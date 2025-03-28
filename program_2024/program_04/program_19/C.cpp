#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0, x1 = n / 2 + 1, y1 = m / 2 + 1;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        if (abs(x - x1) + abs(y - y1) <= max(n / 2, m / 2))
            ans++;
    }
    cout << ans;
    return 0;
}