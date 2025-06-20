#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5;

void solve()
{
    int k;
    cin >> k;
    set<int> s;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    k -= 2;
    for (int i = 1; i <= N; i++)
    {
        if (k % i == 0)
        {
            int j = k / i;
            if (s.count(i) && s.count(j))
            {
                cout << i << " " << j << "\n";
                return;
            }
        }
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