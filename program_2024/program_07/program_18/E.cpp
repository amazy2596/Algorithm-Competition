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
        intt x;
        cin >> x;
        if (x == 1)
            cout << -1 << "\n";
        else if (x % 2 == 0)
        {
            if (log2(double(x)) - intt(log2(double(x))) == 0)
                cout << -1 << "\n";
            else 
            {
                for (int i = 0; i <= 63; i++)
                    if ((x >> i & 1) == 1)
                    {
                        cout << x - (1ll << i) << "\n";
                        break;
                    }
            }
        }
        else 
            cout << x - 1 << "\n";
    }
    return 0;
}

// 01100100
// 01100010
// 01100000