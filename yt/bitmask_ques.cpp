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
vvi cost(21, vi(21));          // max 20*20 matrix
vvi dp(21, vi((1 << 21), -1)); // 21*2^21 mask where max number of elements=20 and each mask is used to represent a subset, all -1 at start
int counter;

// top down memoization solution
int solve(int i, int mask, int &n)
{
  counter++;

  // function called n times here
  if (i == n)
    return 0;

  // memoization
  if (dp[i][mask] != -1)
    return dp[i][mask];

  int ans = INT_MAX;
  // for each job, try every person and assign the minimum to ith job

  // n times here
  for (int j = 0; j < n; j++)
  {

    // check if jth person is not given job before and can be given job now
    if (mask & (1 << j))
    {
      ans = min(ans, cost[i][j] + solve(i + 1, (mask ^ (1 << j)), n)); // take min of ans and solution for next jobs assigned
      // where we remove jth person from subset and check for i+1 to N jobs trying to assign other people
    }
  }
  return dp[i][mask] = ans; // store the best ans for current mask and return value as well while backtracking
}

int main()
{
  int t = 1;
  counter = 0;
  int n;
  while (t--)
  {

    cin >> n;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> cost[i][j];
      }
    }
    // 1<<n -1 means set all n bits to 1 like 11111...11 as 2^21 is 1000...00(20 0's)
    cout << solve(0, (1 << n) - 1, n) << "\n"
         << counter;
  }

  return 0;
}

// Space Complexity => O(n2^n) as n is number of people and jobs and 2^n represents subsets we have to try, n is the first dimension as we make dp[21][1<<21]
// n to represent jobs and 2^n is possible subsets of people

// Time Complexity - O(n^2 * 2^n) bcos we have transition time where we try out all the jobs on line 54 where we calculate the minimum cost in addition
// to calculating the subsets (2^n) and jobs(i => total n) so
// n times check for people existing in subset for ith job(line 54) * 2^n subsets to try * n jobs at max to consider to find solutions(i from 0 to n)

// We start with n elements and then after loop we have n-1 elements left all of which come under possible subsets