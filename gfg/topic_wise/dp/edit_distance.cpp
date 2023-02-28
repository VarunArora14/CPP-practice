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

// int min(int &v1, int &v2, int &v3)
// {
//   return min(v1, min(v2, v3));
// }

int rec(string &s1, string &s2, int i, int j)
{
  // base case if we cross first element of any going left
  // consider abc and hhhhabc
  // we complete abc and then to cover 'hhhh' we return the position, +1 as 0 based indices, consider operation count vs index

  if (i < 0)
    return j + 1;
  if (j < 0)
    return i + 1;

  if (s1[i] == s2[j])
    return rec(s1, s2, i - 1, j - 1);

  return 1 + min({rec(s1, s2, i - 1, j - 1), // replace
                  rec(s1, s2, i - 1, j),     // delete
                  rec(s1, s2, i, j - 1)});   // insert
}

// the overlapping subproblems can further be stored, we use dp to find the smallest change in (i,j) indices of s1 and s2
// consider overlapping problems and building solution over it

int dp_sol(string &s1, string &s2)
{
  int n = s1.length(), m = s2.length();
  vvi dp(n + 1, vi(m + 1, -1)); // n+1*m+1

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      // base case 1
      if (i == 0)
        dp[i][j] = j; // min operations left=j as crossed 0th idx for i

      // base case 2
      else if (j == 0)
        dp[i][j] = i; // crossed 0th idx so remaining operations=i

      else if (s1[i - 1] == s2[j - 1])
        dp[i][j] = dp[i - 1][j - 1]; // same characters so continue with prev ans

      else
      {
        dp[i][j] = 1 + min({dp[i - 1][j - 1], // replace
                            dp[i][j - 1],     // insert(j-1 changes to j but i remains same, means inserted in s1)
                            dp[i - 1][j]});   // delete(i-1 changes to i but j remains same means we go to next i position or delete an element in s1)
      }
    }
  }

  return dp[n][m];
}

int main()
{
  string s1, s2;

  cin >> s1 >> s2;

  cout << rec(s1, s2, s1.length() - 1, s2.length() - 1) << "\n"; // start from last characters
  cout << dp_sol(s1, s2);
  return 0;
}

// replace in abed, abcd by (i+1, j+1) by replacing 'c' with 'e' or reverse
// delete in abecd, abcd by (i+1,j) by removing e and checking next
// insert in bcd, abcd by (i,j+1) by adding 'a' to first and then moving to next

// we do not need to do solve(s2,s1) as insert and delete operations on s1 means we go in both directions
// replace also doesnt cause problem