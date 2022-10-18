#include <iostream>
#include <vector>
using namespace std;

int main()
{

  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int sum = 0;
  for (int val : nums)
    sum += val;
  cout << "sum is " << sum;
  return 0;
}