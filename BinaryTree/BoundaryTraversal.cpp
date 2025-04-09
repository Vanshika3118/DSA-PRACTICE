// print left part except leaf node
// print leaf nodes
// print right part except leaf node (reverse order)

#include <iostream>
#include <vector>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int isleaf(Node* root) {
        return (root->left == NULL && root->right == NULL);
    }

    void left(Node* root, vector<int>& res) {
        Node* temp = root->left;
        while (temp) {
            if (!isleaf(temp)) {
                res.push_back(temp->data);
            }
            if (temp->left) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
    }

    void right(Node* root, vector<int>& res) {
        Node* temp = root->right;
        vector<int> v;
        while (temp) {
            if (!isleaf(temp)) {
                v.push_back(temp->data);
            }
            if (temp->right) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
        res.insert(res.end(), v.rbegin(), v.rend());
    }

    void leaf(Node* root, vector<int>& res) {
        if (isleaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) leaf(root->left, res);
        if (root->right) leaf(root->right, res);
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> res;
        if (root == NULL) return res;
        if (!isleaf(root)) res.push_back(root->data);
        left(root, res);
        leaf(root, res);
        right(root, res);
        return res;
    }
};

// Main function
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left->left = new Node(10);
    root->right->left->right = new Node(11);

    Solution sol;
    vector<int> boundary = sol.boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int num : boundary) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
// Output: Boundary Traversal: 1 2 4 8 9 10 11 3 7
// Time Complexity: O(n) where n is the number of nodes in the tree