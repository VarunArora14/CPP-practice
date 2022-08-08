#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int main()
{
    // online judge and freopen inside main() and not outside
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    map<int, int> map1;
    map1.insert(pair<int, int>(1, 10));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
}