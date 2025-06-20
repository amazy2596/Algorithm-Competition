#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt n;
    cin >> n;
    vector<intt> a(2);
    a[1] = 1;
    for (int i = 2; i <= n; i++)
        a.push_back(a[i - 1] + 4 * (i - 1));
    cout << a[n];
    return 0;
}