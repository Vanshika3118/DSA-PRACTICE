#include <bits/stdc++.h>
using namespace std;

// Define the structure of a node
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// Inorder traversal (iterative)
vector<int> inorderTraversal(Node* root) {
    vector<int> result;
    stack<Node*> st;
    Node* node = root;
    while (true) {
        if (node != NULL) {
            st.push(node);
            node = node->left;
        } else {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            result.push_back(node->val);
            node = node->right;
        }
    }
    return result;
}

int main() {
    // Sample Tree:
    //       1
    //        \
    //         2
    //        /
    //       3

    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->left = new Node(3);

    vector<int> result = inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
