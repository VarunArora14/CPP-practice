
/*
Given an array A of length N, we can define rotation as follows. If we rotate A to the right, all elements move to 
the right one unit, and the last element moves to the beginning. That is, it becomes [AN,A1,A2,…,AN−1]. Similarly if 
we rotate A to the left, it becomes [A2,A3,…,AN,A1].

Given an array A and an integer x, define f(A,x) to be the array A rotated by the amount x. If x≥0, this means we 
rotate it right x times. If x<0, this means we rotate it left |x| times.

You are given an array A of length N. Then Q queries follow. In each query, an integer x is given. To answer the 
query, you should replace A with A+f(A,x) where + denotes concatenation. After this operation, you must output the 
sum of all elements of A. Since this number can be large, output it modulo 10^9+7.

Note that the queries are cumulative. When you modify A to answer one query, it starts that way for the next query.

Input
The first line contains an integer N - the size of the initial array.
The second line contains N integers A1,…,AN - the elements of the initial array.
The third line contains an integer Q - the number of queries.
The fourth line contains Q space-separated integers x1,…,xQ, where xi is the parameter of the i-th query.
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, i, q, x[100000];
    vector<int> a;
    int num;
    long long int total = 0;
    const unsigned int M = 1000000007;
    cin >> n; //size of array
    if (n <= 0)
    {
        cout << 0;
        exit(0);
    }
    for (i = 0; i < n; i++)
    {

        cin >> num;
        a.push_back(num);
    }
    for (i = 0; i < n; i++)
    {
        total += a[i];
    }
    cin >> q;
    for (i = 0; i < q; i++)
    {

        cin >> x[i];
    }
    for (i = 0; i < q; i++)
    {
        total += (total % M);
        cout << total << endl;
    }
    // cout << "total is " << total;
}