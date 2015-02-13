
#include<iostream>

using namespace std;

void fun(int arr[], int i, int n)
{
   if(i == n)
   {
      int prod1 = arr[0]*arr[1]*arr[2];
      int prod2 = arr[2]*arr[3]*arr[4];
      int prod3 = arr[4]*arr[5]*arr[6];

      if(prod1 == prod2 && prod2 == prod3)
      {
         for(int x = 0; x < 7;x++) cout<<arr[x];
         cout<<endl;
      }
      return;
   }


   for(int j = i; j < n; j++)
   {
      swap(arr[i],arr[j]);
      fun(arr,i+1,n);
      swap(arr[i],arr[j]);
   }
}

int main()
{
   int arr[] = {1,2,3,4,6,8,9};
   fun(arr,0,7);
   return 0;
}
