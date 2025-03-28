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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        if (n == 1 && m == 1)
            cout << -1 << "\n";
        else 
        {
            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < m; j++)
                    cout << a[i][j] << " ";
                cout << a[i][0] << " \n";
            }
            for (int j = 1; j < m; j++)
                cout << a[0][j] << " ";
            cout << a[0][0] << " \n";
        }
    }
    return 0;
}