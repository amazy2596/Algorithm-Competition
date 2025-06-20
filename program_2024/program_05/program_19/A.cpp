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
    if (n % 2)
        cout << -1 << "\n";
    else 
        cout << n / 2 << " " << n / 2 << "\n";
    return 0;
}