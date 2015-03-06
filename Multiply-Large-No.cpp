#include<iostream>
#include<cstring>
using namespace std;

void strrev(char arr[])
{
   int n = strlen(arr);

   int l = 0;
   int r = n-1;
   while(l < r)
   {
      char temp = arr[l];
      arr[l] = arr[r];
      arr[r] = temp;
      l++;
      r--;
   }
}

int get_int(char ch)
{
    return ch - '0';
}
char *multiply(char s1[], char s2[])
 {
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int i, j, k = 0, c = 0;
    char *r = new char[(l1+l2+1)]; // add one byte for the zero terminating string
    int temp;

    strrev(s1);
    strrev(s2);
    for (i = 0;i <l1+l2; i++)
    {
        r[i] = 0 + '0';
    }

    for (i = 0; i <l1; i++)
    {
        c = 0; k = i;
        for (j = 0; j < l2; j++)
        {
            temp = get_int(s1[i]) * get_int(s2[j]);
            temp = temp + c + get_int(r[k]);
            c = temp /10;
            r[k] = temp%10 + '0';
            k++;
        }
        if (c!=0)
        { 
            r[k] = c + '0';
            k++;
        }
    }

    r[k] = '\0';
    strrev(r);

    return r;
}

int main()
{
  char arr[] = "123";
  char brr[] = "45";
  cout<<multiply(arr,brr);
  return 0;
}
