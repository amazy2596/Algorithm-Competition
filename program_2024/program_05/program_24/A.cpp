#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int a[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            cout << a[0][0];
        if (s[i] == '2')
            cout << a[0][1];
        if (s[i] == '3')
            cout << a[0][2];
        if (s[i] == '4')
            cout << a[1][0];
        if (s[i] == '5')
            cout << a[1][1];
        if (s[i] == '6')
            cout << a[1][2];
        if (s[i] == '7')
            cout << a[2][0];
        if (s[i] == '8')
            cout << a[2][1];
        if (s[i] == '9')
            cout << a[2][2];
    }
    return 0;
}