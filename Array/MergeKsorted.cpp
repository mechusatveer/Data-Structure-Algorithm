Hi

you are given n sorted array each of size m
you need to generated a new array of size mn which is sorted 
Anyhow we need to allocate mn space so do not count that is space complexity

1)    4  8 9 10 14 16
       3  6 7 11 17 18
      1  2 5   6  12 13

Here m = 6
        n = 3

1) brute force will be

    space complexity = O(1) No extra space we using
    Time complexity = mnlog(mn)

2)  

   struct item
   {
        int i;
        int next_index;
   }

   we will use min heap here
   So allocate n size 
   for each n array pick the first item
   build item struct and place next index as 1
   and send to min heap

  Now precolate all parents

  nlogn Time taken here

  now extract root and place this to result array only i part and get next_index
  next item that we send to min heap will be from same array which have root extracted.

  so we do it for all remain items


  (mn-n)logn + nlogn


  So using this approach

  Space Complexity = O(n)
  Time complexity = (mn-n)logn + nlogn = mnlog(n)

3) Can we use merge sort merge logic like approach

    two array of size m and n we can merge in m+n time

    and for merge purpose we can use result array itself

   thats good for us

   but we can do a merge best manner if we do using 

   Now there is some twick here

   1) if we have all n array of same size we can use queue to pick who is next candiadte
   2) else we have to use priority queue based

  suppose all array of same size

   Allocate a deque of size n  place each array to queue

   pop first two items and merge them and push_back to queue
 
  mlogn time it take for merge all parts and queue so it not take any time complexity

  = mlog(n) 

Time complexity = mlog(n)
 Space complexity = O(n)

But if each array is not of same size

we have to use heap based merge process

mlog(n) + nlog(n) heap procolate cost

= (m+n)log(n)





   
  
-- 
Thanks & Regards

Satveer Singh Mechu
