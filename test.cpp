#include "iostream"
#include "queue"
#include "algorithm"
#include "bitset"
using namespace std;

int main()
{
  int n = 5;
  cout << bitset<8>(-n) << "\n"
       << bitset<8>(n);
}

// (n & -n) gives last set bit of a number by converting it to number with last set bit
// it is same as (n & (n-1))