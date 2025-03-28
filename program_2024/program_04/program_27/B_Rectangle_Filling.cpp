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
        if (n == 1 || m == 1)
        {
            vector<char> ch(max(n, m));
            int w = 0, b = 0;
            for (int i = 0; i < max(n, m); i++)
            {
                cin >> ch[i];
                if (ch[i] == 'W')
                    w++;
                else 
                    b++;
            }
            if (w != 0 && b != 0)
            {
                if (ch[0] != ch[max(n, m) - 1])
                    cout << "NO\n";
                else 
                    cout << "YES\n";
            }
            else 
                cout << "YES\n";
        }
        else 
        {
            vector<bool> b(3), w(3);
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    char ch;
                    cin >> ch;
                    if (i == 1)           
                    {
                        if (ch == 'B')
                            b[0] = 1;
                        else 
                            w[0] = 1;
                    }
                    if (i == n)
                    {
                        if (ch == 'B')
                            b[1] = 1;
                        else 
                            w[1] = 1;
                    }
                    if (j == 1)
                    {
                        if (ch == 'B')
                            b[2] = 1;
                        else 
                            w[2] = 1;
                    }
                    if (j == m)
                    {
                        if (ch == 'B')
                            b[3] = 1;
                        else 
                            w[3] = 1;
                    }
                }
            }
            bool okb = 1, okw = 1;
            for (int i = 0; i < 4; i++)
            {
                if (!b[i])
                    okb = 0;
                if (!w[i])
                    okw = 0;
            }
            if (okb || okw)
                cout << "YES\n";
            else 
                cout << "NO\n";
        }
    }
    return 0;
}