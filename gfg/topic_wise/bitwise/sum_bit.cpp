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

int sum(int f, int s)
{
  int s = f ^ s;     // 0^1 and 1^0 is 1(for last bit)
  int carry = f & s; // check carry bit set or not
  if (carry == 0)
    return s;
  else
    return sum(f, carry << 1);
}

int main()
{

  return 0;
}

/*
sum of 2 numbers without using arithmetic operators but bitwise
Consider 4(0100) and 2(0010). use a carry and add the last bit. We need to think in terms of bits now
1+1=2 so we want to make it 0, so we do int res= first ^ second and carry= (first&second)<<1 if both are 1 then carry= (1<<1) or 2(0010)
then we check if carry!=0
*/