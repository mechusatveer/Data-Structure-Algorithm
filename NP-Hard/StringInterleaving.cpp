#include<iostream>

using namespace std;

void Int(string str1,string str2,unsigned int i,unsigned int j,char* str,unsigned int index)
{
   if(index == (str1.size() + str2.size()))
   {
      cout<<str<<endl;
      return;
   }

   if(i < str1.size())
   {
      str[index] = str1[i];
      Int(str1,str2,i+1,j,str,index+1);
   }

   if(j < str2.size())
   {
      str[index] = str2[j];
      Int(str1,str2,i,j+1,str,index+1);
   }
}

int main()
{
   string str1("ab");
   string str2("c");
   char* ptr = new char[str1.size() + str2.size() + 1];
   ptr[str1.size() + str2.size()] = '\0';
   Int(str1,str2,0,0,ptr,0);
   return 0;
}
