#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<int> a(t);
    map<int, pair<int, int>> mp;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int key = n * (i - 1) + j;
            mp[key] = {i, j};
        }
    vector<int> row(n + 1), col(n + 1); 
    int other_1 = 0, other_2 = 0;
    bool f = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> a[i];
        if (mp.find(a[i]) != mp.end())
        {
            int x = mp[a[i]].first, y = mp[a[i]].second;
            row[x]++, col[y]++;
            if (row[x] == n)
            {
                cout << i + 1;
                f = 1;
                break;
            }
            if (col[y] == n)
            {
                cout << i + 1;
                f = 1;
                break;
            }
            if (x == y)
            {
                other_1++;
                if (other_1 == n)
                {
                    cout << i + 1;
                    f = 1;
                    break;
                }
            }
            if (y == abs(n - x + 1))
            {
                other_2++;
                if (other_2 == n)
                {
                    cout << i + 1;
                    f = 1;
                    break;
                }
            }
        }
    }
    if (!f)
        cout << -1;
    return 0;
}