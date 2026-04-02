#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Represents a node in the 2-3 tree
struct Node {
    vector<int> keys;           // Stores 1 or 2 keys (temporarily 3 during split)
    vector<Node*> children;     // Stores 2 or 3 children (temporarily 4 during split)
    Node* parent;

    Node(Node* p = nullptr) : parent(p) {}

    bool isLeaf() const {
        return children.empty();
    }
};

class TwoThreeTree {
    Node* root;

    // Splits a node that has overflowed (3 keys)
    void split(Node* node) {
        int midKey = node->keys[1];
        
        Node* left = new Node(node->parent);
        left->keys.push_back(node->keys[0]);
        
        Node* right = new Node(node->parent);
        right->keys.push_back(node->keys[2]);

        if (!node->isLeaf()) {
            left->children = {node->children[0], node->children[1]};
            right->children = {node->children[2], node->children[3]};
            for (auto child : left->children) child->parent = left;
            for (auto child : right->children) child->parent = right;
        }

        if (!node->parent) {
            root = new Node();
            root->keys.push_back(midKey);
            root->children = {left, right};
            left->parent = right->parent = root;
        } else {
            Node* p = node->parent;
            // Insert midKey into parent
            auto it = lower_bound(p->keys.begin(), p->keys.end(), midKey);
            int index = distance(p->keys.begin(), it);
            p->keys.insert(it, midKey);
            
            // Update parent's children
            p->children.erase(p->children.begin() + index);
            p->children.insert(p->children.begin() + index, {left, right});
            
            if (p->keys.size() > 2) split(p);
        }
        delete node;
    }

public:
    TwoThreeTree() : root(nullptr) {}

    void insert(int key) {
        if (!root) {
            root = new Node();
            root->keys.push_back(key);
            return;
        }

        Node* curr = root;
        while (!curr->isLeaf()) {
            if (key < curr->keys[0]) curr = curr->children[0];
            else if (curr->keys.size() == 1 || key < curr->keys[1]) curr = curr->children[1];
            else curr = curr->children[2];
        }

        curr->keys.push_back(key);
        sort(curr->keys.begin(), curr->keys.end());
        if (curr->keys.size() > 2) split(curr);
    }

    void printInorder(Node* node) {
        if (!node) return;
        for (size_t i = 0; i < node->keys.size(); ++i) {
            if (!node->isLeaf()) printInorder(node->children[i]);
            cout << node->keys[i] << " ";
        }
        if (!node->isLeaf()) printInorder(node->children.back());
    }

    void display() {
        printInorder(root);
        cout << endl;
    }
};

int main() {
    TwoThreeTree tree;
    for (int x : {10, 20, 5, 15, 30, 25}) tree.insert(x);
    cout << "Inorder traversal: ";
    tree.display();
    return 0;
}
