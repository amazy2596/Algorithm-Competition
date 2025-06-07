#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

struct Trie {
    
    int tot;
    vector<vector<int>> nex;
    vector<int> cnt; // 以这个节点结尾的字符串的个数
    Trie() : nex(1e6 + 5, vector<int>(26)), cnt(1e6 + 5) {}
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

void solve()
{
    
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}