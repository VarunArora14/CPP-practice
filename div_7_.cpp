#include<iostream>
#include<string.h>

// divisible by 11 - sum of add places - sum of even places = 0 or num % 11==0
// divisibly by 12 - must be divisibe by 3 and 4
// for 4 , last 2 digits divisible by 4
// for 2 , last digit % 2 == 0
//for 3 - if the sum of digits of N is a multiple of 3
// for 5 - last either 0 or 5
// for 6 - both divisible by 2 and 3
//for 7 - if subtracting twice the last digit of N from the remaining digits
// gives a multiple of 7 (e.g. 658 is divisible by 7 because 65 - 2 x 8 = 49, 
//which is a multiple of 7)
// for 8 - last 3 digits multiple of 8
//for 9 - sum of digits multple of 9

using namespace std;

int main()
{   int sub=0,n,flag=0,r=0;
    string s;
    cout<<"enter the number string"<<endl;
    getline(cin,s);
    int i,a;
    a=s.length();
    
   if(a==0)
    {
        cout<<"no number entered";
    }
    else if(s.length()==1)
    {
        cout<<"remainder is "<<(s[0]-'0') % 7<<endl;
    }
    else
    {
        for(i=0;i<a-1;i++)
        {   sum=sum*10;
            sum+=s[i]-'0';
            
        }
        n=s[i]-'0';
        cout<<"2* n is "<<2*n<<endl;

        while(sum>0)
        {
            sum=sum-(2*n);
            if(sum%7==0)
            {
                cout<<endl<<"sum is "<<sum<<endl;
                flag=1;
            }
        }
    }
    if(flag==0)
    {
        cout<<"the remainder is "<<sum<<endl;
    }
    else
    {
        cout<<"completely divisible by 7 "<<endl;
    }
}

 // C++ program to find remainder of a large
// number when divided by 7.
#include<iostream>
using namespace std;
 
/* Function which return Remainder after dividing
   the number by 7 */
int remainderWith7(string num) {
    int remainder = 0;
    
    for (int i = 0; i < num.length(); i++) {
        int dividend = (remainder * 10) + (num[i] - '0');
        remainder = dividend % 7;
    }
    
    return remainder;
}
 
/* Driver program */
int main() {
    string str;
    
    str = "1234";
    cout << str << " % 7 = " << remainderWith7(str) << endl;
    
    str = "1232";
    cout << str << " % 7 = " << remainderWith7(str) << endl;
    
    str = "12345";
    cout << str << " % 7 = " << remainderWith7(str) << endl;
    
    return 0;
}
