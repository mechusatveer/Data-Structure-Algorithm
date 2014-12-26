
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

void BSTDLL(Node* root,Node **head)
{
    if(root == NULL) return;

    BSTDLL(root->right,head);


    if(*head == NULL)
    {
          *head = root;
          (*head)->left = NULL;
          (*head)->right = NULL;
    }
    else
    {
        (*head)->left = root;
        root->right = (*head);
        (*head) = (*head)->left;
    }

    BSTDLL(root->left,head);
}

void BSTDLLUtil(Node **root)
{
    Node *head = NULL;
    BSTDLL(*root,&head);
    head->left = NULL;
    *root = head;
}

Node* LeadDLL(Node *root,Node **head)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->left == NULL && root->right == NULL)
    {
        if(*head == NULL)
        {
            *head = root;
        }
        else
        {
           (*head)->left = root;
           root->right = *head;
           (*head) = (*head)->left;
        }
        return NULL;
    }


    root->right = LeadDLL(root->right,head);
    root->left = LeadDLL(root->left,head);
    return root;
}
void LeadDLLUtil(Node** root,Node **head)
{
    *root = LeadDLL(*root,head);
}

void Inorder(Node *root)
{
  if(root == NULL) return;

  Inorder(root->left);
  cout<<root->data<<"  ";
  Inorder(root->right);
}

int main()
{
    Node* root = NULL;
    Insert(&root,12);
    Insert(&root,7);
    Insert(&root,15);
    Insert(&root,6);
    Insert(&root,8);
    Insert(&root,13);
    /*
    BSTDLLUtil(&root);

    while(root != NULL)
    {
       cout<<root->data<<"  ";
       root = root->right;
    }
    */

    Node* head = NULL;

    LeadDLLUtil(&root,&head);

    while(head != NULL)
    {
       cout<<head->data<<"  ";
       head = head->right;
    }
    cout<<"Tree "<<endl;
    Inorder(root);

    return 0;
}
