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
        string s;
        cin >> n >> s;
        int count = 0;
        for (int i = 0; i < n; i++)
            count += s[i] == 'U';
        cout << (count % 2 == 1 ? "YES\n" : "NO\n");
    }
    return 0;
}