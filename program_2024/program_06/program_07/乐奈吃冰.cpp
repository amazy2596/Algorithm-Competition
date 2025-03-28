#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    cout << a + (a / 2 >= b ? b : a / 2);
    return 0;
}