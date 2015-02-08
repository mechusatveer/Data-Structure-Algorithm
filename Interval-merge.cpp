Interval given to you

One question is like

Print all intervals that can be processed here interval if conflict cannot process
so here we interested in non merging intervals
 greedy  end based sorting
 
Other problem is below  we need to merge intervals so here we are interested in marging process
its just opposite of above

if ith intervals cannot merged with i-1th then its not possible that it can merge with i+1

so we sort based on start point

Push first and pick next if it merge mean curr start is less than stack top end
merge them and keep doing

if its not merged 
push new also in stack.

nlogn time complexity be here


// A C++ program for merging overlapping intervals
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
 
// An interval has start time and end time
struct Interval
{
    int start;
    int end;
};
 
// Compares two intervals according to their staring time.
// This is needed for sorting the intervals using library
// function std::sort(). See http://goo.gl/iGspV
bool compareInterval(Interval i1, Interval i2)
{  return (i1.start < i2.start)? true: false; }
 
// The main function that takes a set of intervals, merges
// overlapping intervals and prints the result
void mergeIntervals(vector<Interval>& intervals)
{
    // Test if the given set has at least one interval
    if (intervals.size() <= 0)
        return;
 
    // Create an empty stack of intervals
    stack<Interval> s;
 
    // sort the intervals based on start time
    sort(intervals.begin(), intervals.end(), compareInterval);
 
    // push the first interval to stack
    s.push(intervals[0]);
 
    // Start from the next interval and merge if necessary
    for (int i = 1 ; i < intervals.size(); i++)
    {
        // get interval from stack top
        Interval top = s.top();
 
        // if current interval is not overlapping with stack top,
        // push it to the stack
        if (top.end < intervals[i].start)
        {
            s.push( intervals[i] );
        }
        // Otherwise update the ending time of top if ending of current 
        // interval is more
        else if (top.end < intervals[i].end)
        {
            top.end = intervals[i].end;
            s.pop();
            s.push(top);
        }
    }
 
    // Print contents of stack
    cout << "\n The Merged Intervals are: ";
    while (!s.empty())
    {
        Interval t = s.top();
        cout << "[" << t.start << "," << t.end << "]" << " ";
        s.pop();
    }
 
    return;
}
 
// Functions to run test cases
void TestCase1()
{
    // Create a set of intervals
    Interval intvls[] = { {6,8}, {1,9}, {2,4}, {4,7} };
    vector<Interval> intervals(intvls, intvls+4);
 
    // Merge overlapping inervals and print result
    mergeIntervals(intervals);
}
void TestCase2()
{
    // Create a set of intervals
    Interval intvls[] = { {6,8},{1,3},{2,4},{4,7} };
    vector<Interval> intervals(intvls, intvls+4);
 
    // Merge overlapping inervals and print result
    mergeIntervals(intervals);
}
void TestCase3()
{
    // Create a set of intervals
    Interval intvls[] = { {1,3},{7,9},{4,6},{10,13} };
    vector<Interval> intervals(intvls, intvls+4);
 
    // Merge overlapping inervals and print result
    mergeIntervals(intervals);
}
 
// Driver program to test above functions
int main()
{
    TestCase1();
    TestCase2();
    TestCase3();
    return 0;
}
Output:

