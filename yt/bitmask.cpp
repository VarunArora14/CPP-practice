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

void add(int &subset, int x)
{
  subset = subset | (1 << (x - 1)); // to add 7, we set the 6th bit as on to represent the subset={1,2,3,4,7} if subset=15
}

void display1(int subset)
{
  int count = 1;
  while (subset)
  {
    if (subset & 1)
    {
      cout << count << " ";
    }
    count++;
    subset = subset >> 1; // go one bit right
  }
}

void display2(int subset, int n = 10)
{
  // pass the number of elements n so we consider n bits, here we assume 10
  for (int i = 0; i < n; i++)
  {
    // check if ith bit on using AND operator
    if (subset & (1 << i))
    {
      cout << i + 1 << " "; // print the position of bit from right(starting from 1 not 0)
    }
  }
}

void remove(int &subset, int x)
{
  // remove element x from subset(by turning the bit off)
  // for this xor the bit at xth position to turn it off as 1^1=0
  subset = subset ^ (1 << (x - 1));
  // cout << (bitset<10>)subset << "\n";
}

int main()
{
  // here we represent a subset in form of number where we can use max 32 bits for integer and subset is represented like this
  // 00010001 => has signed bits at position 0 and 4(from right side view) which can be used to represent numbers 1 and 5 making subset {1,5}
  // in form of integer 17(10001)

  int subset = 15;
  // cout << "enter number to check subsets: ";
  // cin >> subset;
  remove(subset, 2);
  remove(subset, 4);
  add(subset, 7);
  display2(subset);
  cout << "\n";
  cout << (bitset<10>)subset;
  return 0;
}

// Kartik arora yt => https://www.youtube.com/watch?v=7FmL-WpTTJ4