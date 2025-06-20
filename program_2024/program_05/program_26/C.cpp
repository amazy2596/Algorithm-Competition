#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        int idx = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != '0')
            {
                idx = i;
                break;
            }
        }
        intt ans = 1;
        for (int i = idx; i > 0; i--)
            ans += (9 - (s[i] - '0'));
        cout << (idx == 0 || n == 1 ? 0 : ans) << "\n";
    }
    return 0;
}