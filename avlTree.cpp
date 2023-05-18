#include <bits/stdc++.h>
using namespace std;
int const MAX = 1e6;
class Node 
{
public:
    int value;
    Node *left;
    Node *right;
    int height;
    Node(int data)
    {
        left = NULL;
        right = NULL;
        value = data;
        height = 1;
    }
};
// tính chiều cao của cây
int height(Node *n) 
{
    return (n == NULL) ? 0 : n->height; 
}
// Xoay phải
Node *rotateRight(Node *y) 
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
    return x;
}
// Xoay trái
Node *roteteLeft(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
    return y;
}
// tính chỉ số cân bằng của một nút
int balance(Node *N) 
{
    return (N == NULL) ? 0 : (height(N->left) - height(N->right));
}
// chèn một nút vào cây AVL
Node *insertNode(Node *node, int value) {
    // tìm vị trí thích hợp và chèn nút vào đó
    if (node == NULL) 
    {
        node = new Node(value);
        return node;
    }
    if (value < node->value) node->left = insertNode(node->left, value);
    else if (value > node->value) node->right = insertNode(node->right, value);
    else return node;
    // cập nhật chỉ số cân bằng và tiến hành cân bằng cây
    node->height = 1 + max(height(node->left),height(node->right));
    int balanceFactor = balance(node);
    if (balanceFactor > 1) 
    {
        if (value < node->left->value)
        {
            return rotateRight(node);
        } 
        else if (value > node->left->value)
        {
            node->left = roteteLeft(node->left);
            return rotateRight(node);
        }
    }
    if (balanceFactor < -1) 
    {
        if (value > node->right->value) return roteteLeft(node);
        else if (value < node->right->value) 
        {
            node->right = rotateRight(node->right);
            return roteteLeft(node);
        }
    }
    return node;
}
// giải phóng bộ nhớ đã cấp phát cho câ
void releaseMemory(Node* node)
{
    if (node->left != NULL) releaseMemory(node->left);
    if (node->right != NULL) releaseMemory(node->right);
    delete node; 
}
int main() 
{
    // đọc dữ liệu từ file input
    freopen("input.txt", "r", stdin);
    vector<int> a(MAX);
    for (int i = 0; i < 10; ++i)
    {
        Node *root = NULL;
        for (int j = 0; j < MAX; ++j)
        {
            cin>>a[j];
            root = insertNode(root,a[j]);
        }
        cout<<root->height<<endl;
        releaseMemory(root);
    }
    return 0;
}