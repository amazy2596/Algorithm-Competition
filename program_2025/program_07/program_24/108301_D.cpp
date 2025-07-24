#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int x;
    cin >> x;

    int siz = 64;
    vector<vector<int>> a(siz + 1, vector<int>(siz + 1));
    a[1][1] = x;

    for (int i = 2; i <= siz; i++)
        a[i][i] = 1;

    auto print = [&]()
    {
        for (int i = 1; i <= siz; i++)
        {
            for (int j = 1; j <= siz; j++)
            {
                if (a[i][j] != -1)
                    cout << " " << a[i][j] << " ";
                else 
                    cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    };

    int big = 0;
    while (a[1][1] != 1)
    {
        for (int j = 2; j <= siz; j++)
        {
            // print();
            a[1][j] = a[1][1] / 2;

            for (int k = 1; k < j; k++)
            {
                for (int i = 1; i <= siz; i++)
                {
                    a[i][k] -= a[i][j];
                }
            }
            big = j + 1;

            if (a[1][1] == 1)
                break;
        }
    }

    int j = 1;
    for (int i = big; i <= siz && j < big; i++)
    {
        // print();
        for (int k = j + 1; k < big; k++)
            a[k][i]++;

        // print();
        for (int k = 1; k <= siz; k++)
            a[k][j] += a[k][i];

        j++;
    }

    cout << siz << "\n";
    for (int i = 1; i <= siz; i++)
    {
        for (int j = 1; j <= siz; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}