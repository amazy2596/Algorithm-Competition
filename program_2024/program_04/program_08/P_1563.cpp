#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, string>> id(n);
    for (int i = 0; i < n; i++)
        cin >> id[i].first >> id[i].second;
    int ans = 0;
    while (m--)
    {
        int a, s;
        cin >> a >> s;
        if (id[ans].first == 0)
        {
            if (a == 0)
                ans = ((ans + n - s) % n);
            else 
                ans = ((ans + n + s) % n);
        }
        else 
        {
            if (a == 0)
                ans = ((ans + n + s) % n);
            else 
                ans = ((ans + n - s) % n);
        }
        ans %= n;
    }
    cout << id[ans].second;
    return 0;
}