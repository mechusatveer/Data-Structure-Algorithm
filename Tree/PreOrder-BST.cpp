#include<iostream>

using namespace std;

struct Node
{
   int data;
   Node* left;
   Node* right;
   Node(int d)
   {
      data = d;
      left = NULL;
      right = NULL;
   }
};

//index should be used as referance
Node* PreOrder(int arr[],int &index, int start, int end, int size)
{
   if(start > end || index >= size)
    return NULL;

   Node* temp = new Node(arr[index]);


   if(start == end) return temp;

   int i = index;

   while(arr[i] < arr[index])
    i++;
   index++;
   temp->left = PreOrder(arr,index,i-1);
   temp->right = PreOrder(arr,i,end);

}
