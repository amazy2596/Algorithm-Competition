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
        int n;
        cin >> n;
        vector<int> x(n - 1), a;
        for (int i = 0; i < n - 1; i++)
            cin >> x[i];
        a.push_back(x[0] + 1);
        for (int i = 0; i < n - 1; i++)
        {
            if (a.back() > x[i] && x[i] > x[i + 1])
                a.push_back(x[i]);
            else if (i == n - 2)
                a.push_back(x[i] + a.back());
            else
            {
                int l = 0, r = 1e9;
                while (l < r)
                {
                    intt mid = l + r >> 1;
                    if (a.back() * mid + x[i] > x[i + 1])
                        r = mid;
                    else 
                        l = mid + 1;
                }
                a.push_back(x[i] + a.back() * l);
            }
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}