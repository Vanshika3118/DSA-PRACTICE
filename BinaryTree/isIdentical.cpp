#include <iostream>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check if two binary trees are identical
bool areIdentical(TreeNode* root1, TreeNode* root2) {
    // If both trees are empty, they are identical
    if (!root1 && !root2) return true;
    
    // If one is NULL and the other is not, they are not identical
    if (!root1 || !root2) return false;
    
    // Check if current nodes match and recursively check left and right subtrees
    return (root1->val == root2->val) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

// Driver Code
int main() {
    // Creating two identical trees
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    // Checking if the trees are identical
    if (areIdentical(tree1, tree2))
        cout << "Both trees are identical.\n";
    else
        cout << "Trees are not identical.\n";

    return 0;
}
// Output: Both trees are identical.