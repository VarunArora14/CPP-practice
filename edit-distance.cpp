#include<iostream>

using namespace std;

string s ="algorithm";
string z="";
int i=0;
int j=0;
int len = s.length();
char copy()
{
    if(i<len)
return s[i++];
}
void del()
{   
    // i++;
    if(i<len) i++;
    
}
char replace(char t)
{    i++;
//first i++ then return
    return t;
    // i++;
}
char insert(char a)
{
    return a;
}
void twiddle()
{
    if(i<len)
    {
        z[j]=s[i+1];
        z[j+1]=s[i];
        i+=2;
        j+=2;
    }
}

void kill()
{

}
int main()
{
z[j++]=copy();
z[j++]=copy();
z[j++] = replace('t');
del();
z[j++]=copy();
z[j++] = insert('u');
z[j++] = insert('i');
z[j++] = insert('s');
twiddle();
z[j++] = insert('c');
cout<<"\n"<<z;
int k=0;
for(k;k<j;k++)
{
    cout<<z[k];
}
}