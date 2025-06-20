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
        char x, y, i, j;
        int a, b;
        char ch;
        cin >> x >> y >> ch >> i >> j;
        a = (x - '0') * 10 + (y - '0'), b = (i - '0') * 10 + (j - '0');
        if (a == 0)
        {
            if (b < 10)
                cout << 12 << ch << '0' << b << " AM\n";
            else 
                cout << 12 << ch << b << " AM\n";
        }
        else if (a < 10)
        {
            if (b < 10)
                cout << '0' << a << ch << '0' << b << " AM\n";
            else 
                cout << '0' << a << ch << b << " AM\n";
        }
        else if (a < 12)
        {
            if (b < 10)
                cout << a << ch << '0' << b << " AM\n";
            else 
                cout << a << ch << b << " AM\n";
        }
        else if (a == 12)
        {
            if (b < 10)
                cout << a << ch << '0' << b << " PM\n";
            else 
                cout << a << ch << b << " PM\n";
        }
        else 
        {
            a -= 12;
            if (a < 10)
            {
                if (b < 10)
                    cout << '0' << a << ch << '0' << b << " PM\n";
                else 
                    cout << '0' << a << ch << b << " PM\n";
            }
            else
            {
                if (b < 10)
                    cout << a << ch << '0' << b << " PM\n";
                else 
                    cout << a << ch << b << " PM\n";
            }
        }
    }
    return 0;
}