#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    vector<intt> a(n);
    priority_queue<intt> que;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        que.push(a[i]);
        m -= a[i];
        if (m <= 0 && k > 0 && !que.empty())
        {
            m += que.top();
            que.pop();
            k--;
        }
        if (m <= 0)
        {
            ans = i;
            break;
        }
        else 
            ans = i + 1;
    }
    cout << ans << "\n";
    return 0;
}