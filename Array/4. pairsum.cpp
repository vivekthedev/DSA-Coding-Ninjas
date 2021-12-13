/*

Chapter Assignment
Problem Statement: Pair sum in array
Problem Level: MEDIUM
Problem Description:
You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.
Note:
Given array/list can contain duplicate elements.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'num'.

Output format :
For each test case, print the total number of pairs present in the array/list.

Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^4
0 <= num <= 10^9

Time Limit: 1 sec

Sample Input 1:
1
9
1 3 6 2 5 4 3 2 4
7

Sample Output 1:
7

Sample Input 2:
2
9
1 3 6 2 5 4 3 2 4
12
6
2 8 10 5 -2 5
10

Sample Output 2:
0
2

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pairsumLinearApproach(int a[], int size, int num)
{
    int count = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] + a[j] == num)
            {
                count++;
            }
        }
    }
    return count;
}

int pairSumSortedApproach(int a[], int size, int num)
{
    int count = 0;

    int i = 0, j = size - 1;
    while (i < j)
    {
        int sum = a[i] + a[j];
        if (sum == num)
        {
            count++;
            i++;
        }
        else if (sum > num)
        {

            j--;
        }
        else if (sum < num)
        {
            i++;
        }
    }

    return count;
}

int main()
{
    int a[] = {1, 3, 6, 2, 5, 4, 3, 2, 4};
    int size = 9;
    int num = 7;
    sort(a, a + size);

    // cout << pairsumLinearApproach(a, size, num);
    cout << pairSumSortedApproach(a, size, num);
}