#include <iostream>
// find max from a[0] to a[i] for all i 0 to n-1
// example 1 0 5 4 6 8
// Ans: 1 1 5 5 6 8
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
        cout << max << " ";
    }
}