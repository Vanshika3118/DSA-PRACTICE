//Find the height of Binary Tree
// TC: O(N)  SC : O(h)

#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int d)
  {
    this->data=d;
    left=NULL;
    right=NULL;
  }
};

void createBinaryTree(Node*& root)
{
  cout<<"Enter the data: "<<endl;
  int data;
  cin>>data;
  root=new Node(data);

  if(data==-1)
    return;

  cout<<"Enter the data for inserting in left of "<<data<<endl;
  createBinaryTree(root->left);
  cout<<"Enter the data for inserting in right of "<<data<<endl;
  createBinaryTree(root->right);
}

int heightOfBinaryTree(Node* root)
{
  if(root==NULL)
  return -1; // if edges : -1 and if nodes : 0
  return max(heightOfBinaryTree(root->left),heightOfBinaryTree(root->right))+1;
}
int main()
{
  Node* root=NULL;
  createBinaryTree(root);
  cout<<heightOfBinaryTree(root);
}