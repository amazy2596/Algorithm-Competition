#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < 26; i++)
    {
        bool ok = 1;
        for (int j = 0; j < n; j++)
        {
            if (s[j].find('a' + i) == -1)
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            cout << char('a' + i) << "\n";
            break;
        }
    }
    return 0;
}