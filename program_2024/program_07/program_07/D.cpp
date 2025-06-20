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
        int a, b, c, temp;
        cin >> a >> b >> c;
        if (c == 0)
            cout << a << " " << b << " 1 0\n";
        else 
        {
            auto check = [&](int a1, int a2, int b1, int b2)
            {
                if (a1 * b2 + a2 * b1 == b)
                {
                    cout << a1 << " " << b1 << " " << a2 << " " << b2 << "\n";
                    return 1;
                }
                return 0;
            };
            auto get = [&](int a1, int a2, int b1, int b2)
            {
                if (check(a1, a2, b1, b2))
                    return 1;
                if (check(a1, a2, b2, b1))
                    return 1;
                if (check(a2, a1, b1, b2))
                    return 1;
                if (check(a2, a1, b2, b1))
                    return 1;
                return 0;
            };
            bool ok = 0;
            for (int i = 1; i <= sqrt(a); i++)
            {
                if (a % i != 0)
                    continue;
                int a1 = i, a2 = a / a1;
                bool f = 0;
                for (int j = 1; j <= sqrt(c); j++)
                {
                    int b1 = j, b2 = c / b1;
                    if (c % j != 0)
                        continue;
                    if (get(a1, b1, a2, b2))
                    {
                        f = 1;
                        break;
                    }
                    else if (get(-a1, -a2, b1, b2))
                    {
                        f = 1;
                        break;
                    }
                    else if (get(a1, a2, -b1, -b2))
                    {
                        f = 1;
                        break;
                    }
                    else if (get(-a1, -b1, -a2, -b2))
                    {
                        f = 1;
                        break;
                    }
                }
                if (f)
                {
                    ok = 1;
                    break;
                }
            }
            if (!ok)
                cout << "NO\n";
        }
    }
    return 0;
}