#include <iostream>
using namespace std;

// Red-Black Tree Node Structure
enum Color { RED, BLACK };
struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;
    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

// Simplified Red-Black Tree Class with Insertion
class RedBlackTree {
    Node* root;
    // ... rotation methods (rotateLeft, rotateRight) ...
    // ... fixInsert method to handle recoloring and rotations ...
public:
    RedBlackTree() : root(nullptr) {}
    void insert(int data) { /* ... BST insert logic followed by fixInsert() ... */ }
};
