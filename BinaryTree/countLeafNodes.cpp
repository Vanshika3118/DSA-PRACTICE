// Counting number of Leaf Nodes in Binary Tree

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

int countLeafNodes(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  if (root->left == NULL && root->right == NULL)
  {
    return 1;
  }
  return countLeafNodes(root->left) + countLeafNodes(root->right);
}

void createTree(Node *&root)
{
  int data;
  cout << "Enter the data (-1 for no node): ";
  cin >> data;
  if (data == -1)
  {
    return;
  }
  root = new Node(data);
  cout << "Enter data for left node of " << data << endl;
  createTree(root->left);
  cout << "Enter data for right node of " << data << endl;
  createTree(root->right);
}

int main()
{
  Node *root = NULL;
  createTree(root);
  int count = 0;
  cout << "Leaf Nodes : " << countLeafNodes(root) << endl;
}