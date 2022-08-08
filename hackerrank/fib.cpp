#include <iostream>
using namespace std;
int fib(int n)
{
    if (n == 0 || n == 1) // base case
        return n;
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    cout << fib(n);
}
