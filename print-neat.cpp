#include <iostream>
#include<string>

using namespace std;

int len(string words[] ,int start ,int i)
{
    int k;
    int c=0;
    for(k=start;k<=i;k++)
    {
       c+= words[k].length();
    }
    return c;
}
string edit(string words[] ,int start, int n ,int M)
{
    int i,j,k;
    int line=0;
    for(i=start;i<n;i++)
    {
        if(i+ len(words,start,i)<M)
        {
            //Same line all the words till i
            // and rest space is M - i+ len(words,i)
            cout<<words[i]<<" ";
        }
        else
        {   cout<<"\n";
            line++;
            edit(words,i,n,M);
        }
        
    }
}
int main()
{   
    string words[] = {"Today", "is", "Monday", "and", "tomorrow", "is", "tuesday"};
    int M = 12;
    int n=7;
    cout<<edit(words,0,n,M);
    // string a;
}