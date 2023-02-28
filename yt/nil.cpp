#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <string>
#include <climits>

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define print3(x, y, z) cout << #x << '=' << x << ',' << #y << '=' << y << ',' << #z << '=' << z << endl
#define nline cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define pb push_back
#define sz(x) ((long long)(x).size())
#define ppb pop_back
#define ff first
#define ss second

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpii = vector<pair<int, int>>;

const int mod = 1000000007;
const int max_n = 1000000;

int maxval = INT_MIN, minval = INT_MAX;

string solve(string s)
{
  string temp = s;
  // base case for 1 length
  if (s.length() == 1)
    return (s[0] == '?') ? "a" : s;

  int n = s.length();
  set<char> charset;

  for (int i = 0; i < n; i++)
  {
    if (temp[i] != '?')
      continue;
    if (i == 0)
    {
      charset.insert(temp[i + 1]);
      for (int j = 0; j < 3; j++)
      {
        if (!charset.count('a' + j))
        {
          temp[i] = 'a' + j;
          break;
        }
      }
    }
    else if (i == n - 1)
    {
      charset.insert(temp[n - 2]);
      for (int j = 0; j < 3; j++)
      {
        if (!charset.count('a' + j))
        {
          temp[i] = 'a' + j;
          break;
        }
      }
    }
    else
    {
      charset.insert(temp[i - 1]);
      charset.insert(temp[i + 1]);
      for (int j = 0; j < 3; j++)
      {
        if (!charset.count('a' + j))
        {
          temp[i] = 'a' + j;
          break;
        }
      }
    }
    charset = {}; // empty it
  }
  return temp;
}

int main()
{

  string s = "rd?e?wg??";
  cout << solve(s);
  return 0;
}