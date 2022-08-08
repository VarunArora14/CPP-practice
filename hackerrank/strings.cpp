// https://www.codechef.com/LTIME95C/problems/EQUINOX
#include <iostream>
#include <vector>
using namespace std;
int isequinox(string str)
{
    if (str[0] == 'E' || str[0] == 'Q' || str[0] == 'U' || str[0] == 'I' || str[0] == 'N' || str[0] == 'O' || str[0] == 'X')
    {
        return 1;
    }
    return 0;
}
void check(vector<string> str, int &s, int &a, int n)
{
    int i, j;
    string newstring;

    for (i = 0; i < n; i++)
    {
        newstring = str[i];
        // Here check whether the newstring[0] has starting with letters of EQUINOX
        if (isequinox(newstring))
        {
            s++;
        }
        else
        {
            a++;
        }
        // cout << newstring << endl;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<string> str;
    int t, i, n, j;
    int s, a;
    string newstr;
    //  s is sarthak pooints
    // a is anuradha points
    // n is no. of strings
    cin >> t;
    for (i = 0; i < t; i++)
    {
        cin >> n >> s >> a;
        for (j = 0; j < n; j++)
        {
            //  cin>>s[j];
            cin >> newstr;
            str.push_back(newstr);
            // clear vector using vectorname.clear()
        }
        check(str, s, a, n);
        // cout << "s is " << s << " and a is " << a << endl;
        if (s == a)
        {
            cout << "DRAW" << endl;
        }
        else if (s < a)
        {
            cout << "ANURADHA" << endl;
        }
        else
        {
            cout << "SARTHAK" << endl;
        }
        str.clear();
    }
}