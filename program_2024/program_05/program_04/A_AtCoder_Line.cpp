#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    if (x > y)
        swap(x, y);
    if (x < z && z < y)
        cout << "Yes\n";
    else 
        cout << "No\n";
    return 0;
}