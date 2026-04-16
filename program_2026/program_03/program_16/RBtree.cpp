#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct Node
{
    int key;
    Node *parent = nullptr;
    Node *lchild = nullptr, *rchild = nullptr;
    int color;

    Node(int x) : key(x) {}
};

Node *root = nullptr;

Node* newNode(int x)
{
    Node *res = new Node(x);
    res->color = 1;
    return res;
}

void reverse(Node *cur) { cur->color ^= 1; }

Node* find(int x)
{
    Node *cur = root;
    while (cur != nullptr)
    {
        if (cur->key == x) return cur;
        else if (x < cur->key) cur = cur->lchild;
        else if (x > cur->key) cur = cur->rchild;
    }
    return nullptr;
}

void leftRotate(Node *cur)
{
    Node *parent = cur->parent;
    Node *child = cur->rchild;
    assert(child != nullptr);

    if (parent == nullptr) root = child;
    else if (parent->lchild == cur) parent->lchild = child;
    else parent->rchild = child;

    cur->rchild = child->lchild;
    if (child->lchild != nullptr) child->lchild->parent = cur;
    cur->parent = child;

    child->parent = parent;
    child->lchild = cur;
}

void rightRotate(Node *cur)
{
    Node *parent = cur->parent;
    Node *child = cur->lchild;
    assert(child != nullptr);

    if (parent == nullptr) root = child;
    else if (parent->lchild == cur) parent->lchild = child;
    else parent->rchild = child;

    cur->lchild = child->rchild;
    if (child->rchild != nullptr) child->rchild->parent = cur;
    cur->parent = child;

    child->parent = parent;
    child->rchild = cur;
}

int colorof(Node *node)
{
    return node == nullptr ? 0 : node->color;
}

void insertFixup(Node *cur)
{
    Node *pa = cur->parent;
    Node *gpa = pa->parent;
    Node *uncle = (gpa->lchild == pa ? gpa->rchild : gpa->lchild);

    if (colorof(uncle) == 0)
    {
        if (pa == gpa->lchild)
        {
            if (cur == pa->lchild)
            {
                rightRotate(gpa);
                reverse(pa);
                reverse(gpa);
            }
            else
            {
                leftRotate(pa);
                rightRotate(gpa);
                reverse(cur);
                reverse(gpa);
            }
        }
        else
        {
            if (cur == pa->rchild) 
            {
                leftRotate(gpa);
                reverse(pa);
                reverse(gpa);
            }
            else
            {
                rightRotate(pa);
                leftRotate(gpa);
                reverse(cur);
                reverse(gpa);
            }
        }
    }
    else 
    {
        reverse(pa);
        reverse(uncle);
        reverse(gpa);
        if (gpa->parent != nullptr && gpa->parent->color == 1) insertFixup(gpa);
    }
}

void insert(int x)
{
    if (root == nullptr)
    {
        root = newNode(x);
        root->color = 0;
        return; 
    }

    Node *cur = root;
    while (cur != nullptr)
    {
        if (x <= cur->key)
        {
            if (cur->lchild == nullptr)
            {
                auto tmp = newNode(x);
                cur->lchild = tmp;
                tmp->parent = cur;
                cur = tmp;
                break;
            }
            else cur = cur->lchild;
        }
        else if (x > cur->key)
        {
            if (cur->rchild == nullptr)
            {
                auto tmp = newNode(x);
                cur->rchild = tmp;
                tmp->parent = cur;
                cur = tmp;
                break;
            }
            else cur = cur->rchild;
        }
    }

    if (cur->parent != nullptr && cur->parent->color == 1) insertFixup(cur);
    root->color = 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], insert(a[i]);

    vector<vector<Node*>> depth(n + 1);
    auto dfs = [&](auto dfs, Node *cur, int d) -> void
    {
        if (cur != nullptr) depth[d].push_back(cur);
        if (cur->lchild != nullptr) dfs(dfs, cur->lchild, d + 1);
        if (cur->rchild != nullptr) dfs(dfs, cur->rchild, d + 1);
    };
    dfs(dfs, root, 0);

    for (int i = 0; i < n; i++)
    {
        for (auto u : depth[i])
        {
            if (u->color == 1) cout << "!";
            cout << u->key << " ";
        }
        cout << "\n";
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
