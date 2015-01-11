//Head Tail flip solution in room
//Room have many coins none of above on a coin
//u pick one coin if its tail u make it head and place back
//if its head toss it and what it come place same way
//what will be stage after 100000 iterations
// head to tail ratio i mean
#include<iostream>
 
using namespace std;
 
void fun()
{
  //Initially in the room there are 50% head 50% tail
  double fHead = 0.5;
  double fTail = 0.5;
 
  double rHead = 0;
  double rTail = 0;
 
  for(int i = 0; i < 100000; i++)
  {
      rTail =  fHead + fTail*0.5;
      rHead =  fTail*0.5;
 
      fHead = rHead;
      fTail = rTail;
  }
 
  cout<<"Head = "<<fHead<<endl;
  cout<<"Tail = "<<fTail<<endl;
 
}
 
int main()
{
   fun();
   return 0;
 
}
