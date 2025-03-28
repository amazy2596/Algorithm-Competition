#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    double p2 = c * 1.0 / d;
    if (p2 != 0)
        cout << "Infinity";
    else 
        cout << "limited";
    return 0;
}