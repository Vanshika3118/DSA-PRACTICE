#include <iostream>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to check if S is identical to T
    bool isIdentical(Node* T, Node* S) {
        if (T == NULL && S == NULL)
            return true;
        if (T == NULL || S == NULL)
            return false;

        return (T->data == S->data) &&
               isIdentical(T->left, S->left) &&
               isIdentical(T->right, S->right);
    }

    // Function to check if S is a subtree of T
    bool isSubTree(Node* T, Node* S) {
        if (S == NULL)
            return true;
        if (T == NULL)
            return false;

        if (isIdentical(T, S))
            return true;

        return isSubTree(T->left, S) || isSubTree(T->right, S);
    }
};

// Utility function to build and test trees
int main() {
    /*
        Tree T:
                1
               / \
              2   3
             / \
            4   5

        Tree S:
              2
             / \
            4   5
    */

    // Construct Tree T
    Node* T = new Node(1);
    T->left = new Node(2);
    T->right = new Node(3);
    T->left->left = new Node(4);
    T->left->right = new Node(5);

    // Construct Tree S
    Node* S = new Node(2);
    S->left = new Node(4);
    S->right = new Node(5);

    Solution sol;
    if (sol.isSubTree(T, S))
        cout << "S is a subtree of T" << endl;
    else
        cout << "S is NOT a subtree of T" << endl;

    return 0;
}
