#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include "unordered_set"
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

int gcd_itr(int a, int b)
{
  int minval = min(a, b);
  int gcd = 0;
  for (int i = 1; i <= minval; i++)
  {
    if (a % i == 0 && b % i == 0)
      gcd = i;
  }
  return gcd;
}

int gcd_euclid(int a, int b)
{
  // the b%a becomes the 'a' as parameter so check that
  if (a == 0)
    return b;
  return gcd_euclid(b % a, a);
}

/*
int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}
*/

// smallest number which can be divided by both numbers
int lcm(int a, int b)
{
  return (a / gcd_euclid(a, b)) * b; // avoid overflow by a*b
}

int main()
{
  cout << lcm(5, 10);
  return 0;
}