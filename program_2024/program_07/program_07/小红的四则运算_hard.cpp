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
    cout << max({a + b + c, (a + b) * c, a * (b + c), a * b * c});
    return 0;
}