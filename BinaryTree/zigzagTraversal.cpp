//Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.In zig zag traversal starting from the first level go from left to right for odd-numbered levels and right to left for even-numbered levels.

#include <bits/stdc++.h>
using namespace std;

// Definition of a Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    // Function to store the zig-zag order traversal of a tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        vector<int> res;
        if (!root) return res; // Edge case: empty tree

        queue<Node*> q;
        q.push(root);
        int level = 1;

        while (!q.empty()) {
            vector<int> ans;
            int n = q.size();
            
            for (int i = 0; i < n; i++) {
                Node* temp = q.front();
                q.pop();
                ans.push_back(temp->data);
                
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            
            // Alternate levels are reversed
            if (level % 2 == 0) {
                reverse(ans.begin(), ans.end());
            }

            // Append the elements to the final result
            res.insert(res.end(), ans.begin(), ans.end());

            level++; // Increment level
        }
        return res;
    }
};

// Function to create a binary tree from user input
Node* buildTree() {
    int val;
    cout << "Enter root node value (-1 for NULL): ";
    cin >> val;
    if (val == -1) return nullptr;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        cout << "Enter left child of " << temp->data << " (-1 for NULL): ";
        cin >> val;
        if (val != -1) {
            temp->left = new Node(val);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << " (-1 for NULL): ";
        cin >> val;
        if (val != -1) {
            temp->right = new Node(val);
            q.push(temp->right);
        }
    }
    return root;
}

// Main function
int main() {
    // Build the tree from user input
    Node* root = buildTree();
    
    // Create Solution object
    Solution sol;
    
    // Get zig-zag traversal
    vector<int> result = sol.zigZagTraversal(root);
    
    // Print the result
    cout << "Zig-Zag Traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
