#include <bits/stdc++.h>
using intt = long long;
using namespace std;

bool check(string s, int l, int r)
{
    if (s[l] >= 'a' && s[l] <= 'z' && s[r] >= 'a' && s[r] <= 'z')    
        return true;
    if (s[l] >= '0' && s[l] <= '9' && s[r] >= '0' && s[r] <= '9')
        return true;
    return false;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string s;
    cin >> s;
    // vector<int> index;
    // for (int i = 0; i < s.length(); i++)
        // if (i != s.length() - 1 && s[i] == '-' && ((s[i + 1] >= 'a' && s[i - 1] >= 'a' && s[i + 1] <= 'z' && s[i + 1] <= 'z' && s[i + 1] != s[i - 1])||(s[i + 1] >= '0' && s[i - 1] >= '0' && s[i + 1] <= '9' && s[i - 1] <= '9' && s[i + 1] != s[i - 1])))
            // index.push_back(i);
    // index.push_back(0);
    // int idx = 0;
    // vector<string> ans(105);
    // for (int i = 0; i < index.size() - 1; i++)
    // {
        // for (char ch = s[index[i] - 1] + 1; ch < s[index[i] + 1]; ch++)
        // {
            // for (int j = 0; j < p2; j++)
                // ans[idx] += (p1 == 1 ? tolower(ch) : (p1 == 2 ? toupper(ch) : '*'));
        // }
        // if (p3 == 2)
            // reverse(ans[idx].begin(), ans[idx].end());
        // idx++;
    // }
    // idx = 0;
    // for (int i = 0; i < s.length(); i++)
        // if (i == index[idx])
            // cout << ans[idx++];
        // else 
            // cout << s[i];
    for (int i = 0; i < s.length(); i++)
    {
        if (i != s.length() - 1 && s[i] == '-' && s[i - 1] < s[i + 1] && check(s, i - 1, i + 1))
        {
            string ans;
            for (char ch = s[i - 1] + 1; ch < s[i + 1]; ch++)
            {
                for (int j = 0; j < p2; j++)
                    ans += (p1 == 1 ? ch : (p1 == 2 ? toupper(ch) : '*'));
            }
            if (p3 == 2)
                reverse(ans.begin(), ans.end());
            cout << ans;
        }
        else 
            cout << s[i];
    }
    return 0;
}