/*
Spell out an integer number in English.
For example:
Input: 1000234
Output: One Thousand, Two Hundred and Thirty Four
Note: support negative integer.
*/


/*
solution: process the number by three digits one time, add proper big unit between those digits.
For each three digits, consider different situations.
*/

#include <iostream>
#include <string>
using namespace std;


string lastdigit[10] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
string allteen[10] = { "", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
string allten[10] = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
string more[10] = { "","","","","Thousand ","Thousands " ,"Lac ", "Lacs ", "Crore ", "Crores "};

string UnderHundred(int num)
 {
    string output = "";

    if (num >= 100)
    {
        output += lastdigit[num/100] + " Hundred ";
        num %= 100;
    }

    if (num >= 11 && num <= 19)
    {
        output += allteen[num-10] + " ";
    }
    else if (num >= 20 || num == 10)
    {
        output += allten[num/10] + " ";
        num %= 10;
    }

    if (num >= 1 && num <= 9)
    {
        output += lastdigit[num] + " ";
    }

    return output;
}
//Do not try to start from left side
//process less than 1000 element first and then remain process in pair of two.
string TranslateNumber(long long num)
{
    string output = UnderHundred(num%1000);

    num = num/1000;

    int index = 4;

    while (num > 0)
    {

        int d1 = num%10;
        num = num/10;
        int d2 = num%10;
        num = num/10;
        int d = d2*10 + d1;

        if(d >= 11 && d <= 19)
        {
            index++;
            output = allteen[d%10] + " " + more[index] + " " + output;
            index++;
        }
        else if(d == 0)
        {
            index = index+2;
        }
        else if(d >= 1 && d <= 9)
        {
             output = lastdigit[d%10] + " " + more[index] + " " + output;
             index = index + 2;
        }
        else
        {
            index++;
            output = allten[d2] + " " + lastdigit[d1] + " "  + more[index] + " " + output;
            index++;
        }
    }
    return output;
}

int main() {

    cout<<"Input the number: ";
    long long num;
    cin>>num;
    cout<<TranslateNumber(num)<<endl;
    return 0;
}
