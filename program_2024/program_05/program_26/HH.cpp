#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    string a, b, c;
    cin >> a >> b >> c;
    map<char, char> mp;
    for (int i = 0; i < b.length(); i++)
        mp[b[i]] = a[i];
    bool f = 1;
    string ans;
    for (int i = 0; i < c.length(); i++)
    {
        if (mp.find(c[i]) != mp.end())
            ans += mp[c[i]];
        else 
        {
            f = 0;
            break;
        }
    }
    if (f)
        cout << ans;
    else 
        cout << -1;
    return 0;
}