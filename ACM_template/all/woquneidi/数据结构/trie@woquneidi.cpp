                
struct Trie {
    
    int tot;
    vector<vector<int>> nex;
    vector<int> cnt; // 以这个节点结尾的字符串的个数
    Trie() : nex(100001, vector<int>(26)), cnt(100001) {}
    Trie(int n, int m) : nex(n + 1, vector<int>(m)), cnt(n + 1) {} 
    // n为树中最多会有多少个节点, m表示有多少种字符
    void insert(string s, int t = 1) {    // 插入字符串
        int p = 0;
        for (int i = 0; i < s.length(); i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) nex[p][c] = ++tot;    // 如果没有，就添加结点
            p = nex[p][c];
        }
        cnt[p] += t;
    }

    bool find(string s) {    // 查找字符串
        int p = 0;
        for (int i = 0; i < s.length(); i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) return 0;
            p = nex[p][c];
        }
        return cnt[p];
    }
};