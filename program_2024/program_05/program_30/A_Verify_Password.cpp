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
        string s;
        cin >> n >> s;
        bool ok1 = 0;
        for (int i = 0; i < n; i++)
            if ((s[i] < 'a' && s[i] > 'z') || (s[i] < '0' && s[i] > '9'))
            {
                ok1 = 1;
                break;
            }
        if (ok1)
        {
            cout << "NO\n";
            continue;
        }
        int idx = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                idx = i - 1;
                break;
            }
        }
        bool ok2 = 0;
        for (int i = 0; i < idx; i++)
        {
            if (s[i] > s[i + 1])
            {
                ok2 = 1;
                break;
            }
        }
        if (ok2)
        {
            cout << "NO\n";
            continue;
        }
        bool ok3 = 0;
        for (int i = idx + 1; i < n; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                ok3 = 1;
                break;
            }
        }
        if (ok3)
        {
            cout << "NO\n";
            continue;
        }
        bool ok4 = 0;
        for (int i = idx + 1; i < n - 1; i++)
        {
            if (s[i] > s[i + 1])
            {
                ok4 = 1;
                break;
            }
        }
        if (ok4)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}
