#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };

struct Trie 
{
    struct Node
    {
        array<int, 26> nex;
        int cnt = 0, end = 0;

        Node() { nex.fill(0); }
    };

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
            int c = s[i] - 'a';
            if (!tree[p].nex[c])
                tree[p].nex[c] = newNode();

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
            int c = s[i] - 'a';
            if (!tree[p].nex[c])
                return 0;

            p = tree[p].nex[c];
        }

        return tree[p].end;
    }

};