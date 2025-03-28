#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int num = (s[3] - '0') * 100 + (s[4] - '0') * 10 + (s[5] - '0');
    if (num >= 1 && num <= 349 && num != 316)
        cout << "Yes\n";
    else 
        cout << "No\n";
    return 0;
}