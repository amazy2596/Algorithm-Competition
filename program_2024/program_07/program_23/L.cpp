#include <bits/stdc++.h>
using intt = long long;
using namespace std;

void solve()
{
    string s[9];
    for (int i = 0; i < 9; i++)
        cin >> s[i];
    int x, y;
    for (int i = 1; i < 8; i++)
    {
        for (int j = 1; j < 8; j++)
        {
            if (s[i][j] == '8')
            {
                x = i, y = j;
                break;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            if (i == x && j == y)
                cout << s[i][j];
            else 
                cout << "*";
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    solve();
    return 0;
}