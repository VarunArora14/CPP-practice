// https://www.geeksforgeeks.org/nth-natural-number-after-removing-all-numbers-consisting-of-the-digit-9/
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

bool isNine(int val)
{
  while (val)
  {
    if (val % 10 == 9)
      return true;
    val = val / 10;
  }
  return false;
}

// O(n) solution where we keep moving forward till count=n
int sol1(int n)
{
  int count = 0, ans = 0;
  // stop when count==n inside the loop
  for (int i = 1;; i++)
  {
    if (!isNine(i))
      count++;
    if (count == n)
    {
      ans = i;
      break;
    }
  }
  return ans; // nth natural number without 9 as those are skipped. i keeps moving till the condition satisfied and can only have problem with overflow
}

// Another solution with O(log9 n) (base 9) which finds
long long sol2(long long N)
{
  // Stores the Nth number
  long long result = 0;

  long long p = 1;

  // Iterate while N is
  // greater than 0
  while (N > 0)
  {

    // Update result
    result += (p * (N % 9));

    // Divide N by 9
    N = N / 9;

    // Multiply p by 10
    p = p * 10;
  }
  // Return result
  return result;
}

int main()
{

  int n = 9;
  return 0;
}

/*
One way is to check for each number if it contains 9 then ignore it and do count-- otherwise where count=n at start for nth natural number

Other is to find base 9 numbers -
It is known that, digits of base 2 numbers varies from 0 to 1. Similarly, digits of base 10 numbers varies from 0 to 9.
Therefore, the digits of base 9 numbers will vary from 0 to 8.
It can be observed that Nth number in base 9 is equal to Nth number after skipping numbers containing digit 9.
So the task is reduced to find the base 9 equivalent of the number N.
*/