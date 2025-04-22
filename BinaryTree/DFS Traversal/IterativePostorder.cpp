#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function for postorder traversal using two stacks
vector<int> postorder(Node* root) {
    vector<int> result;
    if (root == NULL) return result;

    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(root);

    while (!st1.empty()) {
        root = st1.top();
        st1.pop();
        st2.push(root);

        if (root->left != NULL) {
            st1.push(root->left);
        }
        if (root->right != NULL) {
            st1.push(root->right);
        }
    }

    while (!st2.empty()) {
        result.push_back(st2.top()->data);
        st2.pop();
    }

    return result;
}

// Main function to test postorder traversal
int main() {
    // Creating a simple binary tree
    /*
              1
             / \
            2   3
           / \   \
          4   5   6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> post = postorder(root);

    cout << "Postorder Traversal: ";
    for (int val : post) {
        cout << val << " ";
    }

    return 0;
}
