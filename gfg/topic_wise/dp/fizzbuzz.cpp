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

void sol()
{
  for (int i = 1; i <= 100; i++)
  {
    string val = "";
    if (i % 3 == 0)
      val += "Fizz";
    if (i % 5 == 0)
      val += "Buzz";
    if (i % 7 == 0)
      val += "Bazz";

    if (val == "")
      val += to_string(i);

    cout << val << "\n";
  }
}

int main()
{
  sol();
  // for (int i = 1; i <= 100; i++)
  // {
  //   if (i % 3 == 0 && i % 5 == 0)
  //   {
  //     cout << "FizzBuzz\n";
  //   }
  //   else if (i % 3 == 0)
  //     cout << "Fizz\n";
  //   else if (i % 5 == 0)
  //     cout << "Buzz\n";
  //   else
  //     cout << i << "\n";
  // }

  return 0;
}