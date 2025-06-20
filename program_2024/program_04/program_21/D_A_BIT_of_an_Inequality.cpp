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
        int n;
        cin >> n;
        vector<int> a(n + 1), prefixxor(n + 1);
        vector<vector<int>> bit(n + 1, vector<int>(35, 0));
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            prefixxor[i] = prefixxor[i - 1] ^ a[i];
            for (int j = 0; j <= 32; j++)
            {
                bit[i][j] = bit[i - 1][j];
                bit[i][j] += prefixxor[i] >> j & 1;
            }
        }
        intt ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int h;
            for (h = 32; h >= 0; h--)
                if (a[i] >> h & 1)
                    break;
            intt l1 = bit[i - 1][h], l0 = i - l1;
            intt r1 = bit[n][h] - l1, r0 = n - i - r1 + 1;
            ans += l1 * r1 + l0 * r0;
        }
        cout << ans << endl;
    }
    return 0;
}