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
        string s;
        cin >> s;
        if (n == 1)
            cout << (s == "1" ? "Yes\n" : "No\n");
        else if (n == 2)
            cout << (s == "11" ? "Yes\n" : "No\n");
        else 
        {
            string cur;
            vector<int> idx;
            bool f = 1;
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '1')
                {
                    idx.push_back(i);
                    cur += '1';
                    f = 1;
                }
                else if (f && s[i] == '0')
                {
                    cur += '0';
                    f = 0;
                }
            }
            if (idx.size() > cur.size() - idx.size())
                cout << "Yes\n";
            else 
                cout << "No\n";
        }
    }
    return 0;
}