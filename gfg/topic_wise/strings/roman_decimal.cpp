// https://www.geeksforgeeks.org/converting-roman-numerals-decimal-lying-1-3999/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <climits>
#include "unordered_map"

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void sol(string num)
{
  unordered_map<char, int> m;
  m.insert({'I', 1});
  m.insert({'V', 5});
  m.insert({'X', 10});
  m.insert({'L', 50});
  m.insert({'C', 100});
  m.insert({'D', 500});
  m.insert({'M', 1000});

  // what we have to do is check if next char is a larger value than current char value. That would mean sum is sum+num[m[i+1]]-num[m[i]];
  // the edge case num[i+1] where i=n-1 gives num[n] which would not exist in the map
  int n = num.length();
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    if (m[num[i]] < m[num[i + 1]])
    {
      sum += m[num[i + 1]] - m[num[i]]; // "IXIV"
      i++;
    }
    else
      sum += m[num[i]];
  }
  cout << "sum is " << sum;
}

int main()
{
  string num = "MCIV";
  sol(num);
  return 0;
}

/*

"X" "XXXX", "IV", "MIV"

IMPORTANT - Descending Order
Approach: A number in Roman Numerals is a string of these symbols written in descending order(e.g. M’s first, followed by D’s, etc.). However, in a few specific
cases, to avoid four characters being repeated in succession(such as IIII or XXXX), subtractive notation is often used as follows:

I placed before V or X indicates one less, so four is IV (one less than 5) and 9 is IX (one less than 10).
X placed before L or C indicates ten less, so forty is XL (10 less than 50) and 90 is XC (ten less than a hundred).
C placed before D or M indicates a hundred less, so four hundred is CD (a hundred less than five hundred) and nine hundred is CM (a hundred less than a thousand).
*/