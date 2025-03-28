#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1' && b[i] == '1')
            ans++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        char ch;
        cin >> ch;
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (ch == 'A')
        {
            for (int i = l; i <= r; i++)
            {
                if (a[i] == '0')
                {
                    a[i] = '1';
                    ans += (b[i] == '1');
                }
            }
        }
        else 
        {
            for (int i = l; i <= r; i++)
            {
                if (b[i] == '0')
                {
                    b[i] = '1';
                    ans += (a[i] == '1');
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}