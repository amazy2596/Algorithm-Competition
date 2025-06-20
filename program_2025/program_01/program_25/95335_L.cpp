#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    cout << "Yes\n";
    if (n == 1)
        cout << "1 2 3 1";
    else if (n == 2)
        cout << "1 2 4 5 6 3 5 2 3 1";
    else if (n == 3)
        cout << "1 2 4 7 8 9 10 6 9 5 8 4 5 6 3 5 2 3 1";
    else if (n == 4)
        cout << "1 2 4 7 11 12 13 14 15 10 14 9 13 8 12 7 8 9 10 6 9 5 8 4 5 6 3 5 2 3 1";
    else if (n == 5)
        cout << "1 2 4 7 11 16 17 18 19 20 21 15 20 14 19 13 18 12 17 11 12 13 14 15 10 14 9 13 8 12 7 8 9 10 6 9 5 8 4 5 6 3 5 2 3 1";
    else if (n == 6)
        cout << "1 2 4 7 11 16 22 23 24 25 26 27 28 21 27 20 26 19 25 18 24 17 23 16 17 18 19 20 21 15 20 14 19 13 18 12 17 11 12 13 14 15 10 14 9 13 8 12 7 8 9 10 6 9 5 8 4 5 6 3 5 2 3 1";
    else if (n == 7)
        cout << "1 2 4 7 11 16 22 29 30 31 32 33 34 35 36 28 35 27 34 26 33 25 32 24 31 23 30 22 23 24 25 26 27 28 21 27 20 26 19 25 18 24 17 23 16 17 18 19 20 21 15 20 14 19 13 18 12 17 11 12 13 14 15 10 14 9 13 8 12 7 8 9 10 6 9 5 8 4 5 6 3 5 2 3 1";
}       

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}