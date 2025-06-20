#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5 + 100;
const int MAXMEM = 5e6;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node
{
    node *left = nullptr, *right = nullptr;
    pair<int, int> key;
    int priority;
    int min_left = INT32_MAX;

    node(const pair<int, int>& key) : key(key), priority(rng()), min_left(key.second) {}
};

inline int get_min_left(node* cur)
{
    return cur == nullptr ? INT32_MAX : cur->min_left;
}

inline void update(node* cur)
{
    if (cur)
        cur->min_left = min(cur->key.second, min(get_min_left(cur->left), get_min_left(cur->right)));
}

node* merge(node* left_tree, node* right_tree)
{
    if (left_tree == nullptr)
        return right_tree;
    if (right_tree == nullptr)
        return left_tree;
    
    if (left_tree->priority > right_tree->priority)
    {
        left_tree->right = merge(left_tree->right, right_tree);
        update(left_tree);
        return left_tree;
    }
    else 
    {
        right_tree->left = merge(left_tree, right_tree->left);
        update(right_tree);
        return right_tree;
    }
}

pair<node*, node*> split(node* root, const pair<int, int>& x)
{
    if (root == nullptr)
        return {nullptr, nullptr};

    if (root->key < x)
    {
        auto [left_split, right_split] = split(root->right, x);
        root->right = left_split;
        update(root);
        return {root, right_split};
    }
    else 
    {
        auto [left_split, right_split] = split(root->left, x);
        root->left = right_split;
        update(root);
        return {left_split, root};
    }
}

int n, m;
int a[MAXN];
node *mem = (node*)calloc(MAXMEM, sizeof(node));
node *memPos = mem;
node *root = nullptr;
set<int> s;

void add_segment(int l, int r)
{
    if (l >= r)
        return;
    pair<int, int> p {r - l, l};
    auto [left_tree, right_tree] = split(root, p);
    node *new_node = memPos++;
    *new_node = node(p);
    root = merge(merge(left_tree, new_node), right_tree);
}

void remove_node(node*& cur, pair<int, int>& x)
{
    if (cur == nullptr)
        return;
    
    if (cur->key == x)
    {
        cur = merge(cur->left, cur->right);
        if (cur != nullptr)
            update(cur);
        return;
    }
    
    if (cur->key < x)
        remove_node(cur->right, x);
    else 
        remove_node(cur->left, x);
    
    update(cur);
}

void remove_segment(int l, int r)
{
    if (l >= r)
        return;
    pair<int, int> p {r - l, l};
    remove_node(root, p);
}

void add_value(int x)
{
    auto it = s.lower_bound(x);
    int left_boundary = (it == s.begin() ? 0 : *prev(it));
    int right_boundary = (it == s.end() ? INT32_MAX : *it);

    remove_segment(left_boundary + 1, right_boundary);
    add_segment(left_boundary + 1, x);
    
    if (right_boundary != INT32_MAX)
        add_segment(x + 1, right_boundary);

    s.insert(x);
}

void remove_value(int x)
{
    auto it = s.lower_bound(x);
    int left_boundary = (it == s.begin() ? 0 : *prev(it));
    int right_boundary = (next(it) == s.end() ? INT32_MAX : *next(it));

    remove_segment(left_boundary + 1, x);
    remove_segment(x + 1, right_boundary);

    if (right_boundary != INT32_MAX)
        add_segment(left_boundary + 1, right_boundary);

    s.erase(x);
}

int query(int k)
{
    if (s.empty())
        return 1;
    
    auto [left_tree, right_tree] = split(root, make_pair(k, -1));
    int result = min(*s.rbegin() + 1, get_min_left(right_tree));
    root = merge(left_tree, right_tree);

    return result;
}

void init()
{
    root = nullptr;
    memPos = mem;
    s = {a, a + n};
    add_segment(1, *s.begin());
    for (auto it = s.begin(); next(it) != s.end(); it++)
        add_segment(*it + 1, *next(it));

}

void print_tree(node* root, int depth = 0) {
    if (root == nullptr) {
        cout << string(depth * 4, ' ') << "NULL" << endl;
        return;
    }

    // 打印当前节点的信息
    cout << string(depth * 4, ' ') 
         << "Node (" << root->key.first << ", " << root->key.second << ") "
         << " MinLeft: " << root->min_left << endl;

    // 打印左子树
    cout << string(depth * 4, ' ') << "L: ";
    print_tree(root->left, depth + 1);

    // 打印右子树
    cout << string(depth * 4, ' ') << "R: ";
    print_tree(root->right, depth + 1);
}


void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    init();

    int m;
    cin >> m;
    while (m--)
    {
        // print_tree(root);
        char op;
        cin >> op;
        if (op == '+')
        {
            int x;
            cin >> x;
            add_value(x);
        }
        else if (op == '-')
        {
            int x;
            cin >> x;
            remove_value(x);
        }
        else if (op == '?')
        {
            int k;
            cin >> k;
            cout << query(k) << " ";
        }
    }

    cout << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}