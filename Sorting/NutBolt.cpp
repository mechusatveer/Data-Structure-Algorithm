/*

You have n nuts and n bolts there is one to one mapping but they jumbled.
you need to assign each nut to its bolt.

You cannot compare a nut with other nuts
You cannot compare a bolt with other bolts

Else i know what you do

sort all nuts based on size
sort all bolts based on size

and this is one to one mapping

so complexity will be nlogn

Forget its not allowed

Now what u can do other way

pick a nut and find its bolt  n compare
pick next nut and find its bolt n-1 compare
pick next nut and find its bolt n-2 compare

so overall 

n + n-1 + n-2 + n-3 ........2 = O(n^2)

We want better than this

can we use quick sort here

partition nuts array based on bolt array pivot element
we can take last bolt as pivot item
whatever partition index we found that is pivot item for partition bolts array

n1           n2
b1           b2

so now our problem become two subproblem

solve n1 b1
and solve n2 b2


public class NutsAndBoltsMatch
{
    //Driver method
    public static void main(String[] args)
    {
        // Nuts and bolts are represented as array of characters
        char nuts[] = {'@', '#', '$', '%', '^', '&'};
        char bolts[] = {'$', '%', '&', '^', '@', '#'};
 
        // Method based on quick sort which matches nuts and bolts
        matchPairs(nuts, bolts, 0, 5);
 
        System.out.println("Matched nuts and bolts are : ");
        printArray(nuts);
        printArray(bolts);
    }
 
    // Method to print the array
    private static void printArray(char[] arr) {
        for (char ch : arr){
            System.out.print(ch + " ");
        }
        System.out.print("\n");
    }
 
    // Method which works just like quick sort
    private static void matchPairs(char[] nuts, char[] bolts, int low,
                                                              int high)
    {
        if (low < high)
        {
            // Choose last character of bolts array for nuts partition.
            int pivot = partition(nuts, low, high, bolts[high]);
 
            // Now using the partition of nuts choose that for bolts
            // partition.
            partition(bolts, low, high, nuts[pivot]);
 
            // Recur for [low...pivot-1] & [pivot+1...high] for nuts and
            // bolts array.
            matchPairs(nuts, bolts, low, pivot-1);
            matchPairs(nuts, bolts, pivot+1, high);
        }
    }
 
    // Similar to standard partition method. Here we pass the pivot element
    // too instead of choosing it inside the method.
    private static int partition(char[] arr, int low, int high, char pivot)
    {
        int i = low;
        char temp1, temp2;
        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot){
                temp1 = arr[i];
                arr[i] = arr[j];
                arr[j] = temp1;
                i++;
            } else if(arr[j] == pivot){
                temp1 = arr[j];
                arr[j] = arr[high];
                arr[high] = temp1;
                j--;
            }
        }
        temp2 = arr[i];
        arr[i] = arr[high];
        arr[high] = temp2;
 
        // Return the partition index of an array based on the pivot 
        // element of other array.
        return i;
    }
}
Output:

Matched nuts and bolts are :
# $ % & @ ^
# $ % & @ ^ 
