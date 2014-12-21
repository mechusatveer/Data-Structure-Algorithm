#include<iostream>
#include<map>
using namespace std;

struct IPair
{
   string start;
   string end;
};

struct list
{
   string source;
   list *next;
   list *prev;
   public:
   list(string str,list* n = NULL, list* p = NULL)
   {
       source = str;
       next = n;
       prev = p;
   }
};
void Arrange(IPair *arr, int n)
{
     map<string,list*> mp;
     list* head = NULL;

     list* a = NULL;
     list* b = NULL;
     for(int i = 0; i < n; i++)
     {
         IPair* p = &arr[i];

         if(mp.find(p->start) == mp.end())
         {
             a = new list(p->start,NULL,NULL);
             mp[p->start] = a;
         }
         else
         {
             a = mp[p->start];
         }

         if(mp.find(p->end) == mp.end())
         {
             b = new list(p->end,NULL,NULL);
             mp[p->end] = b;
         }
         else
         {
             b = mp[p->end];
         }

         a->next = b;
         b->prev = a;
     }

     while(a->prev != NULL)
     {
        a = a->prev;
     }

     while(a != NULL)
     {
         cout<<a->source<<"--->";
         a = a->next;
     }
}

int main()
{
    struct IPair *arr = new IPair[6];

    arr[0].start = "Jaipur";
    arr[0].end = "Kolkatta";

    arr[1].start = "Dubai";
    arr[1].end = "Mumbai";

    arr[2].start = "Kolkatta";
    arr[2].end = "Dubai";

    arr[3].start = "Delhi";
    arr[3].end = "Jaipur";

    arr[4].start = "Mumbai";
    arr[4].end = "Chenni";

    arr[5].start = "Banglore";
    arr[5].end = "Delhi";

    Arrange(arr,6);
    return 0;
}
