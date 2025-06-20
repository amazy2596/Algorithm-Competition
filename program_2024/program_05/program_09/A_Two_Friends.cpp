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
        vector<int> a(n + 1);
        map<int, int> mp;
        bool f = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            mp[i] = a[i];
            if (mp.find(a[i]) != mp.end())
            {
                if (a[i] == mp[i] && mp[a[i]] == i)
                    f = 1;
            }
        }
        cout << (f ? 2 : 3) << "\n";
    }
    return 0;
}