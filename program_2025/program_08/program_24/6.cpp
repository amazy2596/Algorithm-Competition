#include<bits/stdc++.h> 
using namespace std;
using i64 = long long;

void solve()
{
    int n, d;
    cin >> n >> d;
    int base = 1;
    int rem = n - d;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, -1));
    int beg = 0;
    for (int i = 1; i <= n;)
    {
        int num = beg;
        int j = 1;
        while (j <= base + rem)
        {
            g[i][j] = num;
            j++;
        }

        num = (num + 1) % d;
        while (j <= n)
        {
            for (int k = 0; k < base; k++)
                g[i][j] = num, j++;
            num = (num + 1) % d;
        }

        if (i == 1)
            i += base + rem;
        else 
            i += base;
        beg = (beg + 1) % d;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j] == -1)
                g[i][j] = g[i - 1][j];
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
}

int main( )
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}