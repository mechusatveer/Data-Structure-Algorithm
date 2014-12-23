
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
