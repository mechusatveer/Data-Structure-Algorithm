/*
Print all Keys between given to keys
Do this for BT/BST
K1 && K2 can present in tree or not
if K1 > K2 return without doing anything
You can ask this from interviewer also what to do when K1 > K2
It can be simply we return or we swap k1 & k2 and do this.
What order keys should get printed this we can ask from interviewer
Based on that we can decide which logic we use
if we want all keys get printed in sorted order we need to use InOrder ways.

GOOD THING
if(root->data > k1)
Call Left

if(root->data < k2)
Call Right

Do not do like where = also used its call one extra function call wasting time
so do not use >= or <=

BAD THING
if(root->data >= k1)
Call Left

if(root->data <= k2)
Call Right

If its writtne print range between k1 & k2 but do not k1 & k2 the while print login u can handle it
if(root->data < k1 && root->data < k2)
cout<<root->data

*/
 
/*Base cases
1. k1 > k2
2. Tree is empty
3. k1 & k2 not included in range
4. Which order we need to print keys.
*/
#include<iostream>
 
using namespace std;
 
struct Node
{
    int data;
    Node *left;
    Node *right;
 
    Node(int d,Node* lft = NULL, Node* rgt = NULL)
    {
        data = d;
        left = lft;
        right = rgt;
    }
};
 
void Insert(Node **root, int data)
{
    if(*root == NULL)
    {
        *root = new Node(data,NULL,NULL);
    }
    else
    {
        Node* temp = *root;
        if(temp->data > data)
        {
            Insert(&(temp->left),data);
        }
        else if(temp->data < data)
        {
             Insert(&(temp->right),data);
        }
        else
        {
            //reject this data
        }
    }
}
 
//This Logic will be valid for BT & BST both
//In place of pre order like logic we can use here Inorder/Post Order also.
//For BST this logic can be optmized
//Some of calls we can skip for BST so we need to improved logic for BST
//For BT this is only case to solve this problem
void PrintRange(Node* root, int k1, int k2)
{
    if(root == NULL)
    {
        return;
    }
 
    if(root->data >= k1 && root->data <= k2)
    {
        cout<<root->data<<"  ";
    }
 
    PrintRange(root->left,k1,k2);
    PrintRange(root->right,k1,k2);
}
//This is valid only for BST
//This prints Range nodes in InOrder foramt
//We cannot skip check with k1 && k2 while printing node
 
void PrintRangeBST_InOrder(Node* root, int k1, int k2)
{
    if(root == NULL)
    {
        return;
    }
 
    if(root->data > k1)
    PrintRangeBST_InOrder(root->left,k1,k2);
 
    if(root->data >= k1 && root->data <= k2)
    {
        cout<<root->data<<"  ";
    }
 
    if(root->data < k2)
    PrintRangeBST_InOrder(root->right,k1,k2);
}
 
void PrintRangeBST_PreOrder(Node* root, int k1, int k2)
{
    if(root == NULL)
    {
        return;
    }
 
    if(root->data >= k1 && root->data <= k2)
    {
        cout<<root->data<<"  ";
    }
 
    if(root->data > k1)
    PrintRangeBST_PreOrder(root->left,k1,k2);
 
    if(root->data < k2)
    PrintRangeBST_PreOrder(root->right,k1,k2);
}
 
void PrintRangeBST_PostOrder(Node* root, int k1, int k2)
{
    if(root == NULL)
    {
        return;
    }
 
    if(root->data > k1)
    PrintRangeBST_PostOrder(root->left,k1,k2);
 
    if(root->data < k2)
    PrintRangeBST_PostOrder(root->right,k1,k2);
 
    if(root->data >= k1 && root->data <= k2)
    {
        cout<<root->data<<"  ";
    }
}
int main()
{
    Node* root = NULL;
    Insert(&root,10);
    Insert(&root,5);
    Insert(&root,15);
    Insert(&root,3);
    Insert(&root,8);
    Insert(&root,13);
    Insert(&root,18);
    Insert(&root,1);
    Insert(&root,4);
    Insert(&root,7);
    Insert(&root,9);
    Insert(&root,11);
    Insert(&root,14);
    Insert(&root,17);
    Insert(&root,19);
    Insert(&root,2);
    Insert(&root,6);
 
    PrintRange(root,6,19);
    cout<<endl;
    PrintRangeBST_InOrder(root,6,19);
    cout<<endl;
    PrintRangeBST_PreOrder(root,6,19);
    cout<<endl;
    PrintRangeBST_PostOrder(root,6,19);
    cout<<endl;
    return 0;
}
