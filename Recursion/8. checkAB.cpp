/*
Problem Statement: Check AB
Problem Level: MEDIUM
Problem Description:
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'

If all the rules are followed by the given string, return true otherwise return false.
Input format :
String S

Output format :
'true' or 'false'

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
abb

Sample Output 1 :
true

Sample Input 2 :
abababa

Sample Output 2 :
false



*/
#include <iostream>
using namespace std;

bool checkAB(string input)
{
    if (input.empty())
    {
        return true;
    }
    else if (input[0] == 'a')
    {
        string smallStr = input.substr(1);
        if (smallStr.find("bb") == 0)
        {
            smallStr = smallStr.substr(2);
        }
        bool ans = checkAB(smallStr);
        return ans;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout << checkAB("abababa");
    return 0;
}