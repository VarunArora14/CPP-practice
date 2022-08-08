#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    // string a[5];
    vector<string> str;
    cout << "enter str";
    char b = 'y';
    string newstr;
    while (b != 'n')
    {
        cout << "enter elemenet";
        cin >> newstr;
        str.push_back(newstr);
        cout << "continue  ? ";
        cin >> b;
    }
    cout << endl;
    sort(str.begin(), str.end());
    for (auto x : str)
    {
        cout << x << " ";
    }

    return 0;
}