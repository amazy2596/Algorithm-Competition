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
        intt ans = 0, num = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
                num++;
            else if (num != 0)
                ans += num + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}