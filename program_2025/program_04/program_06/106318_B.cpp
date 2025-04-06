#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

bool check(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
    if (p1.first == 0 && p2.first + p3.first == 0)
        return true;
    if (p1.second == 0 && p2.second + p3.second == 0)
        return true;

    return false;
}

void solve()
{
    pair<int, int> p1, p2, p3;
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;
    cin >> p3.first >> p3.second;

    if (check(p1, p2, p3) || check(p2, p1, p3) || check(p3, p1, p2))
        cout << "YES\n";
    else 
        cout << "NO\n";
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