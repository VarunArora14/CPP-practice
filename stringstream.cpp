#include<iostream>
#include<string.h>
#include<sstream> //removes error of incomplete type of stringstream s;

using namespace std;

int main(){
cout<<"enter string ";
string str,temp;
getline(cin,str);
int count=0;
stringstream s;
/*
clear() — to clear the stream
str() — to get and set string object whose content is present in stream.
operator << — add a string to the stringstream object.
operator >> — read something from the stringstream object,

*/
s<<str; // storing str in stringstream
int f;
// we have to find occurances of numbers
while(!s.eof())
{
s>>temp;    // extracting word by word
if(stringstream(temp)>>f)     // checking every word for integer
cout<<f<<" ";

temp="";    // to save from space
}
}



// Function to remove spaces */
string removeSpaces(string str) 
{ 
    stringstream ss; 
    string temp; 
  
    //* Storing the whole string into string stream */
    ss << str; 
  
   //* Making the string empty */
    str = ""; 
  
   // Running loop till end of stream */
    while (!ss.eof()) 
    { 
        //* extracting word by word from stream */
        ss >> temp; 
  
       // concatenating in the string to be 
         // returned*/
        str = str + temp; 
    } 
    return str; 
}




