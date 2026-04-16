#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

template <typename T>
struct ThreadNode {
    T data;
    ThreadNode* left;
    ThreadNode* right;
    ThreadNode* parent;
    int ltag = 0;
    int rtag = 0;

    ThreadNode();
    ThreadNode(const T& value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

template <typename T>
class ThreadBinaryTree {
public:
    using Node = ThreadNode<T>;

public:
    // ==================== 构造 / 析构 ====================
    ThreadBinaryTree() : root_(nullptr) {}
    ~ThreadBinaryTree() { clear(); }

    // ==================== 基本操作 ====================
    void clear()
    {
        destroy(root_);
        root_ = nullptr;
    }
    bool empty() const
    {
        return root_ == nullptr;
    }

    Node* getRoot() const { return root_; }
    void setRoot(Node* root) { root_ = root; }

    Node* createNode(const T& value) { return new Node(value); }

    // ==================== 建树相关 ====================
    void buildFromBinaryTree()         // 从普通二叉树构造
    {

    }
    void createSampleTree()
    {
        clear();

        Node* A = createNode('A');
        Node* B = createNode('B');
        Node* C = createNode('C');
        Node* D = createNode('D');
        Node* E = createNode('E');
        Node* F = createNode('F');
        Node* G = createNode('G');

        root_ = A;
        insertLeft(A, B);
        insertRight(A, C);

        insertLeft(B, D);
        insertRight(B, E);

        insertLeft(C, F);
        insertRight(C, G);
    }
    void insertLeft(Node* parent, Node* child)
    {
        parent->left = child;
        child->parent = parent;
    }
    void insertRight(Node* parent, Node* child)
    {
        parent->right = child;
        child->parent = parent;
    }

    // ==================== 前序线索化 ====================
    void preThreading()                        // 前序线索化入口
    {
        Node *pre = nullptr;
        preThreading(root_, pre);
        if (pre != nullptr)
        {
            pre->right = nullptr;
            pre->rtag = 1;
        }
    }
    void preOrderTraverse_Thr() const         // 前序线索遍历
    {
        Node *p = preFirst(root_);
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = preNext(p);
        }
        cout << '\n';
    }

    Node* preFirst(Node* root) const          // 前序第一个结点
    {
        return root;
    }

    Node* preLast(Node* root) const           // 前序最后一个节点
    {
        if (root == nullptr) return nullptr;
        Node* cur = root;
        while (true)
        {
            if (cur->rtag == 0 && cur->right != nullptr) cur = cur->right;
            else if (cur->ltag == 0 && cur->left != nullptr) cur = cur->left;
            else break;
        }
        return cur;
    }

    Node* preNext(Node* p) const              // 前序后继
    {
        if (p == nullptr) return nullptr;
        if (p->ltag == 0) return p->left;
        return p->right;
    }

    Node* prePrev(Node* p) const              // 前序前驱
    {
        if (p == nullptr) return nullptr;
        if (p->ltag == 1) return p->left;
        Node *pa = p->parent;
        if (pa == nullptr) return nullptr;
        if (pa->left == p) return pa;
        if (pa->right == p)
        {
            if (pa->left == nullptr) return pa;
            return preLast(pa->left);
        }
        return nullptr;
    }

    // ==================== 中序线索化 ====================
    void inThreading()                         // 中序线索化入口
    {
        Node *pre = nullptr;
        inThreading(root_, pre);
        if (pre != nullptr) 
        {
            pre->right = nullptr;
            pre->rtag = 1;
        }
    }
    void inOrderTraverse_Thr() const          // 中序线索遍历
    {
        Node *p = inFirst(root_);
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = inNext(p);
        }
        cout << '\n';
    }

    Node* inFirst(Node* root) const           // 中序第一个结点
    {
        while (root != nullptr && root->ltag == 0) root = root->left;
        return root;
    }
    Node* inLast(Node* root) const            // 中序最后一个结点
    {
        while (root != nullptr && root->rtag == 0) root = root->right;
        return root;
    }
    Node* inNext(Node* p) const               // 中序后继
    {
        if (p == nullptr) return nullptr;
        if (p->rtag == 1) return p->right;
        p = p->right;
        while (p != nullptr && p->ltag == 0) p = p->left;
        return p;
    }
    Node* inPrev(Node* p) const               // 中序前驱
    {
        if (p == nullptr) return nullptr;
        if (p->ltag == 1) return p->left;
        p = p->left;
        while (p != nullptr && p->rtag == 0) p = p->right;
        return p;
    }

    // ==================== 后序线索化 ====================
    void postThreading()                     // 后序线索化入口
    {
        Node *pre = nullptr;
        postThreading(root_, pre);
    }
    void postOrderTraverse_Thr() const        // 后序线索遍历
    {
        Node *p = postFirst(root_);
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = postNext(p);
        }
        cout << '\n';
    }

    Node* postFirst(Node* root) const         // 后序第一个结点
    {
        if (root == nullptr) return nullptr;
        Node *cur = root;
        while (true)
        {
            if (cur->ltag == 0 && cur->left != nullptr) cur = cur->left;
            else if (cur->rtag == 0 && cur->right != nullptr) cur = cur->right;
            else break;
        }
        return cur;
    }
    Node* postLast(Node* root) const          // 后序最后一个结点
    {
        return root;
    }
    Node* postNext(Node* p) const             // 后序后继
    {
        if (p == nullptr) return nullptr;
        if (p->rtag == 1) return p->right;

        Node *pa = p->parent;
        if (pa == nullptr) return nullptr;

        if (pa->right == p) return pa;
        if (pa->left == p)
        {
            if (!(pa->rtag == 0 && pa->right != nullptr)) return pa;
            return postFirst(pa->right);
        }
        return nullptr;
    }
    Node* postPrev(Node* p) const             // 后序前驱
    {
        if (p == nullptr) return nullptr;
        if (p->ltag == 1) return p->left;
        if (p->rtag == 0 && p->right != nullptr) return p->right;
        if (p->ltag == 0 && p->left != nullptr) return p->left;
        return nullptr;
    }

    // ==================== 普通遍历（调试用） ====================
    void preOrder(Node* root) const
    {
        if (root == nullptr) return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node* root) const
    {
        if (root == nullptr) return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void postOrder(Node* root) const
    {
        if (root == nullptr) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    // ==================== 辅助功能 ====================
    bool isLeaf(Node* p) const
    {
        if (p == nullptr) return false;
        bool noLeft = (p->ltag == 0 && p->left == nullptr) || (p->ltag == 1);
        bool noRight = (p->rtag == 0 && p->right == nullptr) || (p->rtag == 1);
        return noLeft && noRight;
    }

private:
    // ==================== 销毁 ====================
    void destroy(Node* node)
    {
        if (node == nullptr) return;
        if (node->ltag == 0) destroy(node->left);
        if (node->rtag == 0) destroy(node->right);
        delete node;
    }

    // ==================== 前序线索化辅助 ====================
    void preThreading(Node* node, Node*& pre)
    {
        if (node == nullptr) return;
        auto l = node->left;
        auto r = node->right;

        if (node->left == nullptr) node->left = pre, node->ltag = 1;
        if (pre != nullptr && pre->right == nullptr) pre->right = node, pre->rtag = 1;
        pre = node;
        preThreading(l, pre);
        preThreading(r, pre);
    }

    // ==================== 中序线索化辅助 ====================
    void inThreading(Node* node, Node*& pre)
    {
        if (node == nullptr) return;
        inThreading(node->left, pre);
        if (node->left == nullptr) node->left = pre, node->ltag = 1;
        if (pre != nullptr && pre->right == nullptr) pre->right = node, pre->rtag = 1;
        pre = node;
        inThreading(node->right, pre);
    }

    // ==================== 后序线索化辅助 ====================
    void postThreading(Node* node, Node*& pre)
    {
        if (node == nullptr) return;
        postThreading(node->left, pre);
        postThreading(node->right, pre);
        if (node->left == nullptr) node->left = pre, node->ltag = 1;
        if (pre != nullptr && pre->right == nullptr) pre->right = node, pre->rtag = 1;
        pre = node;
    }

private:
    Node* root_;
};

void solve()
{
    {
        ThreadBinaryTree<char> tree;
        tree.createSampleTree();
        cout << "前序线索遍历: ";
        tree.preThreading();
        tree.preOrderTraverse_Thr();
        cout << '\n';
    }

    {
        ThreadBinaryTree<char> tree;
        tree.createSampleTree();
        cout << "中序线索遍历: ";
        tree.inThreading();
        tree.inOrderTraverse_Thr();
        cout << '\n';
    }

    {
        ThreadBinaryTree<char> tree;
        tree.createSampleTree();
        cout << "后序线索遍历: ";
        tree.postThreading();
        tree.postOrderTraverse_Thr();
        cout << '\n';
    }
}

int main()
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