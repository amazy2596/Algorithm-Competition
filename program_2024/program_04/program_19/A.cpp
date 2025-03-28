#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b >> b >> b >> b >> b;
    if (a[3] == '.')
        cout << "o";
    else if (b[3] == '|')
        cout << "p";
    else 
        cout << "m";
    return 0;
}