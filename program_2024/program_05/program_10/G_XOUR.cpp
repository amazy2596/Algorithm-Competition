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
        vector<int> a(n);
        map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i] >> 2].push(a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            cout << mp[a[i] >> 2].top() << " \n"[i == n - 1];
            mp[a[i] >> 2].pop();
        }
    }
    return 0;
}