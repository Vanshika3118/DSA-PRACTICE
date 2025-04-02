// Calculate the diameter of Binary tree
// TC: O(N2)

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

int height(Node* node) {
  if(node==NULL)
  return -1; // 0 for nodes
  return max(height(node->left),height(node->right))+1;
}

int diameter(Node* root)
{
  if(root==NULL)
        return 0;
        int op1=diameter(root->left); // option 1 is it may be on left side
        int op2=diameter(root->right); // option2 is it may be on right side
        int op3=height(root->left)+height(root->right)+2; // option 3 is it may take both sides
        
        return max(op1,max(op2,op3));
}
int main()
{
  Node* root=NULL;
  createBinaryTree(root);
  cout<<diameter(root);
  return 0;
}