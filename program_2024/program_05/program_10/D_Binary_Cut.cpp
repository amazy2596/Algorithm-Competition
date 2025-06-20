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
        string s;
        cin >> s;
        int ans = 0;
        int idx1 = 0, idx2 = 0;
        bool f1 = 0, f2 = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
                f1 = 1;
            if (s[i] == '0')
            {
                idx1 = i;
                break;
            }
            if (i == s.length() - 1)
                idx1 = i + 1;
        }
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '0')
                f2 = 1;
            if (s[i] == '1')
            {
                idx2 = i + 1;
                break;
            }
            if (i == 0)
                idx2 = 1;
        }
        if (f1)
            ans++;  
        if (f2)
            ans++;
        bool f3 = 0;
        for (int i = idx1; i < idx2; i++)
        {
            if (s[i] == '1')
            {
                for (int j = i + 1; j < idx2; j++)
                {
                    if (s[j] == '0')
                    {
                        i = j - 1;
                        break;
                    }
                    if (j == idx2 - 1)
                        i = j;
                }
                if (f3)
                    ans += 2;
                else 
                    ans++;
                f3 = 1;
            }
        }
        cout << (s.length() == 1 ? 1 : ans) << "\n";
    }
    return 0;
}