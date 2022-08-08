#include <iostream>
using namespace std;

int main()
{
  string s;
  cout << "enter string: ";
  getline(cin, s);
  int count = 0;
  for (int i = 0; i < s.length(); i++)
  {
    cout << "s[i] is " << s[i] << "\n";
    if (s[i] == ' ' || isalpha(s[i]))
    {
    }
    else
    {
      count++;
    }
  }

  cout << count;

  return 0;
}