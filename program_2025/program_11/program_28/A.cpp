#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int k;
    cin >> k;
    while (k--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int m = ((c - a) * 1.0l / b) / 0.01l;
        int row = 1, col = 1;
        while (m >= 10) row++, m -= 10;
        while (m >= 1) col++, m--;
        cout << row << " " << col << "\n";
    }
}

int main()
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