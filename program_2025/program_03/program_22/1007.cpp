#include <bits/stdc++.h>
using namespace std;

const int BITS = 31;

struct Node 
{
    int cnt;      
    int child[2]; 
    Node() : cnt(0) 
    {
        child[0] = child[1] = 0;
    }
};

vector<Node> trie;

int newNode() 
{
    trie.push_back(Node());
    return trie.size() - 1;
}

int insert(int prev, int x, int pos = BITS) 
{
    int cur = newNode();                
    trie[cur].cnt = trie[prev].cnt + 1;   
    if (pos < 0)
        return cur;
    
    int bit = (x >> pos) & 1;
    trie[cur].child[bit ^ 1] = trie[prev].child[bit ^ 1];

    trie[cur].child[bit] = insert(trie[prev].child[bit], x, pos - 1);
    return cur;
}

int query(int l, int r, int x, int pos = BITS) 
{
    if (pos < 0)
        return 0;
    int bit = (x >> pos) & 1;

    int cntL = trie[ trie[l].child[bit ^ 1] ].cnt;
    int cntR = trie[ trie[r].child[bit ^ 1] ].cnt;
    if (cntR - cntL > 0) 
        return (1 << pos) | query(trie[l].child[bit ^ 1], trie[r].child[bit ^ 1], x, pos - 1);
    else
        return query(trie[l].child[bit], trie[r].child[bit], x, pos - 1);
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) 
    {
        int n, q;
        cin >> n >> q;

        trie.clear();
        trie.reserve((n + 1) * (BITS + 2));
        trie.push_back(Node());
 
        vector<int> root(n + 1, 0);
        root[0] = 0;  
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) 
        {
            cin >> a[i];
            root[i] = insert(root[i - 1], a[i]);
        }
 
        while (q--) 
        {
            int l, r, x;
            cin >> l >> r >> x;
            cout << query(root[l - 1], root[r], x) << "\n";
        }
    }
    return 0;
}
