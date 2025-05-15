#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition of Node
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
    // Function to return a list of nodes visible from the left view
    vector<int> leftView(Node* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* temp = q.front();
                q.pop();

                // First node of this level
                if (i == 0)
                    ans.push_back(temp->data);

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
        return ans;
    }
};

// Helper function to build a sample tree
Node* buildSampleTree() {
    // Example tree:
    //         1
    //       /   \
    //      2     3
    //     / \     \
    //    4   5     6
    //             /
    //            7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    return root;
}

int main() {
    Node* root = buildSampleTree();
    Solution obj;
    vector<int> result = obj.leftView(root);

    cout << "Left View of Binary Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
