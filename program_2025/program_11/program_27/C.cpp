#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct node
{
    char ch = '#';
    node *left = nullptr, *right = nullptr;

    node() = default;
    node(char _ch) : ch(_ch) {}
};

node* build(string &s, int &idx)
{
    if (idx >= s.length()) return nullptr;
    if (s[idx] == '1') 
    {
        idx++;
        return new node(s[idx++]); 
    }
    else if (s[idx] == '0') 
    {
        node *cur = new node();
        idx++;
        cur->left = build(s, idx);
        cur->right = build(s, idx);
        return cur;
    }
    return nullptr;
}

map<char, string> g = {
    {'0', "0000"},
    {'1', "0001"},
    {'2', "0010"},
    {'3', "0011"},
    {'4', "0100"},
    {'5', "0101"},
    {'6', "0110"},
    {'7', "0111"},
    {'8', "1000"},
    {'9', "1001"},
    {'a', "1010"},
    {'b', "1011"},
    {'c', "1100"},
    {'d', "1101"},
    {'e', "1110"},
    {'f', "1111"},
};

void solve()
{
    int s, d;
    cin >> s >> d;
    vector<pair<string, string>> a(s + 1);
    deque<pair<string, string>> b;
    for (int i = 1; i <= s; i++)
    {
        string k, v;
        cin >> k >> v;
        a[i] = {k, v};
    }
    
    string huff;
    cin >> huff;

    int idx = 0;
    auto root = build(huff, idx);
    map<string, char> decode;

    auto dfs = [&](auto dfs, node *cur, string code) -> void
    {
        if (cur == nullptr) return;
        if (cur->ch != '#') decode[code] = cur->ch;
        if (cur->left != nullptr) dfs(dfs, cur->left, code + "0");
        if (cur->right != nullptr) dfs(dfs, cur->right, code + "1");
    };
    dfs(dfs, root, "");

    auto calc = [&](string s)
    {
        if (s[0] != 'H') return s;
        if (s[1] == 'H') return s.substr(1);
        s = s.substr(1);
        int num = s.back() - '0';
        string tmp;
        for (int i = 0; i < s.size() - 2; i++) tmp += g[s[i]];
        while (num--) tmp.pop_back();

        string res, cur;
        for (auto ch : tmp)
        {
            cur += ch;
            if (decode.find(cur) != decode.end())
            {
                res += decode[cur];
                cur = "";
            }
        }
        return res;
    };

    int m;
    cin >> m;
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i;
            cin >> i;
            if (i <= s) cout << a[i].first << ": " << a[i].second << "\n";
            else if (i <= s + b.size()) cout << b[i - s - 1].first << ": " << b[i - s - 1].second << "\n";
        }
        else if (op == 2)
        {
            int i;
            cin >> i;
            string k, v;

            if (i == 0)
            {
                cin >> k >> v;
                k = calc(k), v = calc(v);
                cout << k << ": " << v << "\n";
            }
            else 
            {
                if (i <= s) k = a[i].first;
                else if (i <= s + b.size()) k = b[i - s - 1].first;
                cin >> v;
                v = calc(v);
                cout << k << ": " << v << "\n";
            }
            b.push_front({k, v});
            if (b.size() > d) b.pop_back();
        }
        else 
        {
            int i;
            cin >> i;
            string k, v;

            if (i == 0)
            {
                cin >> k >> v;
                k = calc(k), v = calc(v);
                cout << k << ": " << v << "\n";
            }
            else 
            {
                if (i <= s) k = a[i].first;
                else if (i <= s + b.size()) k = b[i - s - 1].first;
                cin >> v;
                v = calc(v);
                cout << k << ": " << v << "\n";
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}