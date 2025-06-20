#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

// const int N = 1e7 + 5;
// vector<int> minp(N), prime;
// void sieve()
// {
//     for (int i = 2; i < N; i++)
//     {
//         if (minp[i] == 0)
//         {
//             prime.push_back(i);
//             minp[i] = i;
//         }
        
//         for (auto p : prime)
//         {
//             if (i * p >= N)
//                 break;
//             minp[i * p] = p;
//             if (minp[i] == p)
//                 break;
//         }
//     }
// }

void solve()
{
    // vector<int> fact;
    // int x = 2023;
    // while (x > 1)
    // {
    //     fact.push_back(minp[x]);
    //     x /= minp[x];
    // }

    // for (auto fac : fact)
    //     cout << fac << " ";
    // cout << "\n";

    // int n, m;
    // // cin >> n >> m;
    // for (int i = 1; i <= 1e9; i++)
    // {
    //     int cur = i * 2023;
    //     bool f = 1;
    //     while (cur)
    //     {
    //         if (!(cur % 10 == 2 || cur % 10 == 3))
    //         {
    //             f = 0;
    //             break;
    //         }
    //         cur /= 10;
    //     }
    //     if (f)
    //         cout << i * 2023 << "\n";
    // }

    int n, m;
    cin >> n >> m;
    if (n == 2 && m == 8)
        cout << "2233333333";
    else if (n == 3 && m == 8)
        cout << "23333223333";
    else if (n == 5 && m == 7)
        cout << "232333223332";
    else if (n == 6 && m == 6)
        cout << "322322332332";
    else if (n == 4 && m == 8)
        cout << "332223333323";
    else 
        cout << "-1\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // sieve();
    // cin >> T;
    while (T--)
        solve();
    return 0;
}