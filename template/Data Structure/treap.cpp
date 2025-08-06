#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 inf = 1e18; 

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };

struct Node
{
    Node *left = nullptr, *right = nullptr;
    pair<int, int> key;
    int priority;
    int min_left = INT32_MAX;
    Node(pair<int, int> key) : key(key), priority(rng()), min_left(key.second) {}
};

int get_left_min(Node *cur)
{
    return cur == nullptr ? INT32_MAX : cur->min_left;
}

void update(Node *cur)
{
    if (cur != nullptr)
        cur->min_left = min(cur->key.second, min(get_left_min(cur->left), get_left_min(cur->right)));
}

Node* merge(Node *left_tree, Node *right_tree)
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

pair<Node*, Node*> split(Node *cur, pair<int, int> key)
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

void remove_node(Node *&cur, pair<int, int> key)
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

void solve()
{
    
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}