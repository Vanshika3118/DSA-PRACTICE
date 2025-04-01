//create a binary tree and print using level order , inorder , preorder and postorder traversal with recursion
#include <iostream>
#include <queue>
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

Node *buildTree(Node *root)
{
  cout << "Enter the data: " << endl;
  int data;
  cin >> data;
  root = new Node(data);

  if (data == -1)
    return NULL;

  cout << "Enter the data for inserting in left of " << data << endl;
  root->left = buildTree(root->left);
  cout << "Enter the data for inserting in right of " << data << endl;
  root->right = buildTree(root->right);

  return root;
}

void levelOrderTraversal(Node *root)
{
  queue<Node *> q;
  q.push(root);
  q.push(NULL); // to mark the end of the current level

  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();

    if (temp == NULL)
    {
      cout << endl; // new line for the next level
      if (!q.empty())
        q.push(NULL); // push NULL to mark the end of the next level
    }
    else
    {
      cout << temp->data << " ";
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
  }
}

void inOrder(Node *root)
{
  if (root == NULL)
    return;

  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void preOrder(Node *root)
{
  if (root == NULL)
    return;

  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(Node *root)
{
  if (root == NULL)
    return;

  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}
int main()
{
  Node *root = NULL;

  // creating a tree
  root = buildTree(root);
  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  // levelorder traversal of the tree
  cout << "Level order traversal of the tree is: " << endl;
  levelOrderTraversal(root);

  cout << "Inorder traversal of the tree is: " << endl;
  inOrder(root);
  cout << endl;

  cout << "Preorder traversal of the tree is: " << endl;
  preOrder(root);
  cout << endl;

  cout << "Postorder traversal of the tree is: " << endl;
  postOrder(root);
  cout << endl;
}