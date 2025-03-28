#include <bits/stdc++.h>
using intt = long long;
using namespace std;

void solve()
{
    const int mod = 1e9 + 7;
    string s;
    cin >> s;
    int n = s.length();
    s = " " + s;
    unordered_map<intt, intt> idx;
    idx[0] = 1;
    intt sum = 0;
    intt ans = 0;
    for (int r = 1; r <= n; r++)
    {
        sum += s[r] == '1';
        sum -= s[r] == '0';
        if (idx.find(sum) == idx.end())
            idx[sum] += r + 1;
        else 
        {
            // for (int i = 0; i < idx[sum].size(); i++)
            // {
                // int l = idx[sum][i];
                // ans = (ans + (l * (n - r + 1) % mod)) % mod;
            // }
            // idx[sum].push_back(r + 1);
            intt l = idx[sum];
            ans = (ans + (l * (n - r + 1) % mod)) % mod;
            idx[sum] += r + 1;
        }
    }
    cout << ans % mod << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}