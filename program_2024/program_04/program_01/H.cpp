#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    for (int i = 0; i < 1e9; i++)
    {
        if (1e18 + i != 1e18)
        {
            cout << i - 1;
            break;
        }
    }
    return 0;
}