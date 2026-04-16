// Problem: 快端上来
// URL: https://ac.nowcoder.com/acm/contest/133247/J
// Author: amazy
// Date: 2026-04-12 14:32:59

#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 lcm(i64 a, i64 b)
{
    return a * b / gcd(a, b);
}

void solve()
{
    i64 a, b, n;
    cin >> a >> b >> n;
    i64 ans;
    if (a % b == 0) ans = n / b;
    else if (b % a == 0) ans = n / a;
    else ans = n / a + n / b - n / lcm(a, b);
    cout << ans << "\n";


    // for (int a = 1; a <= 100; a++)
    // {
    //     for (int b = 1; b <= 100; b++)
    //     {
    //         for (int n = 1; n <= 100; n++)
    //         {
    //             i64 ans;
    //             if (a % b == 0) ans = n / b;
    //             else if (b % a == 0) ans = n / a;
    //             else ans = n / a + n / b - n / (a * b);

    //             i64 tar = 0;
    //             for (int i = 1; i <= n; i++)
    //             {
    //                 if (i % a == 0 || i % b == 0) 
    //                     tar++;
    //             }

    //             if (ans != tar)
    //             {
    //                 cout << a << " " << b << " " << n << "\n";
    //                 return;
    //             }
    //         }
    //     }
    // }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}