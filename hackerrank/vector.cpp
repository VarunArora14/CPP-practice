#include <iostream>
#include <vector>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    for (auto i = 0; i < a.size(); i++)
    {
        /* code */

        cout << a[i] << " ";
    }
}