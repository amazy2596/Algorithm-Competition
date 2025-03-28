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
    if (a > b && c > b)
        cout << min(a, c) - b;
    else 
        cout << 0;
    return 0;
}