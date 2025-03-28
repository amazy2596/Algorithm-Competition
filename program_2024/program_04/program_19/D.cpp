#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    intt ans = 0;
    intt cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            ans = (ans + cnt + 1) % mod;
            cnt = (cnt * 2) % mod;
        }
        else 
        {
            if ((s[i] - '0') % 2 == 0)
                ans = (ans + cnt + 1) % mod;
            cnt = (cnt * 2 + 1) % mod;
        } 
    }
    cout << ans;
    return 0;
}