
//check at current node 
//set boundry for left side
//set boundry for right side
//iterate for left & right side

int isBSTUtil(struct node* node, int min, int max) 
{ 
 
  if (node==NULL) 
     return 1;

  if (node->data < min || node->data > max) 
     return 0; 

  return
    isBSTUtil(node->left, min, node->data-1) &&  // Allow only distinct values
    isBSTUtil(node->right, node->data+1, max);  // Allow only distinct values
} 

bool isBSTUtil(Node* root, int &max, int &min)
{
     if(root == NULL)
     {
        max = INT_MIN;
        min = INT_MAX;
        return true;
     }
     
     if(root->left == NULL && root->right == NULL)
     {
        max = root->data;
        min = root->data;
        return true;
     }
     
     int max_right = 0;
     int min_left = 0;
     bool f1 = isBSTUtil(root->left,max_right,min_left);
     bool f2 = isBSTUtil(root->left,max_right,min_left);
     
     if(f1 == false || f2 == false) return false;
     
     if(root->data < min_left || root->data > max_right)
     return false;
 
     max = Max(root->data,max_right);
     min = Min(root->data,min_left);
    
     return true;
}

bool isBSTUtil(Node* root, int &max, int &min)
{
     if(root == NULL)
     {
        max = INT_MIN;
        min = INT_MAX;
        return true;
     }
     
     if(root->left == NULL && root->right == NULL)
     {
        max = root->data;
        min = root->data;
        return true;
     }
     
     int max_right = 0;
     int min_right = 0;
     int max_left = 0;
     int min_left = 0;
     bool f1 = isBSTUtil(root->left,max_left,min_left);
     bool f2 = isBSTUtil(root->left,max_right,min_right);
     
     if(f1 == false || f2 == false) return false;
     
     if(root->data < min_left || root->data > max_right)
     return false;
 
     max = Max(root->data,max_right);
     min = Min(root->data,min_left);
    
     return true;
}

