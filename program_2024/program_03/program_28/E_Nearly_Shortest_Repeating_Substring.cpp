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
        bool ok = 1;
        for (int len = 1; len <= n && ok; len++)
        {
            if (n % len != 0)
                continue;
            string pre = s.substr(0, len);
            string suf = s.substr(s.length() - len, len);
            int pre_ans = 0, suf_ans = 0;
            for (int i = 0; i < s.length(); i++)
                pre_ans += s[i] != pre[i % len], suf_ans += s[i] != suf[i % len]; 
            if (pre_ans <= 1 || suf_ans <= 1)
            {
                cout << len << "\n";
                break;
            }
        }
    }
    return 0;
}