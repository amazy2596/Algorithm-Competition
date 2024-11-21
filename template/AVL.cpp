#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key, height;
    node *left;
    node *right;
    node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

int getHeight(node *root)
{
    return root == nullptr ? 0 : root->height;
}

int calcBF(node *root)
{
    return root == nullptr ? 0 : getHeight(root->left) - getHeight(root->right);
}

void update(node *root)
{
    if (root != nullptr)
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

node* rightRotate(node *root)
{
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root = temp;

    update(root->right);
    update(root);
    return root;
}

node* leftRotate(node *root)
{
    node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root = temp;

    update(root->left);
    update(root);
    return root;
}

node* balance(node *root)
{
    int bf = calcBF(root);
    int left_bf = calcBF(root->left);
    int right_bf = calcBF(root->right);

    if (bf > 1 && left_bf >= 0)
        return rightRotate(root);
    if (bf < -1 && right_bf <= 0)
        return leftRotate(root);
    
    if (bf > 1 && left_bf < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bf < -1 && right_bf > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

node* insert(node *root, int key)
{
    if (root == nullptr)
        return new node(key);
    
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else if (key == root->key)
        return root;

    update(root);

    return balance(root);
}

node* minValue(node *root)
{
    return root->left == nullptr ? root : minValue(root->left);
}

node* erase(node *root, int key)
{
    if (root == nullptr)
        return root;
    
    if (key < root->key)
        root->left = erase(root->left, key);
    else if (key > root->key)
        root->right = erase(root->right, key);
    else if (key == root->key)
    {
        if (root->left == nullptr || root->right == nullptr)
        {
            node *temp = root->left == nullptr ? root->right : root->left;
            if (temp == nullptr)
                root = nullptr;
            else
                root = temp;
            delete temp;
        }
        else
        {
            node *temp = minValue(root->right);
            root->key = temp->key;
            root->right = erase(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;
    
    update(root);

    return balance(root);
}

// 中序遍历，保存节点的key
void inorderTraversal(node* root, vector<int>& result) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left, result);
    result.push_back(root->key);
    inorderTraversal(root->right, result);
}

// 检查中序遍历是否有序
bool isInorderSorted(node* root) {
    vector<int> result;
    inorderTraversal(root, result);
    for (size_t i = 1; i < result.size(); i++) {
        if (result[i] <= result[i - 1]) {
            return false;
        }
    }
    return true;
}

// 递归检查平衡因子是否满足条件
bool checkBalanceFactor(node* root) {
    if (root == nullptr)
        return true;

    int leftHeight = root->left ? root->left->height : 0;
    int rightHeight = root->right ? root->right->height : 0;

    int balanceFactor = leftHeight - rightHeight;

    if (balanceFactor < -1 || balanceFactor > 1) {
        return false;
    }

    return checkBalanceFactor(root->left) && checkBalanceFactor(root->right);
}

// 递归检查节点高度是否正确
bool checkHeight(node* root) {
    if (root == nullptr)
        return true;

    int leftHeight = root->left ? root->left->height : 0;
    int rightHeight = root->right ? root->right->height : 0;

    int expectedHeight = max(leftHeight, rightHeight) + 1;

    if (root->height != expectedHeight) {
        return false;
    }

    return checkHeight(root->left) && checkHeight(root->right);
}

// 检查整个AVL树是否平衡且满足二叉查找树的性质
bool isAVL(node* root) {
    return isInorderSorted(root) && checkBalanceFactor(root) && checkHeight(root);
}

int main() {
    node* tree = nullptr;

    // 示例插入和删除操作
    tree = insert(tree, 10);
    tree = insert(tree, 20);
    tree = insert(tree, 30);  // 应该触发左旋
    tree = insert(tree, 40);
    tree = insert(tree, 50);  // 应该触发平衡操作

    // 检查AVL树是否正确
    if (isAVL(tree)) {
        cout << "AVL树是正确的且平衡的。" << endl;
    } else {
        cout << "AVL树不平衡或不正确。" << endl;
    }

    tree = erase(tree, 30);
    tree = erase(tree, 10);

    // 再次检查AVL树是否正确
    if (isAVL(tree)) {
        cout << "AVL树在删除操作后依然是正确的且平衡的。" << endl;
    } else {
        cout << "AVL树在删除操作后不平衡或不正确。" << endl;
    }

    return 0;
}
