#include <iostream>
#include <string.h>
#include<algorithm>
#include <process.h>

using namespace std;
int main()
{
    int sub = 0, carry = 0,i;
    string s1, s2;
    cout << "1st string " << endl;
    getline(cin, s1);
    cout << endl
         << "2nd string " << endl;
    getline(cin, s2);
    string str;
    str = "";
    if (s1.length() < s2.length())
    {
        cout << "first string must be greater";
        exit(0);
    }

    for (i = s2.length() - 1; i >= 0; i--) // only till small string length as rest part of
       //s2 would be garbage
    {
        sub = (s1[i] - '0') - (s2[i] - '0') - carry;
        if (sub < 0)
        {
            sub += 10;
            carry = 1;
            cout<<" sub "<<sub<<endl;
        }
        else
        {
            carry = 0;
        }
        str.push_back(sub + '0');
    }

    for (i = s2.length(); i < s1.length(); i++)
    {
        sub = (s1[i] - '0') - carry;
        if(sub<0)
        {
            sub+=10;
            carry=1;
        }
    else
    {
        carry = 0;
    }
    
    
    str.push_back(sub + '0');
    }
    reverse(str.begin(), str.end());
    cout << endl
         << str;
}