#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    // 5 3 1 2 4
    if (n % 2 == 0)
        cout << "-1\n";
    else 
    {
        deque<int> d;
        d.push_back(1);
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
                d.push_back(i);
            else 
                d.push_front(i);
        }
        for (int i = 0; i < n; i++)
            cout << d[i] << " ";
        cout << "\n";
    }
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