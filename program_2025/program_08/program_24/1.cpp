#include<bits/stdc++.h> 
using namespace std;
using i64 = long long;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (q--)
    {
        int op, i, v;
        cin >> op >> i >> v;
        if (op == 1)
            a[i] += v;
        else 
            a[i] -= v;
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main( )
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