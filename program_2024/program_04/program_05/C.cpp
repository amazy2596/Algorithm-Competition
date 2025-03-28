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
        string s = to_string(n);
        int idx = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '0')
            {
                idx = i;
                break;
            }
        if (idx != 0)
        {
            string ans = "1";
            for (int i = idx + 1; i < s.length(); i++)
            {
                if (s[i] == '0')
                    ans += "1";
                else 
                    ans += "0";
            }
            cout << ans << "\n";
        }
        else 
        {
            int num = n % 10;
            if (num == 1)
                cout << 2 << "\n";
            else    
                cout << 1 << "\n";
        }
    }
    return 0;
}