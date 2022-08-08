#include <iostream>
#include <algorithm>
using namespace std;
void songplay(int m, int s)
{
    int len;
    if (m == 0 || s == 0)
    {
        cout << 0 << endl; //as length of ride is 0
    }
    else if (m < s)
    {
        cout << 0 << endl;
    }
    else
    {
        len = m / s;
        // len = floor(len);
        cout << len << endl;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, s, m;
    cin >> t;
    int i;
    for (i = 0; i < t; i++)
    {
        cin >> m >> s;
        songplay(m, s);
    }
}