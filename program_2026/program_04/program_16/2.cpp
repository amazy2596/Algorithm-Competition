#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    char ch;
    cin >> ch;
    if (ch <= '9') cout << ch;
    else if (ch >= 'a' && ch <= 'z') cout << ch - 'a' + 10;
    else cout << ch - 'A' + 36;
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