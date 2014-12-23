
//check at current node 
//set boundry for left side
//set boundry for right side
//iterate for left & right side

/*
   isBst
   1. preorder appraoch widest range to smaller range
   2. inorder appraoch
   3. post order appraoch
*/

/* 
   base case is if root == null max = int_min   min = int_max
   
   //root->data used here to handle one child missing case
   max = Max(right_max,root->data);   for child nodes it makes max = leaf data
   min = Min(left_min,root->data);                // min = leaf data too

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

Node* Insert(Node **root, int data)
{
    if(*root == NULL)
    {
        *root = new Node(data,NULL,NULL);
        return *root;
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

//Initially
//Left Boundry = -INF = INT_MIN
//Right Boundry = INF = INT_MAX
//After processing current node
// For left subtree  -INF to curr->data-1
// For right subtree curr->data+1 to INF
bool PreOrderIsBst(Node* root, int left_b, int right_b)
{
   if(root == NULL) return true;

   if(root->data < left_b || root->data > right_b)
   {
       return false;
   }

   return PreOrderIsBst(root->left,left_b,root->data-1) && PreOrderIsBst(root->right,root->data+1,right_b);
}
bool PreOrderIsBstUtil(Node* root)
{
  return PreOrderIsBst(root,INT_MIN,INT_MAX);
}

void InOrderIsBst(Node* root, int &lastItem, bool &flag)
{
   if(root == NULL || flag == false) return;

   InOrderIsBst(root->left,lastItem,flag);

   if(root->data <= lastItem)
   {
      flag = false;
   }
   else
   {
       lastItem = root->data;
   }

   InOrderIsBst(root->right,lastItem,flag);

}
bool InOrderIsBstUtil(Node* root)
{
  bool flag = true;
  int lastItem = INT_MIN;
  InOrderIsBst(root,lastItem,flag);
  return flag;
}
int Max(int i, int j)
{
   if(i > j) return i;

   return j;
}

int Min(int i, int j)
{
    if(i < j) return i;

    return j;
}
bool PostOrderIsBst(Node* root,int &min, int &max)
{
   if(root == NULL)
   {
       max = INT_MIN;
       min = INT_MAX;
       return true;
   }

   int left_min = 0;
   int left_max = 0;

   int right_min = 0;
   int right_max = 0;

   bool f1 = PostOrderIsBst(root->left,left_min,left_max);
   bool f2 = PostOrderIsBst(root->right,right_min,right_max);

   if(f1 == false || f2 == false) return false;

   if(root->data < left_max || root->data > right_min) return false;

   //root->data used here to handle one child missing case
   max = Max(right_max,root->data);
   min = Min(left_min,root->data);
   return true;
}
bool PostOrderIsBstUtil(Node* root)
{
  int left = 0;
  int right = 0;
  return PostOrderIsBst(root,left,right);
}
int main()
{
    Node* root = NULL;
    //Positive Case

    Insert(&root,10);
    Insert(&root,5);
    Insert(&root,15);
    //Insert(&root,3);
    Node* x = Insert(&root,6);
    Node* y = Insert(&root,14);
    Insert(&root,16);

    //If you comment these then it be bst
     x->data = 11;
    //y->data = 4;

    //if(PreOrderIsBstUtil(root))
    //if(InOrderIsBstUtil(root))
    if(PostOrderIsBstUtil(root))
    {
        cout<<"Bst ";
    }
    else
    {
        cout<<"Not a Bst";
    }
    cout<<endl;
    return 0;
}
