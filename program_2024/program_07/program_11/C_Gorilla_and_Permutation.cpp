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
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = n; i >= k; i--)
            cout << i << " ";
        for (int i = m + 1; i <= k - 1; i++)
            cout << i << " ";
        for (int i = 1; i <= m; i++)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}