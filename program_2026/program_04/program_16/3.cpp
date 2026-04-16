#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int s, m, n;
    cin >> s >> m >> n;
    if (m == 0) 
    {
        cout << "WanMei!\n";
        return;
    }
    if (n >= m && s > m)
    {
        cout << "WanMei!\n";
        return;
    }
    for (int i = 1; i <= 1e6; i++)
    {
        s -= m;
        if (s <= 0) cout << i << "\n";
        s += n;
    }
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