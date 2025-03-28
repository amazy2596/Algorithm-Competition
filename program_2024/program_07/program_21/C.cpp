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
    map<int, int> mp;
    vector<int> a(n);
    int ans = n;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
            t++;
        else 
        {
            mp[a[i]]++;
            if (mp[a[i]] == 2)
            {
                mp.erase(a[i]);
                ans -= 2;
            }
        }
    }
    int mn = min(int (mp.size()), t);
    ans -= mn * 2;
    t -= mn;
    ans -= t / 2 * 2;
    cout << ans;
    return 0;
}