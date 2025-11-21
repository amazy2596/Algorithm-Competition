#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

vector<int> Z(const string &s) // 0-indexed
{
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) 
    {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) 
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    z[0] = n; 
    return z;
}
