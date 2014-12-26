/*
    We cannot use stack here
    We can use queue here 
    But in palce of queue we can use a array also
    Below problem use array of same size
*/


#include<iostream>

using namespace std;

int Max(int i, int j)
{
    if(i > j) return i;
    return j;
}
int Max_HistogramArea(int arr[], int n)
{
    int *temp = new int[n];
    int index = 0;
    temp[index++] = arr[0];
    int max_area = 0;
    for(int i = 1; i < n; i++)
    {
       if(arr[i] >= temp[index-1])
       {
           temp[index++] = arr[i];
       }
       else
       {
           index--;
           int count = 0;
           int lastItem = 0;
           while(index >= 0 && arr[i] < temp[index])
           {
              lastItem = temp[index];
              count++;
              index--;
           }
           if(max_area < lastItem*count)
           {
               max_area = lastItem*count;
           }
           index++;
           while(count--)
           {
               temp[index++] = arr[i];
           }

           temp[index++] = arr[i];
       }
    }

    for(int i = 0; i < index; i++)
    {
        max_area = Max(max_area,temp[i]*(index-i));
    }
    return max_area;
}

int main()
{
   int arr[] = {2,4,6,7,1,8,20,21,9,10,11};
   cout<<Max_HistogramArea(arr,11);
   return 0;
}
