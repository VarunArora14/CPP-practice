// https://www.youtube.com/watch?v=UcoN6UjAI64
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

void reverse_bit(uint32_t n)
{
  uint32_t result = 0;

  for (int i = 0; i < 32; i++)
  {
    // from end with i=0, add 1 to res if n>>i is 1
    // leftshift res for next ith bit to seen from end which gets put at start of res to reverse the bits
    result = (result << 1) + (n >> i & 1);
    // this is better as if we do the below we get for input 4(100) we get ans as 1(001) for above but 2(0010) for below as we move to right later and not
    // at the same time

    // result += (n >> i & 1);
    // result = result << 1;

    cout << "now result is " << result << "\n";
  }
  cout << result;
}

int main()
{
  uint32_t n = 4;
  reverse_bit(n);
  return 0;
}

/*
Given 1000 make it 0001 or given 1101, make it 1011 by changing the last bit to the first bit.

For this, we keep checking the ending bits of number n with help of loop where we do (n>>i & 1) where n>>i rightshifts i bits where i=0 means no
shift. val & 1 compares the last bit of val with 1 to check whether set or not.

n>>i & 1 will check if the ith bit is 1 or not and based on that we operate.
Idea is to start with res=0 and starting at i=0 we do res = res + (num>>i & 1) which is adding value of ith bit from end to res and then do
res<<1 which is leftshift so that once ith bit from end is inserted in res, we left shift 0 at end of res to reverse the bits
*/