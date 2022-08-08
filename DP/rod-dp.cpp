#include <iostream>

int max_rod(int[], int);
int main()
{
    int val[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    std::cout << "Enter the length";
    int n;
    std::cin >> n;
    int maxval= max_rod(val, n);
    std::cout<<"\n max value is "<<maxval;
}

int max_rod(int val[], int len)
{
    if (len <= 0)
    {
        return 0;
    }
    auto q = INT32_MIN;
    int i, j;
    int maxval;
    for (i = 0; i < len; i++)
    {
        q = 0;
        for (j = 0; j <= i; j++)
        {   
          
            q = std::max(q, val[j] + max_rod(val, len - j-1));
            //make sure this -1 is added in max_rod(val, len - j-1)
        }
    }
    return q;
}