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
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < 100; i++)
        {
            if (i * 2 >= y && (15 * i - y * 4) >= x)
            {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}