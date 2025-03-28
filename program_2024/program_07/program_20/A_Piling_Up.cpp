#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int r;
    cin >> r;
    if (r <= 99)
        cout << 100 - r << "\n";
    else if (r <= 199)
        cout << 200 - r << "\n";
    else if (r <= 299)
        cout << 300 - r << "\n";
    else if (r <= 399)
        cout << 400 - r << "\n";
    return 0;
}