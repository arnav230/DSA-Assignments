#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create(int x) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

struct node* insert(struct node* root, int x) {
    if (root == NULL) return create(x);
    if (x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

struct node* search_rec(struct node* root, int x) {
    if (root == NULL || root->data == x) return root;
    if (x < root->data) return search_rec(root->left, x);
    return search_rec(root->right, x);
}

struct node* search_nonrec(struct node* root, int x) {
    while (root != NULL && root->data != x) {
        if (x < root->data) root = root->left;
        else root = root->right;
    }
    return root;
}

struct node* max_node(struct node* root) {
    while (root && root->right) root = root->right;
    return root;
}

struct node* min_node(struct node* root) {
    while (root && root->left) root = root->left;
    return root;
}

struct node* inorder_successor(struct node* root, int x) {
    struct node* curr = search_rec(root, x);
    if (curr == NULL) return NULL;
    if (curr->right) return min_node(curr->right);
    struct node* succ = NULL;
    while (root) {
        if (x < root->data) {
            succ = root;
            root = root->left;
        } else if (x > root->data) root = root->right;
        else break;
    }
    return succ;
}

struct node* inorder_predecessor(struct node* root, int x) {
    struct node* curr = search_rec(root, x);
    if (curr == NULL) return NULL;
    if (curr->left) return max_node(curr->left);
    struct node* pred = NULL;
    while (root) {
        if (x > root->data) {
            pred = root;
            root = root->right;
        } else if (x < root->data) root = root->left;
        else break;
    }
    return pred;
}

int main() {
    struct node* root = NULL;
    int n, x, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    scanf("%d", &x);
    struct node* s1 = search_rec(root, x);
    struct node* s2 = search_nonrec(root, x);
    struct node* mx = max_node(root);
    struct node* mn = min_node(root);
    struct node* succ = inorder_successor(root, x);
    struct node* pred = inorder_predecessor(root, x);

    if (s1) printf("SR %d\n", s1->data); else printf("SR -1\n");
    if (s2) printf("SNR %d\n", s2->data); else printf("SNR -1\n");
    if (mx) printf("MAX %d\n", mx->data);
    if (mn) printf("MIN %d\n", mn->data);
    if (succ) printf("SUCC %d\n", succ->data); else printf("SUCC -1\n");
    if (pred) printf("PRED %d\n", pred->data); else printf("PRED -1\n");

    return 0;
}
