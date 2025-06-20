#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<string> g = {"  yy", "  yy", "oobbrr", "oobbrr", "  ww", "  ww", "  gg", "  gg"};

    auto print = [&]()
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < (i == 2 || i == 3 ? 6 : 4); j++)
                cout << g[i][j];
            cout << "\n";
        }

    };
    
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            char ch;
            cin >> ch;
            if (ch == 'L')
            {
                char back = g[7][2];
                for (int i = 7; i - 2 >= 0; i--)
                    g[i][2] = g[i - 2][2];
                g[0][2] = g[1][2] = back;
            }
            else 
            {
                char pre = g[0][3];
                for (int i = 0; i + 2 <= 7; i++)
                    g[i][3] = g[i + 2][3];
                g[6][3] = g[7][3] = pre;
            }
        }
        else 
            print();
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