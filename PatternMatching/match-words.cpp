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

int getHash(string str)
{
    int arr[256] = {-1};
    int code = 0;
    int c = 0;
    for(int i = 0; i < str.size(); i++)
    {
       if(arr[str[i]] == -1)
       {
          arr[str[i]] = c;
          code = code*10 + c;
          c++;
       }
    }
    return code;
}

int main(int argc, char*argv[])
{
   map<int,vector<string>> mp;
   
   for(int i =1; i <= argc; i++)
   {
       mp[getHash(argv[i])].push_back(argv[i]);
   }
   
   map<int,vector<string>>::iteroator it = mp.begin();
   
   while(it != mp.end())
   {
      vector<string> v = it.second;
      for(int i = 0; i < v.size(); i++)
      cout<<v[i]<<"  ";
      cout<<endl;
   }
   
}
