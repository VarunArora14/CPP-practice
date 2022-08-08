#include <iostream>
#include <string>
using namespace std;
int check(char str[], int l)
{
    int i, j;
    int zero = 0, one = 0;
    for (i = 0; i < l; i++)
    {
        if (str[i] == '0' || str[i] == '1')
        {
            // cout << "hello " << str[i];
            // return 0;
        }
        else
        {
            // cout << str[i] << " ";
            return 0;
        }
    }
    for (i = 0; i < l; i++)
    {

        if (str[i] == '0')
        {
            zero++;
        }
        else
        {
            one++;
        }
        if (one >= zero)
        {
            // cout << "nice";
            return 1;
        }
    }
    return 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, l;
    char str[100000];
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> l;
        for (int j = 0; j < l; j++)
        {
            cin >> str[j];
        }
        if (check(str, l) == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}