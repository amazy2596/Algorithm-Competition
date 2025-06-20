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
        int a, b, c;
        cin >> a >> b >> c;
        int mx = 0;
        for (int i = 0; i <= 5; i++)
            for (int j = 0; j <= 5; j++)
                {
                    if (i + j > 5)
                        continue;
                    else 
                    {
                        int k = 5 - i - j;
                        mx = max(mx, (a + i) * (b + j) * (c + k));
                    }
                }
        cout << mx << "\n";
    }
    return 0;
}