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
    intt ans = 0;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i].first = ++x, a[i].second = ++y;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].first % 2 == a[i].second % 2)
            {
                if (a[j].first % 2 == a[j].second % 2)
                {
                    
                }
            }
        }
    }
    return 0;
}