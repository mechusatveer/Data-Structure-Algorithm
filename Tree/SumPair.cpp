Find elements that sum to a given value in a balanced BST
Find two elements in balanced BST which sums to a given a value.
Constraints Time O(n) and space O(logn).

//Approach we want to use is we will do in order travesal from both side

//Iterative approach
//Recursive approach

void Sum(Node* root,int k)
{
     stack<Node*> q1;
     stack<Node*> q2;
     
     Node* temp1 = root;
     Node* temp2 = root;
     
     bool flag1 = true;
     bool flag2 = true;
     
     while(1)
     {
          if(flag1)
          {
              while(temp1 != null)
              {
                 q1.push(temp1);
                 q1 = q1->left;
              }
              
              if(temp1 == NULL && q1.empty() == false)
              {
                 temp1 = q1.top();
              }
          }
          
          if(flag2)
          {
              while(temp2 != null)
              {
                 q2.push(temp2);
                 q2 = q2->right;
              }
              
              if(temp2 == NULL && q2.empty() == false)
              {
                 temp2 = q2.top();
              }
          }
     
          if(temp1 == temp2) break;
          
          if(temp1->data + temp2->data == k)
          {
              cout<<temp1->data<<"  "<<temp2->data<<endl;
              break;
          }
          else if(temp1->data + temp2->data > k)
          {
             flag1 = false;
             flag2 = true;
             temp2 = temp2->left;
          }
          else
          {
             flag1 = true;
             flag2 = false;
             temp1 = temp1->right;
          }
     
     }
}


}
