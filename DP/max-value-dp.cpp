#include<iostream>
#include<cmath>

// In this program we have to input a number and find the maximum sum by  a function called
// F(n) = max( (F(n/2) + F(n/3) + F(n/4) + F(n/5)), n)

int func(int num);
int main()
{
    int num;
    std::cout<<"enter the number ";
    std::cin>>num;
    std::cout<<"Sum is "<<func(num);
}

int func(int num)
{
    int res[num+1];
    res[0]=0;
    res[1]=1;
    res[5]=5;
    res[2]=2;
    for(int i=2;i<=num;i++)
    {
        res[i] = std::max(res[i/2] + res[i/3] + res[i/4] + res[i/5],i);
    }

    return res[num];
}