#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int m;
    cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    int n;
    cin >> n;
    vector<int> b(n);
    map<int, int> mp, exist;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        for (int j = 0; j < m; j++)
        {
            if (exist.find(a[j]) == exist.end())
            {
                if (mp.find(a[j] - b[i]) != mp.end())
                {
                    ans++;
                    mp.erase(a[j] - b[i]);
                    exist[a[j]]++;
                    break;
                }
            }
        }
        mp[b[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if ()
    }
    return 0;
}