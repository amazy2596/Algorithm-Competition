#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    string s;
    int k;
    cin >> s >> k;
    set<string> q;
    for (int len = 1; len <= s.length(); len++)
        for (int j = 0; j <= s.length() - len; j++)
            q.insert(s.substr(j, len));
    cout << 1;
    return 0;
}