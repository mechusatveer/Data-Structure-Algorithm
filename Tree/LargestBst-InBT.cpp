/*
Given a binary tree, find the largest subtree which is a binary search tree. 
Here largest subtree means a subtree with largest number of nodes in it, 
including all of its descendants
*/

//result will hold the root of largest subtree and m_size will hold its size
bool LargestBST(Node* root, int &max, int &min,int &size,Node **result, int &m_size)
{
    if(root == NULL) 
    {
       max = INT_MIN;
       min = INT_MAX;
       size = 0;
       return true;
    }
    
    if(root->left == NULL && root->right == NULL)
    {
       if(m_size == 0)
       {
          m_size = 1;
          *result = root;
       }
       max = root->data;
       min = root->data;
       size = 1;
       return true;
    }

    bool f1 = LargestBST(root->left,INT_MAX,min,size,result,m_size);
    bool f2 = LargestBST(root->right,max,INT_MIN,right_min,size,result,m_size);
    
    if(f1 == false || f2 == false)
    {
       return false;
    }
    
    max = Max(max,root->data);
    min = Min(min,root->data);

        

}
