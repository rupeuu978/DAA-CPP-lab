#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insertion: Recursively find correct null spot
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Helper: Find minimum node (used for deletion)
Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// Deletion: Handles leaf, one child, and two children scenarios
Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        // Node with one or no child
        if (!root->left) return root->right;
        else if (!root->right) return root->left;
        // Node with two children: Replace with inorder successor
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal to verify result
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30); insert(root, 70);
    deleteNode(root, 30);
    inorder(root); // Outputs: 20 40 50 70
    return 0;
}
