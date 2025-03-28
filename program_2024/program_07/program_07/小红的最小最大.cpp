#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    if (min(a, b) + c > max(a, b))
        cout << "YES\n";
    else 
        cout << "NO\n";
    return 0;
}