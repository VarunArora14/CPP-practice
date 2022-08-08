#include <iostream>
using namespace std;
int main()
{
    freopen("output.txt", "w", stdout);
    int a = 10;
    int *aptr = &a;
    // aptr=&a;
    cout << aptr << " " << *aptr << "\n";
    *aptr = 50;
    cout << aptr << " " << *aptr << "\n";
    cout << "a is " << a << "\n";
}