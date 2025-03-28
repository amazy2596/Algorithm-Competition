#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n <= 2)
        cout << "NO\n";
    else 
        cout << "YES\n" << 1 << " " << n - 1 << "\n";
    return 0;
}