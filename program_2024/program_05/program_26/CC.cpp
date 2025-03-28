#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    if ((n - 1) % (k + 1) <= k && (n - 1) % (k + 1) > 0 && n != 1)
        cout << "Tang";
    else 
        cout << "Jiang";
    // if (n == 1)
    //     cout << "Jiang";
    // else 
    // {
    //     int l = 0, r = 1e9;
    //     while (l < r)
    //     {
    //         int mid = (l + r + 1) >> 1;
    //         if (1ll * mid * k < n - 1)
    //             l = mid;
    //         else 
    //             r = mid - 1;
    //     }
    //     if (n - 1 - l * k <= k && n - 1 - l * k > 0)
    //         cout << "Tang";
    //     else 
    //         cout << "Jiang";
    // }
    // vector<int> dp(n + k + 1, 0);
    // for (int i = n - 1; i >= 1; i--)
    // {
    //     bool win = 1;
    //     for (int j = 1; j <= k; j++)
    //     {
    //         if (dp[i + j])
    //         {
    //             win = 0;
    //             break;
    //         }
    //     }
    //     dp[i] = win;
    // }
    // bool f = 0;
    // for (int i = 1; i <= k; i++)
    //     if (dp[i])
    //     {
    //         f = 1;
    //         break;
    //     }
    // cout << (f ? "Tang" : "Jiang");
    return 0;
}