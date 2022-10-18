#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <climits>
#include "numeric"
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

void solve()
{
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  vi b(n + 1);
  // base case b[0]=0 for finding gcd of a0
  b[0] = b[1] = a[0];
  if (n == 1)
  {
    cout << "YES";
    return;
  }
  for (int i = 1; i < n; i++)
  {
    b[i + 1] = a[i];         // always store the number whose gcd to be found
    int g = gcd(b[i], a[i]); // here b[i] = a[i-1]
    int diff = a[i] / g;     // uncommon factor of a[i] and gcd(a[i],a[i-1])

    b[i] = b[i] * diff; // multiply the diff so that it becomes gcd of both
  }
  // for (int num : b)
  //   cout << num << " ";
  // cout << "\n";
  bool f = false;
  for (int i = 0; i < n; i++)
  {
    if (gcd(b[i], b[i + 1]) != a[i])
    {
      f = true;
      break;
    }
  }
  if (f)
    cout << "NO";
  else
    cout << "YES";
}

// giangly solution 1736b
void solve2()
{
  int n;
  cin >> n;
  vi a(n), b(n + 1);

  for (auto &i : a)
    cin >> i;

  b[0] = a[0], b[n] = a[n - 1]; // base cases
  for (int i = 1; i < n; i++)
  {
    b[i] = lcm(a[i], a[i - 1]); // contains the common and diff factors both
  }

  for (int i = 0; i < n; i++)
  {
    if (gcd(b[i], b[i + 1]) != a[i])
    {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}

int main()
{
  // int v1 = 80, v2 = 16;
  // int diff = v1 / gcd(v1, v2);
  // cout << diff; // factor which are not in v2 but in v1
  int t;
  cin >> t;
  while (t--)
    solve2();
  return 0;
}

// here we have to check if we can create array b using array a where ai = gcd(bi, bi+1) and print Yes or No based on that
// Now gcd of 2 numbers gives the common divisor so we can find the bare minimum factors of 2 numbers
// consider a =[5,10]. Now if we have to create a new array b then b[0] = 5 as we will see later 5 and b[n-1]=10
// if these values are greater than current like b[0]=10 then if b[1]=100 their gcd(100,10) will be 10 but we want 5
// so to get the bare minimum values we have to have that number at position bi or bi+1
// now the 2nd number or b1 has to be such that using it we are able to find GCD of both ai and ai+1 as gcd(b0,b1) = a0
// and a1 = gcd(b1,b2) so here b1 has to have factors of BOTH a1 and a2

// With gcd of b0(same as a0) and a1 we get common factors of a0 and a1. HERE comes the TRICKY part
// diff = a1 / gcd(b1,a0) gives the uncommon factors of a1 and a0 using which we can build b1 as b1 = a0 and later b1*diff

// WHEN DOES THIS FAIL?
// If gcd of bi and bi+1 of this new array != a[i] then it has failed

// https://www.youtube.com/watch?v=IK38JiEokmI