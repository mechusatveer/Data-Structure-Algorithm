/*

You have n words
print words line by line which follow same pattern on single line

pop aca ==>both are matched  p-->a   & o--->c
aabca & xxztx matched a-->x b-->z   c-->t

*/
/*

Logic

Find a hashcode for each word

How u do it

when a new char appear assign it to a no

abc ==>012
acad==>0102
abcd==>0123

All words which belong to same hashcode collect in a vector

we can use here multimap

*/
#include<iostream>
#include<map>
#include<vector>
using namespace std;

int GetHash(string str)
{
    int arr[256];
    for(int i = 0; i < 256; i++)
    {
       arr[i] = -1;
    }
    int code = 0;
    int c = 0;
    for(int i = 0; i < str.size(); i++)
    {
       if(arr[str[i]] == -1)
       {
          arr[str[i]] = c;
          c++;
       }
       code = code*10 + arr[str[i]];
    }
    return code;
}

int main()
{
   string str[7];

   str[0] = "pop";
   str[1] = "abba";
   str[2] = "ccd";
   str[3] = "xyxyz";
   str[4] = "wwv";
   str[5] = "cc";
   str[6] = "aa";

   map<int,vector<string> > m;

   //do not forget to receuive it in ref else what u make change not reflect inside v
   for(int i = 0; i < 7; i++)
   {
      vector<string> &v = m[GetHash(str[i])];
      v.push_back(str[i]);

   }

   map<int,vector<string> >::iterator it = m.begin();

   while(it != m.end())
   {
       vector<string> v = it->second;
       it++;
       for(int i = 0; i < v.size(); i++)
        cout<<v[i]<<"  ";
       cout<<endl;
   }
   return 0;
}
