/*
MINIMUM COST FOR PAINTING A ROW OF HOUSES IN THREE DIFFERENT COLOURS
   
There are N houses in a row. Each house can be painted in either Red,Green or Blue colour. 
The cost of colouring each house in each of the colours is different.

Find the colour of each house such that no two adjacent house have the same colour and the total 
cost of colouring all the houses is minimum.The question intends to state that cost of painting 
any house in any colour is different, so if cost of painting House 1 in Red is say, X then the 
cost of painting House 2 in red will some other value Y. It can be considered each house has 
different dimensions and hence cost of painting in each colour is different, and the cost of paint
for each house also varies.

*/

/* 

This problem can be modelled as a “Dynamic Programming” problem, a method for efficiently solving
a broad range of search and optimization problems.

Cost[i][c] = H[c] + min(Cost[i-1][x]) x belongs to {Red, Blue, Green} x belongs to c

Cost[i][c] = ith house painted with color c then min cost of painting

struct House
{
   int colorIndex;
   vector<int> cost;  //cost of paint corresponding to k colors
};
}
int PaintHouse(House arr[], int n, int k)
{
   if(n == 1)
   {
      int min = arr[0].cost[0];
      arr[0].colorIndex = 0;
      for(x = 1; x < k; x++)
      {
         if(min > arr[0].cost[x])
         {
             min = arr[0].cost[x];
             arr[0].colorIndex = x;
         }
      }
      return min;
   }

   int Cost[n][k]; 
   
   //if first house colored with some color
   for(int i = 0; i < k; i++)
   {
      Cost[0][i] = arr[0].cost[i];
   }
   
   for(int i =1; i < n; i++)
   {
      for(int j = 0; j < k; j++) // if ith house colored with jth color
      {
         int min = INT_MAX;
         for(c = 0; c < k ; c++)
         {
            if(c == j) continue;
            
            if(min > Cost[i-1][c])
            min = Cost[i-1][c];
         }
         Cost[i][j] = arr[i].cost[j] + min;
      }
   }
   
   int result_cost = INT_MAX;
   
   for(int x = 0; x < k; x++)
   {
      if(result_cost > Cost[n-1][x])
      {
         result_cost = Cost[n-1][x];
      }
   }
   
   int index = -1;
   for(int i = n-1; i >= 0; --i)
   {
         int min_cost = INT_MAX;
         
         for(int x = 0; x < k; x++)
         {
            if(x == index) continue;
            
            if(min_cost > Cost[i][x])
            {
               min_cost = Cost[i][x];
               index = x;
            }
        }
        arr[i].colorIndex = index;
   }
   
   return result_cost;
}
