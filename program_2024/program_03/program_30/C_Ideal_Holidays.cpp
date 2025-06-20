#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt n, a, b;
    cin >> n >> a >> b;
    bool ok = 0;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 1; i <= a + b; i++)
    {
        bool temp = 1;
        for (int j = 0; j < n; j++)
        {
            if ((i + p[j]) % (a + b) > a || (i + p[j]) % (a + b) == 0)
            {
                temp = 0;
                break;
            }
        }
        if (temp)
        {
            ok = 1;
            break;
        }
    }
    cout << (ok ? "Yes\n" : "No\n"); 
    return 0;
}