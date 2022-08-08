#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
//algorithm for std::find()

using namespace std;

int main()
{
    vector<string> s1={ "i", "like", "sam", "sung", "samsung", "mobile", "ice", 
  "cream", "icecream", "man", "go", "mango"};
  cout<<"vector[0] = "<<s1[0]<<"\n";
  string str;
  cout<<"enter the string ";
  getline(cin,str);
  string sub;
  int c=0;
  auto i=0;
  int flag=0;
  int len=0;
  // sub = str.substr(0,i+1);
  for( i=0;i<str.length();i++)
  { 
    len++;
    sub = str.substr(c,len);
    
    cout<<"\n Now sub is "<<sub;
    // cout<<str.substr(0,i+1)<<"\n";

    if(find(s1.begin(),s1.end(),sub)!=s1.end())
   {
    // cout<<"\n"<<"HELLO"<<"\n";
    c=i+1;
    flag=1;
    len=0;
   }
   else
   {
     flag=0;
   }
   
  }

  if(flag==0)
  {
    cout<<" \n No";
    cout<<"\n sub = "<<sub;
  }
  else
  {
    cout<<"\n Yes";
    cout<<"\n sub = "<<sub;
  }
  
   
  
  //  s1.end();
  // s1.begin() and 1.end() return begin and end pointers 

//   int main() 
// { 
//     // declaration of vector container 
//     vector<string> myvector{ "computer", 
//                              "science", "portal" }; 
  
//     // using end() to print vector 
//     for (auto it = myvector.begin(); 
//          it != myvector.end(); ++it) 
//         cout << ' ' << *it; 
//     return 0; 
// } 
// Output:

// computer science portal
}


// In this we had to break a given string in such a way that all the substrings in their 
// respective order are present inside the string like -
// Consider the following dictionary 
// { i, like, sam, sung, samsung, mobile, ice, 
//   cream, icecream, man, go, mango}

// Input:  ilike
// Output: Yes 
// The string can be segmented as "i like".

// Input:  ilikesamsung
// Output: Yes
// The string can be segmented as "i like samsung" 
// or "i like sam sung".

// Now to do this we create vector array storing the dictionary values

// Then we create a new string str as input and declare sub as substring to be compared
// in increasing length by str.substring(position,length) 
// We do this inside the loop of str.length() where we do len++ (earlier len=0) and then check by


// if(find(s1.begin(),s1.end(),sub)!=s1.end())
  //  {
  //   // cout<<"\n"<<"HELLO"<<"\n";
  //   c=i+1;
  //   flag=1;
  //   len=0;
  //  }
  //  else
  //  {
  //    flag=0;
  //  }

  // This checks presence of string sub in vector using std::find() function

  // if found then move to next string character using c=i+1 as i was the current last 
  // character whose substring was found in the vector array

  // Using flag we can check whether the all substrings are considered

  // len=0 is important as, if len=1, then inside for loop, len++ is there which would
  // make the new substring sub=str.substring(c,len) where now len=2 . Using len=0 we can have
  // New length of 1 which is needed as smallest substring of 1 length 