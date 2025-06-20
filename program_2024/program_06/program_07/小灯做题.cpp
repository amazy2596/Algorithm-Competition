#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        int a, b, c, k;
        cin >> a >> b >> c >> k;
        if (a == k || b == k || c == k)
            cout << 0 << "\n";
        else if (k == 0)
            cout << 1 << "\n";
        else if (k == 1)
        {
            int count_0 = 0;
            count_0 += (a == 0) + (b == 0) + (c == 0);
            if (count_0 != 0)
                cout << 1 << "\n";
            else 
                cout << 2 << "\n";
        }
        else if (k == 2)
        {
            int count_0 = 0, count_1 = 0;
            count_0 += (a == 0) + (b == 0) + (c == 0);
            count_1 += (a == 1) + (b == 1) + (c == 1);
            if (count_0 != 0 && count_1 != 0)
                cout << 1 << "\n";
            else if (count_0 != 0 || count_1 != 0)
                cout << 2 << "\n";
            else 
                cout << 3 << "\n";
        }
        else
            cout << -1 << "\n";
    }
    return 0;
}