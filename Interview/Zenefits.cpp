You are given a binary array with N elements: d[0], d[1], ... d[N - 1]. 
You can perform AT MOST one move on the array: choose any two integers [L, R],
and flip all the elements between (and including) the L-th and R-th bits. 
L and R represent the left-most and right-most index of the bits marking the 
boundaries of the segment which you have decided to flip.

What is the maximum number of '1'-bits (indicated by S) which 
you can obtain in the final bit-string? 

'Flipping' a bit means, that a 0 is transformed to a 1 and a 1 is 
transformed to a 0 (0->1,1->0). 
Input Format 
An integer N 
Next line contains the N bits, separated by spaces: d[0] d[1] ... d[N - 1] 

Output: 
S 

Constraints: 
1 <= N <= 100000 
d[i] can only be 0 or 1f 
0 <= L <= R < n 

Sample Input: 
8 
1 0 0 1 0 0 1 0 


In most cases when the question is related to sub array the Kadane's algorithm is very useful.
The real problem in this question is to find largest contiguous sub array for which difference
'numberOfZeros - numberOfOnes' is the biggest to maximize the sum of ones after flipping zeros. 
Here is modified version of Kadane's algorithm to do this job. 
It converts 0 to -1 and computes the sum till the sum is <=0 (there is more 0s then 1s). 
If the sum is > 0 starts from the beginning. 
The major difference compare to ordinary Kadane's algorithm is that we are looking for the 
biggest negative sum instead of positive. 


public static void flipBits(int a[], int N)
{
	int maxDiff = 0;
	int flipStartIndex = 0;
	int flipEndIndex = 0;

	int currentDiff = 0;
	int currentStart = 0;

	for (int i = 0; i < N; i++)
	{
	    if (a[i] == 0)
	    {
		    	currentDiff -= 1;
	    }
	    else
	    {
		    	currentDiff += 1;
	    }
	    if (currentDiff < maxDiff)
	    {
		    	maxDiff = currentDiff;
		    	flipStartIndex = currentStart;
		    	flipEndIndex = i;
	    }
	    else if (currentDiff > 0)
	    {
		    	currentDiff = 0;
		    	currentStart = i + 1;
	    }
	}
	
  //so we know where that sub array its from flipStartIndex to flipEndIndex
  //count no of zeros in this they be 1 after flip so we count here 0
  int c = 0;
  for(int i = 0; i < N; i++)
  {
     if(a[i] == 0) c++;
  }
}

