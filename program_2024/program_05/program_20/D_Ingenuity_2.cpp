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
        int len;
        string str, ans;
        cin >> len >> str;
        int nn = 0, ss = 0, ww = 0, ee = 0;
        for (int i = 0; i < len; i++)
        {
            nn += str[i] == 'N';
            ss += str[i] == 'S';
            ww += str[i] == 'W';
            ee += str[i] == 'E';
        }
        if (nn % 2 != ss % 2 || ww % 2 != ee % 2)
        {
            cout << "NO\n";
            continue;
        }
        char name[2] = {'R', 'H'};
        int n = 0, s = 0, w = 1, e = 1;
        for (int i = 0; i < len; i++)
        {
            if (str[i] == 'N')
                ans += name[n++ % 2];
            else if (str[i] == 'S')
                ans += name[s++ % 2];
            else if (str[i] == 'W')
                ans += name[w++ % 2];
            else 
                ans += name[e++ % 2];
        }
        int r = 0, h = 0;
        for (int i = 0; i < ans.length(); i++)
        {
            r += ans[i] == 'R';
            h += ans[i] == 'H';
        }
        if (!r || !h)
            cout << "NO\n";
        else 
            cout << ans << "\n";
    }
    return 0;
}