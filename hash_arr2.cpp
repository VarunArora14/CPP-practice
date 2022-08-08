#include<iostream>
//#include<>

static int count=0;
    void insert(int a[] , int s , int ele)
    {
        

    }


int main()
{   
    
    std::cout<<"enter the size of the table";
    int s;
    std::cin>>s;
    std::cout<<"enter the value of n for fn x%n ";
    int n;
    std::cin>>n;
    int a[s];
    int i;
    for(i=0;i<s;i++)
    {
        a[i]=INT32_MIN;
    }
    int ele;
    char ch='y';
    int x;
    do
    {   std::cout<<" 1. insertion \n"<<" 2. deletion \n"<<" 3. Search  \n"<<" 4. Display \n";

        std::cout<<"enter your choice ";
        std::cin>>x;

        switch (x)
        {
        case 1:
        if(count+1>=s)
        {
         std::cout<<"the table is full";
         break;
        }
        std::cout<<"enter element to be inserted ";
        std::cin>>ele;
        insert(a,s,ele);
            break;

        case 2:
        std::cout<<"enter the element to be deleted ";
        std::cin>>ele;

        default:
            break;
        }


       std::cout<<"Do you want to continue ?";
       std::cin>>ch;
    } while (ch=='y');
    

}