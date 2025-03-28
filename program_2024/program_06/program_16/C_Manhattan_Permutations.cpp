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
        int n, k;
        cin >> n >> k;
        if (k % 2 == 1 || (n - 2) * 4 < k)
            cout << "No\n";
        else 
        {
            vector<int> ans(n + 1), a(n + 1);
            for (int i = 1; i <= n; i++)
                a[i] = i;
            int sum = 0;
            for (int i = 1; i <= n; i++)
            {
                auto it = lower_bound(a.begin(), a.end(), )
            }
        }
    }
    return 0;
}