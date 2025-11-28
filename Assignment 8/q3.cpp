#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
    node(int x) : data(x), left(NULL), right(NULL) {}
};

node* insertNode(node* root, int x) {
    if (root == NULL) return new node(x);
    if (x < root->data) root->left = insertNode(root->left, x);
    else if (x > root->data) root->right = insertNode(root->right, x);
    return root;
}

node* minNode(node* root) {
    while (root && root->left) root = root->left;
    return root;
}

node* deleteNode(node* root, int x) {
    if (root == NULL) return root;
    if (x < root->data) root->left = deleteNode(root->left, x);
    else if (x > root->data) root->right = deleteNode(root->right, x);
    else {
        if (root->left == NULL) {
            node* t = root->right;
            delete root;
            return t;
        }
        else if (root->right == NULL) {
            node* t = root->left;
            delete root;
            return t;
        }
        node* t = minNode(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

int maxDepth(node* root) {
    if (root == NULL) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return (l > r ? l : r) + 1;
}

int minDepth(node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL) return minDepth(root->right) + 1;
    if (root->right == NULL) return minDepth(root->left) + 1;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    return (l < r ? l : r) + 1;
}

int main() {
    node* root = NULL;
    int n, x, d;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insertNode(root, x);
    }
    cin >> d;
    root = deleteNode(root, d);

    cout << maxDepth(root) << endl;
    cout << minDepth(root) << endl;

    return 0;
}
