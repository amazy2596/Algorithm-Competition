#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int k1, k2;
    cin >> k1 >> k2;
    
    auto check = [&](int n, int k)
    {
        if (k < 2)
            return false;
        while (n)
        {
            if (n % k > 1)
                return false;
            n /= k;
        }
        return true;
    };

    vector<vector<int>> a(10, vector<int>(10, 2));
    for (int i = 2; i < 7; i++)
    {
        for (int j = i + 1; j < 7; j++)
        {
            while (!check(a[i][j], i) || !check(a[i][j], j))
            {
                a[i][j]++;
            }
        }
    }

    if (k2 < 7)
    {
        cout << "YES\n";
        cout << a[k1][k2] << "\n";
        return;
    }

    auto fast_pow = [&](int a, int b) -> __int128_t
    {
        __int128_t res = 0, power = 1;

        while (a)
        {
            if (a & 1)
                res += power;
            a >>= 1;
            power = power * b;
        }

        return res;
    };

    int cnt = 2;
    while (true)
    {
        __int128_t num = fast_pow(cnt, k2);
        if (num > 1e18)
        {
            cout << "NO\n";
            return;
        }
        if (check(num, k1) && check(num, k2))
        {
            cout << "YES\n";
            cout << (int) num << "\n";
            return;
        }
        cnt++;
    }

}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}