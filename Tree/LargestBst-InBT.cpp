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
    
    int size_left = 0;
    int size_right = 0;
    
    int left_max = 0;
    int right_max = 0;
    int left_min = 0;
    int right_min = 0;
    
    bool f1 = LargestBST(root->left,left_max,left_min,size_left,result,m_size);
    bool f2 = LargestBST(root->right,right_max,right_min,right_size,result,m_size);
    
    if(f1 == false || f2 == false)
    {
       return false;
    }
    
    if(root->data < left_max || root->data  > right_min)
    return false;
    
    size = size_left + size_right + 1;
    
    if(size > m_size)
    {
        m_size = size;
        *result = root;
    }
    max = Max(right_max,root->data);
    min = Min(left_min,root->data);

        
    return true;
}

Node* LargestBSTUtil(Node* root)
{
    int max = INT_MIN;
    int min = INT_MAX;
    Node *result = NULL;
    int m_size = 0;
    int size = 0;
    LargestBST(root,max,min,size,&result,m_size);
    return result;
}
