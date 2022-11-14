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

string convert(string s, int numRows)
{
  int n = s.length();
  int count = 0;
  int row = 0;
  vector<vector<char>> vec(numRows);
  while (count < n)
  {
    row = 0;
    while (row < numRows && count < n)
    {
      vec[row].push_back(s[count]);
      count++;
      row++;
    }
    row = numRows - 2;
    while (row > 0 && count < n)
    {
      vec[row].push_back(s[count]);
      count++;
      row--;
    }
  }

  string ans = "";
  for (int i = 0; i < numRows; i++)
  {
    for (char val : vec[i])
      ans += val;
    cout << "\n";
  }

  return ans;
}

int main()
{
  string s;
  cin >> s;
  int num;
  cin >> num;
  cout << convert(s, num);
  return 0;
}