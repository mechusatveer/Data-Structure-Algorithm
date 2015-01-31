1) You have n requests from different people to book a room
    In a year think days are 0-364
    Req1  3-7 mean i want to book a room from day 3 to day 7
    Req2  2-19 mean i want to book a room from day 2 to day 19
    Req3  5-7 mean i want to book a room from day 5 to day 7

   Now all request cannot be processed
   We want 

  1) How many max request can be processsed
  2) How much max rent we can get it mean how many max days u can keep your room busy

  request cannot accepted partial

 1-2
 3-4
 1-5

 Here how many max request we can process - 2  1-2 & 3-4
But how many max days we can keep busy this room is 1-5 and in that case only 1 req be processed.

Any doubt drop a mail to me

2) You are school teacher, u have your n students
    You have one array of their marks and all these n students are in a queu
    Then can know marks of next and prev student
    
    Now condition is u need to distribute sweets between these students
    If a student have more marks then any neighbour he want more sweets than that neighbour

    Note:- we not say equal
    3 4 4
    1 2 1 its ok 
     3rd cannot say why i not get two bcoz he not have more marks 

    Simply say you can make a argument if you have more marks than your neighbour

   Now we need to distrubite sweets such a way 
   So no argument happen there
   and sweets used be less.
-------------------------------------------------------------------------------------------------------

We cannot use here vector or string or something like that
we have to allocate our own memory allocation and keep pointing in that only
like if i use vector results be strange

==============================================================================
#include<iostream>
#include<vector>

using namespace std;

void function(int arr[], int i, int n,int res[], int x)
{
    if(i == n)
    {
        for(int j = 0; j < x; j++) cout<<res[j]<<"  ";
        cout<<endl;
        return;
    }
    
    res[x] = arr[i];
    function(arr,i+1,n,res,x+1);
    function(arr,i+1,n,res,x);
}

int main()
{
    int arr[] = {1,2,3,4};
    int result[] = {0,0,0,0};
    function(arr,0,4,result,0);
    return 0;
}

1  2  3  4  

1  2  3  

1  2  4  

1  2  

1  3  4  

1  3  

1  4  

1  

2  3  4  

2  3  

2  4  

2  

3  4  

3  

4  

===========================================================================================
Problem 1 Part 1
===========================================================================================
Appraoch 1:-
============
int Process(vector<Interval> v)
{
    int t = 0;
    for(int i = 0; i < v.size(); i++)
    {
       if(v[i].end >= v[i+1].start) return 0;
       t++;
    }
    return t;
}
int ProcessMaxRequest(Intervals arr[], int n, int i, vector<Interval> v, int &tmax)
{
   if(i == n)
   {
      //You have vector of intervals
      int t = Process(v);
      if(t > tmax) tmax = t;
      return;
   }
   v.push_back(arr[i]); //part of
   ProcessMaxRequest(arr,n,i+1,v);
                        //not part of
   ProcessMaxRequest(arr,n,i+1,v);
}

Approach 2:-
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval
{
    int s;
    int e;
    int w;
    Interval(int i,int j)
    {
        s = i;
        e = j;
        w = 1;
    }
};

class compare
{
  public:
  bool operator()(Interval a,Interval b)
  {
      if(a.s < b.s) return true;
      else if(a.s > b.s) return false;
      return a.e < b.e;
  }
};
int Max(int i, int j)
{
   if(i > j) return i;
   
   return j;
}

int MaxBookings(Interval arr[], int n)
{
    int max_booking = 0;
    for(int i = 0; i < n; i++)
    {
       
       Interval curr = arr[i];
       int w = curr.w;
       int max = w;
       
       for(int j = i-1; j >= 0; --j)
       {
           Interval temp = arr[j];
           if(temp.e < curr.s)
           {
               max = Max(max,temp.w + w);
           }
       }
       arr[i].w = max;
       
       if(max > max_booking)
       {
           max_booking = max;
       }
    }
    return max_booking;
}


int main()
{
    Interval arr[10] =  { Interval(4,23),
                          Interval(1,14),
                          Interval(15,18),
                          Interval(13,15),
                          Interval(19,34),
                          Interval(11,23),
                          Interval(3,17),
                          Interval(6,29),
                          Interval(4,14),
                          Interval(2,33)
                        };
    sort(arr,arr+10,compare());
    cout<<endl;
    cout<<MaxBookings(arr,10)<<endl;
    cout<<endl;
    return 0;
}



===========================================================================================================
//Problem 1 Part 2
============================================================================================================
Approach 1:- O(n*2^n)

int Process(vector<Interval> v)
{
    int t = 0;
    for(int i = 0; i < v.size(); i++)
    {
       if(v[i].end >= v[i+1].start) return 0;
       
       t = t + v[i].end - v[i].start + 1;
    }
    return t;
}
int GetMaxRent(Intervals arr[], int n, int i, vector<Interval> v, int &tmax)
{
   if(i == n)
   {
      int t = Process(v);
      if(t > tmax) tmax = t;
      return;
   }
   v.push_back(arr[i]); 
   GetMaxRent(arr,n,i+1,v);
   GetMaxRent(arr,n,i+1,v);
}

Appraoch 2:- O(n^2)
===================
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval
{
    int s;
    int e;
    int w;
    Interval(int i,int j)
    {
        s = i;
        e = j;
        w = e - s + 1;
    }
};

class compare
{
  public:
  bool operator()(Interval a,Interval b)
  {
      if(a.s < b.s) return true;
      else if(a.s > b.s) return false;
      return a.e < b.e;
  }
};
int Max(int i, int j)
{
   if(i > j) return i;
   
   return j;
}

int MaxRent(Interval arr[], int n)
{
    int max_rent = 0;
    for(int i = 0; i < n; i++)
    {
       
       Interval curr = arr[i];
       int w = curr.w;
       int max = w;
       
       for(int j = i-1; j >= 0; --j)
       {
           Interval temp = arr[j];
           if(temp.e < curr.s)
           {
               max = Max(max,temp.w + w);
           }
       }
       arr[i].w = max;
       
       if(max > max_rent)
       {
           max_rent = max;
       }
    }
    return max_rent;
}


int main()
{
    Interval arr[10] =  { Interval(4,23),
                          Interval(1,14),
                          Interval(15,18),
                          Interval(13,15),
                          Interval(19,34),
                          Interval(11,23),
                          Interval(3,17),
                          Interval(6,29),
                          Interval(4,14),
                          Interval(2,33)
                        };
    sort(arr,arr+10,compare());
    cout<<endl;
    cout<<MaxRent(arr,10)<<endl;
    cout<<endl;
    return 0;
}

