#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[] = {1, 3, 8, 2, 4, 6, 5};
    int len = sizeof(a) / sizeof(a[0]);
    cout << distance(a, max_element(a, a + len));
}