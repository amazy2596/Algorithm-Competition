// Problem: 【模板】字典树
// URL: https://www.luogu.com.cn/problem/P8306
// Author: amazy
// Date: 2025-11-20 21:08:07

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct Trie 
{
    struct Node
    {
        array<int, 65> nex;
        int cnt = 0, end = 0;
        Node() { nex.fill(0); }
    };

    int id(char c)
    {
        if ('a' <= c && c <= 'z') return c - 'a';
        if ('A' <= c && c <= 'Z') return c - 'A' + 26;
        if ('0' <= c && c <= '9') return c - '0' + 52;
    }

    vector<Node> tree;
    Trie(int n = 0)
    {
        tree.reserve(n);
        tree.emplace_back();
    } 

    int newNode()
    {
        tree.emplace_back(Node());
        return tree.size() - 1;
    }
    
    void insert(string s) 
    {
        int p = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            int c = id(s[i]);
            if (!tree[p].nex[c]) tree[p].nex[c] = newNode();
            p = tree[p].nex[c];
            tree[p].cnt++;
        }
        tree[p].end++;
    }

    int find(string s) 
    {
        int p = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            int c = id(s[i]);
            if (!tree[p].nex[c]) return 0;
            p = tree[p].nex[c];
        }
        return tree[p].cnt;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    Trie trie(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        trie.insert(s);
    }

    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        cout << trie.find(s) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}