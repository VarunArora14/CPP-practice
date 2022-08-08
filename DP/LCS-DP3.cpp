#include <iostream>
#include <string>
#include <algorithm>

int func(std::string, std::string, int, int);
int maxval(int, int, int);
// std::string final;
//trying to find the string value does not help as recursive answer adds different strings at end

int main()
{
    std::string first, second, third;
    std::cout << "enter first - ";
    std::cin >> first;
    std::cout << "enter second -";
    std::cin >> second;
    // std::cout << "enter third - ";
    // std::cin >> third;
    int a, b, c;
    a = first.length();
    b = second.length();
    // c = third.length();
    func(first, second, a, b);
    // std::reverse(final.begin(),final.end());
    // std::cout<<"\n"<<final;
}

int func(std::string first, std::string second, int a, int b)
{
    int L[a + 1][b + 1];
    int k = 0;
    char final[20];
    //not L[a][b]
    //not i<a
    // for(auto i=0;i<=a;i++)
    // {
    //     for(auto j=0;j<=b;j++)
    //     {
    //         if(i==0 || j==0)
    //         {
    //             L[i][j]=0;
    //         }

    //         else if (first[i-1]==second[j-1])
    //         {
    //             L[i][j]= 1 + L[i-1][j-1];
    //         }

    //         else
    //         {
    //             L[i][j] = std::max(L[i-1][j],L[i][j-1]);
    //         }

    //     }
    // }

    int dp[a + 1][b + 1];
    for (int i = 0; i <= a; ++i)
        dp[i][0] = 0;

    for (int j = 0; j <= b; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= a; ++i)
        for (int j = 1; j <= b; ++j)
        {
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            if (first[i - 1] == second[j - 1])
            {
                final[k++] = second[j - 1];
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    int answer = dp[a][b];

    int i,j = 0;
    std::cout << " ";
    for (auto j = 0; j < b; j++)
    {
        std::cout << " " << second[j];
    }
    std::cout << "\n";

    for (auto i = 0; i <= a; i++)
    {
        if (i < a)
        {
            std::cout << first[i] << " ";
        }
        else
        {
            std::cout << "  ";
        }

        for (j = 0; j <= b; j++)
        {
            //    std::cout<<L[i][j]<<" ";
            std::cout << dp[i][j] << " ";
        }
        std::cout << "\n";
    }


    int index = dp[a][b];
    i=a;
    j=b;
    char lcs[index+1];//not int as it will point to memory block
    while(i>=0 && j>=0)
    {
        //if current character same then index-- , i-- and j-- as current character part of lcs
        if(first[i-1]==second[j-1])
        {   
            lcs[index-1]=first[i-1];
            index--;
            i--;
            j--;
        }
        //if not then look for the greater value 
        else if(dp[i-1][j]>dp[i][j-1])
        i--;
        else
        {
            j--;
        }
        
    }
    std::cout << "LCS of " << first << " and " << second << " is " << lcs;
    // std::cout << "\n \n The longest common subseqence is ";
    // for (auto i = 0; i < k; i++)
    // {
    //     std::cout << final[i];
    // }
    return 0;
}

// #include<iostream>
// #include<string>

// int func(std::string, std::string, int , int);

// int main()
// {
//     std::string first,second;

//     std::cout<<"First - ";
//     std::getline(std::cin,first);
//     std::cout<<"\n Second - ";
//     std::getline(std::cin,second);

//     int n,m;
//     n=first.length();
//     m=second.length();
//     std::cout<<"\n"<<func(first,second,n,m);
// }

// int func(std::string first , std::string second, int n, int m )
// {   //int count=0;

//     if(n==0||m==0)
//     return 0;

//     if(first[n-1]==second[m-1])
//     {
//         m--;
//         n--;
//         // count++;

//        return 1 + func(first,second,n-1,m-1);
//     }

//     else
//     {
//         return std::max(func(first,second,n-1,m),func(first,second,n,m-1));
//     }

// }