#include<bits/stdc++.h> 
using namespace std;
using i64 = long long;

void solve()
{
    i64 n, m;
    cin >> n >> m;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    auto check = [&](i64 d)
    {
        i64 res = 0;
        for (int i = 1; i <= n; i++)
            res += a[i] / d;
        return res <= m;  
    };

    i64 l = 1, r = 1e15;
    while (l < r)
    {
        i64 mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else 
            l = mid + 1;
    }

    cout << l << "\n";
}

int main( )
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}