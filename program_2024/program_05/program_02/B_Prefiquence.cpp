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
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        int last = 0;
        int ans = 0;
        for (int i = 0; i < a.length(); i++)
        {
            bool f = 1;
            for (int j = last; j < b.length(); j++)
            {
                if (a[i] == b[j])
                {
                    f = 0;
                    ans++;
                    last = j + 1;
                    break;
                }
            }
            if (f)
                break;
        }
        cout << ans << "\n";
    }
    return 0;
}