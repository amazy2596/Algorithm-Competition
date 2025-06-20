#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 100;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node
{
    node *left = nullptr, *right = nullptr;
    pair<int, int> key;
    int priority;
    int min_left = INT32_MAX;
    node(pair<int, int> key) : key(key), priority(rng()), min_left(key.second) {}
};

int get_left_min(node *cur)
{
    return cur == nullptr ? INT32_MAX : cur->min_left;
}

void update(node *cur)
{
    if (cur != nullptr)
        cur->min_left = min(cur->key.second, min(get_left_min(cur->left), get_left_min(cur->right)));
}

node* merge(node *left_tree, node *right_tree)
{
    if (left_tree == nullptr)   
        return right_tree;
    if (right_tree == nullptr)
        return left_tree;
    
    if (left_tree->priority < right_tree->priority)
    {
        right_tree->left = merge(left_tree, right_tree->left);
        update(right_tree);
        return right_tree;
    }
    else 
    {
        left_tree->right = merge(left_tree->right, right_tree);
        update(left_tree);
        return left_tree;
    }
}

pair<node*, node*> split(node *cur, pair<int, int> key)
{
    if (cur == nullptr)
        return {nullptr, nullptr};
    
    if (key > cur->key)
    {
        auto [left_split, right_split] = split(cur->right, key);
        cur->right = left_split;
        update(cur);
        return {cur, right_split};
    }
    else 
    {
        auto [left_split, right_split] = split(cur->left, key);
        cur->left = right_split;
        update(cur);
        return {left_split, cur};
    }
}

void remove_node(node *&cur, pair<int, int> key)
{
    if (cur == nullptr)
        return;
    
    if (cur->key == key)
    {
        cur = merge(cur->left, cur->right);
        if (cur != nullptr)
            update(cur);
        return;
    }

    if (cur->key > key)
        remove_node(cur->left, key);
    else 
        remove_node(cur->right, key);

    update(cur);
}

int n, m, a[maxn];
node *root;
set<int> s;

void add_segment(int l, int r)
{
    if (l >= r)
        return;

    pair<int, int> key = {r - l, l};
    node *new_node = new node(key);
    auto [left_split, right_split] = split(root, key);
    root = merge(merge(left_split, new_node), right_split);
}

void remove_segment(int l, int r)
{
    if (l >= r)
        return;
    
    pair<int, int> key = {r - l, l};
    remove_node(root, key);
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

    auto [left_split, right_split] = split(root, pair<int, int> {k, -1});
    int result = min(*s.rbegin() + 1, get_left_min(right_split));
    root = merge(left_split, right_split);
    return result;
}

void init()
{
    root = nullptr;
    s = {a, a + n};
    add_segment(1, *s.begin());
    for (auto it = s.begin(); next(it) != s.end(); it++)
        add_segment(*it + 1, *next(it));
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    init();

    cin >> m;

    while (m--)
    {
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
        else 
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
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}