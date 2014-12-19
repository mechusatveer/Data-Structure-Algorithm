/*

You are given a array and you need to print all triplets which follow this property A^2 + B^2 = C^2

We want all unique triplets.

3,4,5 & 4,3,5 both are same bcoz here only A & B swapped so print only once these type triplets.

1) Array can have duplicates
   5,3,2,4,3,2,4 ==>2,3,4 are duplicate
2) Array have all positive no
3) Array have all negative no
4) Array have +- both

Note:- This problem become interesting when we have duplicates and +- mix.

*/
 
/* First goal remove duplicate bcoz we want only unique triplets

Like above ex after removing duplicates array will be - 5,3,2,4 all duplicates removed
What type sort we looking here, since there are positive negative so we do based on magnitude

4,2,3,-3,-2,-6,-4 ==>-2,2,-3,3,-4,4,-6
Sorting done based on magnitude and - + order.

After doing this you should remove duplicates

Take a case to make it more clear

Ex- 5,2,-1,0,3,-2,-1,-5,5,3,-3,1

Step1 - Sort based on magnitude
0,-1,-1,1,-2,2,-3,3,3,-5,5,5
Step 2- Rremove duplicate
0,-1,1,-2,2,-3,3,-5,5 =>All duplicates removed

To sort based on magnitude we can use functror and that we apply with sort algo or we can write our custom sort algo also.

class Compare
{
   public:
   bool operator()(int i, int j)
   {
     if(abs(i) == abs(j))
     {
        if(i < j) return true;
     }
     else
     {
        if(abs(i) < abs(j))
        {
           return true;
        }
     }
      return false;
   }
}

sort(arr,arr+N,Compare);

Algorithm not accept as a function it need a functor only so if u do

bool Compare(int i, int j)
{

}
This not  be good give compile time error even

After doing this we done then it become so simple

for(int c = n-1; c >= 2; --c)
{
   int a = 0;
   int b = c-1;
   while(a<b)
   {
      if(arr[a]*arr[a] + arr[b]*arr[b] == arr[c]*arr[c])
      {
         cout<<arr[a]<<" "<<arr[b]<<" "<<arr[c]<<endl;
      }
      else if(arr[a]*arr[a] + arr[b]*arr[b] < arr[c]*arr[c])
      {
         a++;
      }
      else
      {
        b++;
      }
   }
}
*/
 
/*
  what if 3,4,5 & 4,3,5 are different

  while printing a,b,c
  Do two prints
  1. arr[a],arr[b],arr[c]
  2. arr[b],arr[a],arr[c]
  Nothing more to do

*/
 
#include<iostream>
#include<algorithm>
 
using namespace std;
 
class compare
{
   private:
   int abs(int i)
   {
      if(i >= 0) return i;
      return -1*i;
   }
 
   public:
   bool operator()(int i, int j)
   {
     if(abs(i) == abs(j))
     {
        if(i < j) return true;
     }
     else
     {
        if(abs(i) < abs(j))
        {
           return true;
        }
     }
      return false;
   }
};
 
//Do not forget to return last index+1 so this j be new n
int RemoveDuplicates(int arr[], int n)
{
   int j = 1;
   int prev = arr[0];
   for(int i = 1; i < n; i++)
   {
      if(prev == arr[i]) continue;
      else
      {
        arr[j++] = arr[i];
        prev = arr[i];
      }
   }
   return j;
}
void PrintTriplets(int arr[], int n)
{
   sort(arr,arr+n,compare());
   n = RemoveDuplicates(arr,n);
 
   for(int c = n-1; c >= 2; --c)
   {
       int a = 0;
       int b = c-1;
       while(a<b)
       {
          if((arr[a]*arr[a] + arr[b]*arr[b]) == (arr[c]*arr[c]))
          {
             //cout<<arr[a]<<" "<<arr[b]<<" "<<arr[c]<<endl;
             cout<<arr[a]<<" "<<arr[b]<<" "<<arr[c]<<endl;
             cout<<arr[b]<<" "<<arr[a]<<" "<<arr[c]<<endl;
             a++;
             b--;
          }
          else if(arr[a]*arr[a] + arr[b]*arr[b] < arr[c]*arr[c])
          {
             a++;
          }
          else
          {
            b++;
          }
       }
   }
 
}
int main()
{
    //int arr[] = {5,4,2,-1,0,3,-2,-1,-4,-5,5,3,-3,1,4,12,13,-13,-12};
    int arr[] = {3,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    PrintTriplets(arr,n);
    return 0;
}
