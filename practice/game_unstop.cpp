#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <climits>

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

void sol(string str, string pattern)
{
  if (str.length() < 2)
  {
    cout << " not possible";
    return;
  }

  string check1 = pattern[0] + str;
  string check2 = str + pattern[1];

  // now for each string, we have to find the other one
  // for check1 what we do is, we keep looking for pattern[1] from end and once we find it we add to a variable and once we find pattern[0]
  // we add this to ans1. No need to reset this variable as if later another pattern[0] found then easier for us.
  int ans1 = 0, ans2 = 0;
  int len = check1.length();

  int var = 0;
  for (int i = len - 1; i >= 0; i--)
  {
    // keep incrementing when u find pattern[1] and add all only when u find pattern[0]
    if (check1[i] == pattern[1])
      var++;
    else if (check1[i] == pattern[0])
      ans1 += var;
  }

  var = 0;

  // similarly for check2, when you find pattern[1], var++ and once you find pattern[0], ans2+=var
  for (int i = len - 1; i >= 0; i--)
  {
    if (check2[i] == pattern[1])
      var++;
    else if (check2[i] == pattern[0])
      ans2 += var;
  }

  cout << " ans is " << max(ans1, ans2);
}

int main()
{
  string str, pattern;
  cin >> str >> pattern;
  sol(str, pattern);
  return 0;
}
/*
Given 2 strings str and pattern you have to find the max number of times the pattern of len=2 is there in the string.
The len of pattern=2 is fixed
Also note that the children can append either pattern[0] and pattern[1] to the str but is not compulsory

Adding any would not cause any problem and since the problem says we have to find the pattern subsequence and not substring,
rather than putting pattern[0] everywhere and finding the best value, putting it at 0th pos is best.
Similarly, putting pattern[1] at the end is best as we have to find the subsequence
*/