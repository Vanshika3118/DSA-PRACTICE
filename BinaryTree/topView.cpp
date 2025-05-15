#include <iostream>
#include <vector>
#include <map>
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
    // Function to return a list of nodes visible from the top view
    vector<int> topView(Node* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;

        queue<pair<Node*, int>> q;
        map<int, int> mp;

        q.push({root, 0});

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            Node* node = temp.first;
            int line = temp.second;

            // If this line (horizontal distance) is not recorded yet
            if (mp.find(line) == mp.end()) {
                mp[line] = node->data;
            }

            if (node->left)
                q.push({node->left, line - 1});
            if (node->right)
                q.push({node->right, line + 1});
        }

        for (auto it : mp) {
            ans.push_back(it.second);
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
    //       \   / \
    //        4 5   6
    //             /
    //            7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    return root;
}

int main() {
    Node* root = buildSampleTree();
    Solution obj;
    vector<int> result = obj.topView(root);

    cout << "Top View of Binary Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
