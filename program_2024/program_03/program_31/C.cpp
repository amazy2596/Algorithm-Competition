#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    double n, d, k;
    cin >> n >> d >> k;
    double x1 = d, y1 = 0, x2 = 0, y2 = d, x3 = n, y3 = n - d, x4 = n - d, y4 = n;
    double k1 = (y1 - y2) / (x1 - x2), k2 = (y4 - y2) / (x4 - x2), k3 = (y4 - y3) / (x4 - x3), k4 = (y3 - y1) / (x3 - x1);
    double b1 = y1 - k1 * x1, b2 = y2 - k2 * x2, b3 = y4 - k3 * x4, b4 = y3 - k4 * x3;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        if (d <= n - d)
        {
            if (x <= d)
            {
                double min_y = k1 * x + b1, max_y = k2 * x + b2;
                if (y >= min_y && y <= max_y)
                {
                    cout << "YES\n";
                    continue;
                }
                else 
                {
                    cout << "NO\n";
                    continue;
                }
            }
            else if (x > d && x <= n - d)
            {
                double min_y = k4 * x + b4, max_y = k2 * x + b2;
                if (y >= min_y && y <= max_y)
                {
                    cout << "YES\n";
                    continue;
                }
                else 
                {
                    cout << "NO\n";
                    continue;
                }
            }
            else
            {
                double min_y = k4 * x + b4, max_y = k3 * x + b3;
                if (y >= min_y && y <= max_y)
                {
                    cout << "YES\n";
                    continue;
                }
                else
                {
                    cout << "NO\n";
                    continue;
                }
            }
        }
        else
        {
            if (x <= n - d)
            {
                double min_y = k1 * x + b1, max_y = k2 * x + b2;
                if (y >= min_y && y <= max_y)
                {
                    cout << "YES\n";
                    continue;
                }
                else 
                {
                    cout << "NO\n";
                    continue;
                }
            }
            else if (x > n - d && x <= d)
            {
                double min_y = k1 * x + b1, max_y = k3 * x + b3;
                if (y >= min_y && y <= max_y)
                {
                    cout << "YES\n";
                    continue;
                }
                else 
                {
                    cout << "NO\n";
                    continue;
                }
            }
            else
            {
                double min_y = k4 * x + b4, max_y = k3 * x + b3;
                if (y >= min_y && y <= max_y)
                {
                    cout << "YES\n";
                    continue;
                }
                else 
                {
                    cout << "NO\n";
                    continue;
                }
            }
        }
    }
    return 0;
}