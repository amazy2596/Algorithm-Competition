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
    if (a != b)
        for (int i = 1; i <= 3; i++)
        {
            if (i != a && i != b)
            {
                cout << i;
                break;
            }
        }
    else 
        cout << -1;
    return 0;
}