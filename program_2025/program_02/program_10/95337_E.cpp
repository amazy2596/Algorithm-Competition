#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    vector<string> g(3);
    for (int i = 0; i < 3; i++)
        cin >> g[i];
    
    int cnt = 0;
    vector<pair<int, int>> pos;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cnt += g[i][j] == 'X';
            if (g[i][j] == 'G')
                pos.emplace_back(i, j);
        }
    }

    auto check1 = [&]()
    {
        bool res = 0, ok;
        for (int i = 0; i < 3; i++)
        {
            ok = 1;
            for (int j = 0; j < 3; j++)
            {
                if (g[i][j] != 'X')
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
                res = 1;
        }

        for (int j = 0; j < 3; j++)
        {
            ok = 1;
            for (int i = 0; i < 3; i++)
            {
                if (g[i][j] != 'X')
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
                res = 1;
        }

        ok = 1;
        for (int i = 0; i < 3; i++)
        {
            if (g[i][i] != 'X')
            {
                ok = 0;
                break;
            }
        }
        if (ok)
            res = 1;

        ok = 1;
        int i = 0, j = 2;
        while (i < 3 && j >= 0)
        {
            if (g[i][j] != 'X')
            {
                ok = 0;
                break;
            }
            i++, j--;
        }
        if (ok)
            res = 1;

        return res;
    };

    auto check2 = [&]()
    {
        bool res = 0, ok;
        for (int i = 0; i < 3; i++)
        {
            ok = 1;
            for (int j = 0; j < 3; j++)
            {
                if (g[i][j] != 'O')
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
                res = 1;
        }

        for (int j = 0; j < 3; j++)
        {
            ok = 1;
            for (int i = 0; i < 3; i++)
            {
                if (g[i][j] != 'O')
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
                res = 1;
        }

        ok = 1;
        for (int i = 0; i < 3; i++)
        {
            if (g[i][i] != 'O')
            {
                ok = 0;
                break;
            }
        }
        if (ok)
            res = 1;

        ok = 1;
        int i = 0, j = 2;
        while (i < 3 && j >= 0)
        {
            if (g[i][j] != 'O')
            {
                ok = 0;
                break;
            }
            i++, j--;
        }
        if (ok)
            res = 1;

        return res;
    };

    if (check2())
    {
        cout << "No\n";
        return;
    }
    
    if (cnt <= 2)
    {
        cout << "Yes\n";
        return;
    }
    else if (cnt == 3)
    {
        for (int i = 0; i < pos.size(); i++)
        {
            for (int j = i + 1; j < pos.size(); j++)
            {
                auto [x1, y1] = pos[i];
                auto [x2, y2] = pos[j];

                g[x1][y1] = 'X', g[x2][y2] = 'X';
                if (check1())
                {
                    cout << "Yes\n";
                    return;
                }
                g[x1][y1] = 'O', g[x2][y2] = 'O';
            }
        }
    }
    else if (cnt == 4)
    {
        auto [x1, y1] = pos.back();
        g[x1][y1] = 'X';
        if (check1())
        {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}