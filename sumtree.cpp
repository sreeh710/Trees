#include<iostream>
using namespace std;

struct Node
{
int data;
Node *left;
Node *right;       
};
struct Node *Node1(int item)
{
    Node *temp =  new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(Node *root)
{
     if(root!=NULL)
     {
     inorder(root->left);
     cout<<root->data<<"\t";
     inorder(root->right);              
     }
}
void sumtree(Node *root,int * sum)
{
     if(root!=NULL)
     {
     sumtree(root->right,sum);
     *sum=*sum+root->data;
     cout<<*sum-root->data<<"\t";
     root->data=*sum-root->data;
     sumtree(root->left,sum);
     }
}

int main()
{
   
    struct Node *root = Node1(11);
    root->left = Node1(2);
    root->right = Node1(29);
    root->left->left = Node1(1);
    root->left->right = Node1(7);
    root->right->left = Node1(15);
    root->right->right = Node1(40);
    root->right->right->left = Node1(35); 
    cout<<"Inorder traversal";
    inorder(root);
    cout<<"Sumtree\n";
    int sum=0;
    sumtree(root,&sum);

int x;
cin>>x;
    return 0;
}
