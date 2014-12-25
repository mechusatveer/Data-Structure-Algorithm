//Print Max Diff Pair
// 1) arr[i] < arr[j] & i < j
// 2) No constraint like that 
#include<iostream>

using namespace std;

int PrintPair_1(int arr[], int n)
{
   
   int min = temp[0];
  
   int max_diff = 0;
   
   for(int i = 1; i < n; i++)
   {
       max_diff = Max(max_diff,arr[i]-min)
       min = Min(min,arr[i]);
   }
   return max_Diff;
}

int PrintPair_2(int arr[], int n)
{
   
   int min = temp[0];
   int max = temp[0];
  
   int max_diff = 0;
   
   for(int i = 1; i < n-1; i++)
   {
       max_diff = Max(max_diff,arr[i]-min);
       max_diff = Max(max_diff,max-arr[i]);
       min = Min(min,arr[i]);
       max = Max(max,arr[i]);
   }
   return max_Diff;
}
int main()
{
   int arr[] = {7,9,5,6,3,2};
   PrintPair(arr,sizeof(arr)/sizeof(arr[0]));
}
