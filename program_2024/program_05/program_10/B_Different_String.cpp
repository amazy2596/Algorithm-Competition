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
        map<char, int> mp;
        int idx = 0;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
            if (s[i] != s[0])
                idx = i;
        }
        if (mp.size() == 1)
            cout << "NO\n";
        else 
        {
            cout << "YES\n";
            swap(s[0], s[idx]);
            cout << s << "\n";
        }
    }
    return 0;
}