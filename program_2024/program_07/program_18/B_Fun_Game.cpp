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
        string s, t;
        cin >> s >> t;
        if (s == t)
            cout << "YES\n";
        else 
        {
            if (s[0] == '1')
                cout << "YES\n";
            else 
            {
                bool f = 1;
                for (int i = 0; i < n; i++)
                {
                    if (s[i] == '1' || i == n - 1)
                    {
                        for (int j = i; j >= 0; j--)
                        {
                            if (s[j] == '0' && t[j] == '1')
                            {
                                f = 0;
                                break;
                            }
                        } 
                        break;
                    }
                }
                cout << (f ? "YES\n" : "NO\n");
            }
        }
    }
    return 0;
}