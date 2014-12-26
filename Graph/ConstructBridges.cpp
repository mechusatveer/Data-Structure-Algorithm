/*
A River that cuts through a set of cities above and below it.
Each city above the river is matched with a city below the river.
Construct as many Non-Crossing Bridges as possible.
Input:
Above Bank >> 7 4 3 6 2 1 5
Below Bank >> 5 3 2 4 6 1 7
are given in pairs: (7,5) (4,3) (3,2) (6,4) (2,6) (1,1) (5,7)
Output:
(1,1) (3,2) (4,3) (6,4) (7,5)

*/

/*

We need to apply sort on one bcoz result be same whatever we use.
*/
#include<iostream>
#include<algorithm>
using namespace std;

#define N 7
struct Pair
{
   int above;
   int below;
};

class compare
{
   public:
   bool operator()(Pair p, Pair q)
   {
      return p.above < q.above;
   }
};

int LIS(int arr[], int n)
{
   int *lis = new int[n];

   for(int i = 0; i < n; i++)
   {
      lis[i] = 1;
   }

   int max = 1;
   int max_index = 0;
   for(int i = 1; i < n; i++)
   {
       for(int j = 0; j < i; j++)
       {
          if(arr[j] < arr[i] && (lis[j]+1) > lis[i])
          {
              lis[i] = lis[j]+1;
          }
       }

       if(max < lis[i])
       {
            max = lis[i];
            max_index = i;
       }
   }

   cout<<arr[max_index]<<"  ";
   int x = max_index-1;
   while(x >= 0)
   {
      if(arr[x] < arr[max_index])
      {
         cout<<arr[x]<<"  ";
         max_index = x;
      }
      x--;
   }
   cout<<endl;
   return max;
}
int main()
{
   Pair *p = new Pair[N];

   p[0].above = 7;
   p[0].below = 5;

   p[1].above = 4;
   p[1].below = 3;

   p[2].above = 3;
   p[2].below = 2;

   p[3].above = 6;
   p[3].below = 4;

   p[4].above = 2;
   p[4].below = 6;

   p[5].above = 1;
   p[5].below = 1;

   p[6].above = 5;
   p[6].below = 7;

   int *temp = new int[N];

   sort(p,p+N,compare());

   for(int i = 0; i < N; i++)
   {
      temp[i] = p[i].below;
   }

   int b = LIS(temp,N);

   cout<<b<<" "<<"bridges can be constructed"<<endl;

   return 0;
}
