#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    unordered_map<string, int> mapp;
    string s;
    cin >> s;
    for (int len = 1; len <= s.length(); len++)
    {
        for (int i = 0; i <= s.length() - len; i++)
        {
            string temp = s.substr(i, len);
            if (mapp.find(temp) == mapp.end())
                mapp[temp]++;
        }
    }
    cout << mapp.size();
    return 0;
}