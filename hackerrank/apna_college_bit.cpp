#include <iostream>
using namespace std;
void allsubsets()
{
    // program to find all possible subsets
    // this uses 2^n formula for n times as they have total 2^n subsets
    // example {1,2,3}={},{1},{2},{3},{1,2},{2,3},{1,3},{1,2,3}
    // we can use bits as 1=001, 2=010, 4=100, 7=0111
    int n, a[100];
    cin >> n;
    // 2^n can be written as (1<<n). example 1<<3 shifts 3 bits across 1 which gives
    // 1000 which is 2^3=8
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << a[j] << " ";
            }
        }
        cout << "\n";
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    allsubsets();
}
void ones_in_number()
{
    int n;
    cin >> n;
    // now to find ones we do n&n-1 which returns the number with one less 1
    // example n=5=(101)2, n-1=4=(100)2. Now n&n-1 = (100)2=4
    // then n=4 an n-1=3=(011)2. Again n&n-1=(100)&(011)=0

    int c = 0;
    while (n != 0)
    {
        c++;
        n = n & n - 1;
    }
    cout << "number of ones is " << c;
}
void powerof2()
{
    unsigned int n;
    cin >> n;
    // check if the number is power of 2
    // now in binary all powers of 2 are 1000.. like 2=010, 4=100, 8=1000
    // so 8-1=0111, 4-1=011 which means if we find n&n-1==0 then power of 2
    if (n == 0)
    {
        cout << "number is 0";
    }
    else if (n == 1)
    {
        cout << "number is 1";
    }
    else if (n & n - 1)
    {
        cout << "number is not power of 2";
    }
    else
    {
        cout << "number is power of 2";
    }
}