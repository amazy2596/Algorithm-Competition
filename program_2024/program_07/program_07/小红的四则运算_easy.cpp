#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    cout << max({a[0] * a[1] * a[2], a[0] + a[1] + a[2], (a[0] + a[1]) * a[2], (a[1] + a[2]) * a[0], (a[0] + a[2]) * a[1]});
    return 0;
}