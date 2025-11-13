#include <iostream>
using namespace std;

struct Node {
    int roll;
    Node* left;
    Node* right;
    int height;
    Node(int val) : roll(val), left(NULL), right(NULL), height(1) {}
};

int height(Node* n) {
    return (n == NULL) ? 0 : n->height;
}

int getBalance(Node* n) {
    if (!n) return 0;
    return height(n->left) - height(n->right);
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

Node* insert(Node* root, int roll) {
    if (!root) return new Node(roll);
    if (roll < root->roll)
        root->left = insert(root->left, roll);
    else if (roll > root->roll)
        root->right = insert(root->right, roll);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // Left rotation cases
    if (balance < -1 && roll > root->right->roll)
        return leftRotate(root);

    // Right rotation cases
    if (balance > 1 && roll < root->left->roll)
        return rightRotate(root);

    return root;
}

int main() {
    Node* root = new Node(10);
    root->right = new Node(20);
    root->right->right = new Node(30);
    root->right->right->right = new Node(40);
    root->right->right->right->right = new Node(50);

    cout << "Before insertion: Height = " << height(root) << endl;

    root = insert(root, 15);

    cout << "After inserting roll no. 15, Height = " << height(root) << endl;
}
