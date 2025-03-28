#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int a = 0, b = 0;
    for (int i = 0; i < 9; i++)
    {
        int x;
        cin >> x;
        a += x;
    }
    for (int i = 0; i < 8; i++)
    {
        int x;
        cin >> x;
        b += x;
    }
    cout << a - b + 1;
    return 0;
}