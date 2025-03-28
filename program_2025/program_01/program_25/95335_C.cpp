#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e6 + 5;
const int alp = 26;
int trie[N][26];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int nodeCount = 1;
    int edges = 0; 
    int maxLen = 0;

    auto insertWord = [&](const string &s)
    {
        int p = 0; 
        for (char c : s) 
        {
            int idx = c - 'a';
            if (trie[p][idx] == 0) 
            {
                trie[p][idx] = nodeCount++;
                edges++;
            }
            p = trie[p][idx];
        }
    };

    for (int i = 0; i < n; i++) 
    {
        string s; 
        cin >> s;
        maxLen = max(maxLen, (int)s.size());
        insertWord(s);
    }

    cout << 2 * edges - maxLen << "\n";
    return 0;
}