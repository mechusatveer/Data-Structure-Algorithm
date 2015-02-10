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



Node* PreOrder(int arr[],int &index, int min, int max, int size)
{
   if(index >= size)
    return NULL;

   if(arr[index > min && arr[index] < max)
   {
       Node* temp = new Node(arr[index]);
       index++;
       temp->left = PreOrder(arr,index,min,arr[index-1],size);
       temp->right = PreOrder(arr,index,arr[index-1],max,size);
       return temp;
   }
   
   return NULL;
}
