#include<iostream>
#include<string.h>

using namespace std;

int palindrome(char str[] ,int start, int len)
{
    
// Base Case: For only 1 character or middle character
if(str[start]==str[len] && start==len)
{
    return 1;
}

//If only 2 words are there and same
if (str[start]==str[len] && start+1==len)
{
    return 2;
}

//If 2 characters are same then return function 
if(str[start]==str[len])
{
    return palindrome(str,start+1,len-1)+2;
}
// return the maximum value of either moving 1 element from start and moving 1 element from end
// GEEKSFORGEEKS -> max(EEKSFORGEEKS,GEEKSFORGEEK)

    return max(palindrome(str,start+1,len),palindrome(str,start,len-1));

}

int palin2(char str[] )
{
    int i,j;
    int len = strlen(str);
    // int L[end][end];

    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            if(str[i]==str[j])
            {

            }
        }
    }
}

int main()
{
    char str[] = "GEEKSFORGEEKS";
    int len = sizeof(str)/sizeof(str[0]);
    palindrome(str,0,len);
}

// In the recursive soltuion we were moving i from 0 to n and j from n to 0
// If str[i]==str[j] then 2 + func(str,i+1.j-1)
// else max(func(str,i+1,j),func(str,i,j-1))

// considr each character in string at position i and from 0...i and i...n find the longest
// common subsequence(it will be n...i next to i)
// return the maximum