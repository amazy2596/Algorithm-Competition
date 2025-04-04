#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "-1\n";
        return;
    }

    deque<int> a;
    for (int i = 1; i <= n; i += 2)
        a.push_back(i);
    for (int i = 2; i <= n; i += 2)
        a.push_back(i);

    while (--n)
    {
        a.push_back(a.front());
        a.pop_front();
    }

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}