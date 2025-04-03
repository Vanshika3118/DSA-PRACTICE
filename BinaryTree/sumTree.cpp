// A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

// Helper function to calculate sum of tree nodes
int sum(Node *root)
{
  if (root == NULL)
    return 0; // Base case: sum of empty tree is 0
  return root->data + sum(root->left) + sum(root->right);
}

// Function to check if a tree is a Sum Tree
bool isSumTree(Node *root)
{
  if (!root || (!root->left && !root->right))
    return true; // Base case: Empty tree or leaf node is a Sum Tree

  int leftSum = sum(root->left);
  int rightSum = sum(root->right);

  if (root->data == leftSum + rightSum &&
      isSumTree(root->left) &&
      isSumTree(root->right))
    return true;

  return false;
}

// Driver code
int main()
{
  Node *root = new Node(26);
  root->left = new Node(10);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(6);
  root->right->right = new Node(3);

  if (isSumTree(root))
    cout << "The given tree is a Sum Tree.\n";
  else
    cout << "The given tree is NOT a Sum Tree.\n";

  return 0;
}
