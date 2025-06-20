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
        for (int i = 0; i < 32; i++)
        {
            if ((x >> i & 1) != (y >> i & 1))
            {
                cout << (1 << i) << "\n";
                break;
            }
        }
    }
    return 0;
}