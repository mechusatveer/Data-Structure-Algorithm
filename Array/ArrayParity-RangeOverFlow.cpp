/* We need to find out parity for an array
a1,a2,a3,a4,a5,........an

Parity of this array can be defined as

(((((a1*a2)+a3)*a4+a5)*a6+a7)*a8.....an)%2

The issue be here range overflow bcoz array size can be too long
To solve this problem we keep taking %2 and keep reducing no...

Now the problem is 

Split array in two array
ArrayOdd= have items at odd index
ArrayEven = have items at even index

There is similar problem like

We have a running stream of binary data
at any point of time we need to tell the no formed yet from this stream 
is divisble by 3 or not

11101010010110101010101011001000110111000011000101100101101000101

This also leads to range overflow but we taking %3 with final expression so 
we can keep redcuing by %3 after eac exp

num = 0;

num = (num<<1 + curr_bit)%3;

if(num%3 == 0) cout<<"Disivible";
else cout<<"Not";

*/

/*
If i have a expression like

(a+b*c-d*x+y*z)%k

to solve range overflow issue

we can take modulo k after each operator get solved

result be same in both case

(5+3*6-8*2)%3 = (5+18-16)%3 = 1

Now other way

(5+18%3 - 16%3)%3
=(5+0-1)%3 = 4%3 = 1

*/

#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    int n = sizeof(arr)/sizeof(arr[0]);

    int reven = arr[0]%2;
    int rodd = arr[1]%2;

    bool flagMultEven = true;
    bool flagMultOdd = true;

    for(int i = 0; i < n; i++)
    {
       if(i%2 == 0)
       {
          if(flagMultEven)
          {
              reven = (reven*arr[i])%2;
          }
          else
          {
              reven = (reven+arr[i])%2;
          }
          flagMultEven = !flagMultEven;
       }
       else
       {
          if(flagMultOdd)
          {
              rodd   = (rodd*arr[i])%2;
          }
          else
          {
              rodd = (rodd+arr[i])%2;
          }
          flagMultOdd = !flagMultOdd;
       }
    }

    if(reven > rodd)
    {
        cout<<"EVEN"<<endl;
    }
    else if(rodd > reven)
    {
        cout<<"ODD"<<endl;
    }
    else
    {
        cout<<"NEUTRAL"<<endl;
    }
    return 0;
}
