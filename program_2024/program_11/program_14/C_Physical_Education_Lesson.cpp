#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    auto check = [&](int n, int x, int k)
    {
        int circle = 2 * k - 2;
        int cnt = n - ((n - (n % circle == 0)) / circle * circle);
        if (cnt <= k)
            return cnt == x;
        else
            return (2 * k - cnt) == x;
    };
    int ans = 0;
    vector<int> a;
    // for (int i = max(2ll, x); i <= n; i++)
    // {
        // if (check(n, x, i))
        // {
            // ans++;
            // a.push_back(i);
        // }
    // }

    // 4 5 7 10 13 14 19 37 40 
    // 6 8 12 18 24 26 36 72 78

    // 4 5 7 10 13 14 19 20 37 40 
    // 6 8 12 18 24 26 36 38 72 78

    for (int i = 1; i <= sqrt((n + x - 2)); i++)
    {
        if ((n + x - 2) % i == 0)
        {
            if (i % 2 == 0 && (i + 2) / 2 >= x)
                a.push_back((i + 2) / 2);
            if ((n + x - 2) / i != i)
            {
                int j = (n + x - 2) / i;
                if (j % 2 == 0 && (j + 2) / 2 >= x)
                    a.push_back((j + 2) / 2);
            }
        }
    }
    for (int i = 1; i <= sqrt((n - x)); i++)
    {
        if ((n - x) % i == 0)
        {
            if (i % 2 == 0 && (i + 2) / 2 >= x)
                a.push_back((i + 2) / 2);
            if ((n - x) / i != i)
            {
                int j = (n - x) / i;
                if (j % 2 == 0 && (j + 2) / 2 >= x)
                    a.push_back((j + 2) / 2);
            }
        }
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    cout << a.size() << "\n";
    // for (auto k : a)
    // {
        // vector<int> temp;
        // temp.push_back(0);
        // int num = 100;
        // while (num--)
        // {
            // int i = 0;
            // while (i < k)
                // temp.push_back(++i);
            // while (i > 2)
                // temp.push_back(--i);
        // }
        // cout << temp[n] << " ";
    // }
    // for (int i = 0; i < a.size(); i++)
    //     cout << a[i] << " ";
    // cout << "\n";
    // for (int i = 0; i < a.size(); i++)
    //     cout << 2 * a[i] - 2 << " ";
    // cout << "\n";
    // cout << ans << "\n";
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