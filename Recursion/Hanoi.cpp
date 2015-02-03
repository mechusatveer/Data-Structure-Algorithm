#include<iostream>

using namespace std;

void Hanoi_1(char source, char mid, char dest, int n)
{
   if(n == 0) return;
   if(n == 1)
   {
        cout<<"Shift "<<n<<"From "<<source<<"To "<<dest<<endl;
        return;
   }

   Hanoi(source,dest,mid,n-1);
   cout<<"Shift "<<n<<"From "<<source<<"To "<<dest<<endl;

   Hanoi(mid,dest,source,n-2);
   cout<<"Shift "<<n-1<<"From "<<mid<<"To "<<dest<<endl;

   Hanoi(source,mid,dest,n-2); // do not forget to write this mean we solving a problem with n-2 items.
}

void Hanoi_2(char source, char mid, char dest, int n)
{
   if(n == 0) return;
   if(n == 1)
   {
        cout<<"Shift "<<n<<"From "<<source<<"To "<<dest<<endl;
        return;
   }

   Hanoi(source,dest,mid,n-1);
   cout<<"Shift "<<n<<"From "<<source<<"To "<<dest<<endl;

   Hanoi(mid,source,dest,n-1);
  
}

int main()
{
   int n = 3;
   Hanoi('A','B','C',n);
   return 0;
}
