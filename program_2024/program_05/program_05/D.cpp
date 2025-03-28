#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, q;
    string s;
    cin >> n >> q >> s;
    string ss = "red";
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        if (len < 3)
        {
            cout << 0 << "\n";
            continue;
        }
        string cur = s.substr(l - 1, len);
        int ans = len;
        int cnt = len / 3;
        string tempp;
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < cnt; k++)
                tempp += ss[j];
        }
        if (len % 3 == 1)
        {
            for (int i = 0; i < 3; i++)
            {
                string temp = tempp;
                temp.insert(temp.begin() + temp.find(ss[i]), ss[i]);
                int anss = 0;
                for (int j = 0; j < cur.length(); j++)
                    if (cur[j] != temp[j])
                        anss++;
                ans = min(ans, anss);
            }
        }
        else if (len % 3 == 2)
        {
            for (int i = 0; i < 3; i++)
            {
                string temp = tempp;
                for (int j = 0; j < 3; j++)
                    if (i != j)
                        temp.insert(temp.begin() + temp.find(ss[j]), ss[j]);
                int anss = 0;
                for (int j = 0; j < cur.length(); j++)
                    if (cur[j] != temp[j])
                        anss++;
                ans = min(ans, anss);
            }
        }
        else if (len % 3 == 0)
        {
            int anss = 0;
            for (int i = 0; i < cur.length(); i++)
                if (cur[i] != tempp[i])
                    anss++;
            ans = min(ans, anss);
        }
        cout << ans << "\n";
    }
    return 0;
}