#include <bits/stdc++.h>
using intt = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 4 == 0)
        cout << n / 4 << "\n";
    else 
        cout << n / 4 + (n - n / 4 * 4) / 2 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}