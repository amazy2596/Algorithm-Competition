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
        vector<int> a(n + 1);
        vector<vector<int>> prefixor(n + 1, vector<int>(24, 0));
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            for (int j = 0; j <= 20; j++)
                prefixor[i][j] = prefixor[i - 1][j] + ((a[i] >> j) & 1);
        }
        int l = 1, r = n + 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            bool check = 1;
            vector<int> cur_or = prefixor[mid];
            for (int i = mid; i <= n; i++)
            {
                for (int j = 0; j <= 20; j++)
                {
                    if ((cur_or[j] == 0 && prefixor[i][j] - prefixor[i - mid][j] != 0) || (cur_or[j] != 0 && prefixor[i][j] - prefixor[i - mid][j] == 0))
                    {
                        check = 0;
                        break;
                    }
                }
                if (!check)
                    break;
            }
            if (check)
                r = mid;
            else 
                l = mid + 1;
        }
        cout << l << "\n";
    }
    return 0;
}