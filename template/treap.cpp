#include <bits/stdc++.h>
#define int long long
using namespace std;

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

void solve()
{
    
}

signed main()
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