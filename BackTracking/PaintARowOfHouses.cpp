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

struct ColorCostPair
{
   int cIndex;
   int cost;
}
struct House
{
   int colorIndex;
   vector<ColorCostPair> cost;  //cost of paint corresponding to k colors
};

class Compare
{
   public:
   bool operator()(ColorCostPair &p1, ColorCostPair &p2)
   {
      if(p1.cost <= p2.cost) return true;
      
      return false;
   }
};

bool PaintHouseUtil(House arr[], int index, int n,int k, int &curr_cost)
{
   if(index == n) return true;
   
   for(int c = 0; c < k; c++)
   {
      if(arr[index-1].cIndex == arr[index].cost[c].colorIndex) continue;
      
      arr[index].cIndex = arr[index].cost[c].colorIndex;
      curr_cost = arr[index].cost[c].cost;
      if(PaintHouseUtil(arr,index+1,n,k,curr_cost))
      {
         return true;
      }
      
      curr_cost = curr_cost - arr[index].cost[c].cost;
   }
   
   return false;
}

bool PaintHouse(House arr[], int n, int k)
{
   //Cannot be painted
   if(k ==1 && n > 1) return false;
   
   //Every house have a sorted vector of cost based
   for(int i = 0; i < n; i++)
   {
      sort(arr[i].cost,arr[i].cost + k,Compare);
   }
   
   int result[n];
   
   int min_cost = INT_MAX;
   int curr_cost = 0;
   for(int i = 0; i < k; i++)
   {
      curr_cost = arr[0].cost[i].cost;
      arr[0].colorIndex = arr[0].cost[i].cIndex;
      
      if(PaintHouseUtil(arr,1,n,k,curr_cost))
      {
         if(curr_cost < min_cost)
         {
            min_cost = curr_cost;
            for(int p = 0; p < n; p++)
            {
               result[p] = arr[p].cIndex;
            }
         }
      }
   }
   
   for(int i = 0; i < n; i++)
   {
      arr[i].cIndex = result[i];
   }
   
   return true;
