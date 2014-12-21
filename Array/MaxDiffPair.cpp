//Print Max Diff Pair


#include<iostream>

using namespace std;

int Min(int i, int j)
{
    if(i < j) return i;
    return j;
}

int Max(int i, int j)
{
    if(i > j) return i;
    return j;
}
int PrintPair(int arr[], int n)
{
   int* temp_min = new int[n];//This array hold min item upto here
   int* temp_max = new int[n];//This array hold max item upto here

   temp_min[0] = arr[0];
   temp_max[0] = arr[0];
   
   int min = temp[0];
   int max = temp[0];
   
   for(int i = 1; i < n-1; i++)
   {
       min = Min(min,arr[i]);
       max = Max(max,arr[i]);
       temp_min[i] = min;
       temp_max[i] = max;
   }

   min = arr[n-1];
   max = arr[n-1];
   
   int max_Diff = 0;
   
   int curr_Diff = 0;
   for(int i = n-2; i >= 0; --i)
   {
      curr_Diff = Max(max - temp_min[i], min - temp_max[i]);
      if(curr_Diff > max_Diff) max_Diff = curr_Diff;
      
      max = Max(max,arr[i]);
      min = Min(min,arr[i]);
   }

   delete []temp;
   temp = NULL;
   return max_Diff;
}

int main()
{
   int arr[] = {7,9,5,6,3,2};
   PrintPair(arr,sizeof(arr)/sizeof(arr[0]));
}
