#include <bits/stdc++.h>
#define int long long
using namespace std;

int query(int x, int y)
{
    int res;
    cout << "? " << x << " " << y << endl;
    cin >> res;
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n);
    priority_queue<int, vector<int>, greater<int>> q;
    int i = 2;
    while(i < n)
    {
        int res = query(1, i);
        q.push(i);
        if (res == 0)
        {
            ans[i] = 1;
            i++;
            break;
        }
        i++;
    }
    while (!q.empty() && i < n)
    {
        int top = q.top();
        q.pop();
        int res = query(top, i);
        if (res == 0)
        {
            ans[i] = top;
            q.push(i);
            i++;
        }
    }
    cout << "! ";
    for (int i = 1; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}