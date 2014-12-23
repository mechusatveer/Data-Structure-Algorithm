/* You are given a tree print rightmost node in each level
Print right view of a BT.
*/

void PrintRightView(Node* root, int curr_level, int &max)
{
   if(root == null) return;
   
   if(curr_level > max)
   {
      cout<<root->data<<endl;
      max = curr_level;
   }
   
   PrintRightView(root->right,curr_level+1,max);
   PrintRightView(root->left,curr_level+1,max);
}

void PrintRightViewUtil(Node* root)
{
     int curr_level = -1;
     int max = 0;
     PrintRightView(root,curr_level,max);
}

int main()
{
    PrintRightViewUtil(root);
}
