/*
Input 3 output 4
Input 4 output 5

                 0
            1---------->2
       3------->4---NULL---->5

we have parent link
*/

#include<iostream>
using namespace std;


struct Node {
  int val;
  Node *left;
  Node *right;
  Node *parent;

  Node(int v) : val(v), left(NULL), right(NULL), parent(NULL) {}
};


Node *FindNeighbor( Node *node, int level )
{

    if( node == NULL ) return NULL;
    if( level == 0 )  return node;

    Node *left = FindNeighbor(node->left,level+1);
    //always return left child at first such that this node is the immediate right neighbor
    if( left )
    {
		return left;
	}
    else
    {
		return FindNeighbor(node->right,level+1);
	}
}

Node *RightNeighbor(Node *node )
{

    Node *parent = node->parent;
    //records the level of node in order to find the same level neighbor
    int level = 0;
    while (parent)
    {
        //find the lowest parent for node and the its immediate right neighbor
        //do till node is not left child of parent
        //   parent
        //  /
        // node
        //if this happen stop it
        while( parent && parent->left != node)
        {
            node = parent;
            parent = node->parent;
            level--;
        }

        if( parent == NULL )
            return NULL;
        //find the neighbor node with level 0
        Node *local = FindNeighbor( parent->right, level);

        if(local)
        {
            return local;
		}
        else
        {
            node = parent;
            parent = node->parent;
            level--;
        }
    }
    return NULL;
}

int main(){

    Node *root = new Node(0);
    root->left = new Node(1);
    root->left->parent = root;
    root->right = new Node(2);
    root->right->parent = root;
    root->left->left = new Node(3);
    root->left->left->parent = root->left;
    root->left->right = new Node(4);
    root->left->right->parent = root->left;
    root->right->right = new Node(5);
    root->right->right->parent = root->right;
    Node *p1 = root->left->left; //3
    Node *p2 = root->left->right; //4
    cout<<RightNeighbor(p1)->val<<endl;
    cout<<RightNeighbor(p2)->val<<endl;
    return 0;
}


