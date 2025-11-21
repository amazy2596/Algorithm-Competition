#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

vector<int> kmp(const string &s) 
{
    vector<int> v(s.size());
    for(int i = 1, j = 0; i < s.size(); ++i) 
    {
        while(j > 0 && s[i] != s[j]) j = v[j - 1];
        if(s[i] == s[j]) j++;
        v[i] = j;
    }
    return v;
}