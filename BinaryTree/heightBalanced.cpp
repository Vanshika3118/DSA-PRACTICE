// Given a binary tree, determine if it is height-balanced. A binary tree is considered height-balanced if the absolute difference in heights of the left and right subtrees is at most 1 for every node in the tree.

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
  {
    root=NULL;
    return ;
  }

  cout<<"Enter the data for inserting in left of "<<data<<endl;
  createBinaryTree(root->left);
  cout<<"Enter the data for inserting in right of "<<data<<endl;
  createBinaryTree(root->right);
}

int height(Node* root)
  {
      if(root==NULL)
      return 0;
      
      int left=height(root->left);
      int right=height(root->right);
      
      return max(left,right)+1;
  }
    bool isBalanced(Node* root) {
        // Code here
        if(root==NULL)
        return true;
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        
        if(abs(leftHeight-rightHeight)<=1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
        
        return false;
    }


int main()
{
  Node* root=NULL;
  createBinaryTree(root);
  cout<<isBalanced(root);
  return 0;
}