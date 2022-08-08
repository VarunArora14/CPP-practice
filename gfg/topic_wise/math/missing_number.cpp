// https://www.geeksforgeeks.org/find-the-missing-number/

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

// take the sum till n by formula n(n+1)/2 and then keep reducing the numbers
int sol1(int n, vi &vec)
{
  // since we passed the length of vec, we must  find sum till n+1
  n = n + 1;
  int maxval = n * (n + 1) / 2;

  for (int &i : vec)
    maxval -= i;
  return maxval; // it only has the missing number

  // Time is O(n) and const space
}
// problem with the above approach is that if n very large, the maxval can cross limits
// instead we can take xor of all nums till 1 to n and then of all nums in vec. Since xor or 1 and 1 is 0, at the end we will have only the
// remaining number left

int sol2(int n, vi &vec)
{
  int val1 = 1, val2 = vec[0];

  for (int i = 1; i < n; i++)
    val2 = val2 ^ vec[i];

  for (int i = 2; i <= n + 1; i++)
    val1 = val1 ^ i;

  return (val1 ^ val2);
}

int main()
{
  vi vec = {1, 2, 3, 5, 6, 7};
  int n = vec.size();
  cout << sol1(n, vec) << " " << sol2(n, vec);
  return 0;
}

/*
given nums 1 to n, find the missing number
*/