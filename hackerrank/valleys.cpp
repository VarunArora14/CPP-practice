// https://www.hackerrank.com/challenges/counting-valleys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
#include <iostream>
#include <string>
using namespace std;
int valley = 0, mountain = 0;
// int count = 0;
string input;
void check(int i, string inp)
{
    if (inp[i] == 'D')
    {
        valley++;
    }
    else
    {
        mountain++;
    }
}
int valleys()
{
    int count = 0;
    // for D do -1, for U do +1
    cin >> input;
    int len = input.length();
    if (len == 0)
        return 0;
    else if (len == 1)
    {
        if (input[0] == 'D')
            return 1;
        else
            return 0;
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            if (count == 0)
            {
                check(i, input);
            }
            if (input[i] == 'D')
            {
                count--;
            }
            else
            {
                count++;
            }
        }
        return valley;
    }
}
int main()
{
    cout << valleys();
}
