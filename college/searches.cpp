// program to perform both linear and binary search
#include "iostream"
using namespace std;

void linear_search(int[], int, int val);
void binary_search(int[], int, int val);

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int a[100], length;
  cin >> length;
  int i, j;
  for (size_t i = 0; i < length; i++)
  {
    cin >> a[i];
  }
  int val;
  cin >> val;
  // linear_search(a, length, val);
  binary_search(a, length, val);
}

void linear_search(int a[], int length, int val)
{
  bool flag = false;
  for (size_t i = 0; i < length; i++)
  {
    if (a[i] == val)
    {
      cout << "element found at position " << i + 1 << "\n";

      flag = true;
      break;
    }
  }
  if (!flag)
    cout << "element not found";
}

void binary_search(int a[], int length, int val)
{
  int start, end, mid;
  start = 0;
  end = length - 1;
  bool flag = false;
  while (start < end)
  {
    mid = (start + end) / 2;
    if (a[mid] > val)
    {
      // value less than middle element
      end = mid - 1;
    }
    else if (a[mid] < val)
    {
      // value greater than middle element
      start = mid + 1;
    }
    else
    {
      cout << "the element found at position " << mid + 1;
      flag = true;
      break;
    }
  }
  if (!flag)
    cout << "element not found";
}