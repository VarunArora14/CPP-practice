#include "iostream"
#include "algorithm"
#include "cmath"
using namespace std;

// sort() functionality - Let's say you have various time intervals being given like i1(2,6), i2(3,7), i3(6,9), i4(5,4) and we have to sort this on basis of start
// time. For that you will have to make a custom func as time not a data-type in cpp
// struct interval
// {
// int st, et;
// };
// now, you can compare the intervals using a user-defined compare() function bcos interval is a structure with 2 datas and then use that function's result
// for the sort() as well bcos it takes compare function too. Make sure that the function returns bool value and not something else

// bool compare(interval i1, interval i2)
// {
// here we compare only the starting time for example
// since i1 comes before i2 and we want smaller to be first and then the bigger so => increasing order
// return i1.st > i2.st;
// returns true if i1={3,4} and i2={4,6}
// }

int main()
{
  // interval arr[] = {{6, 4}, {3, 5}, {4, 6}, {8, 13}};
  // int a[] = {1, 3, 4, 2, 7, 5};
  // sort(arr, arr + 4, compare); // the sort function in algorithm sorts array from start to end pointer which is a+end_point
  // for sort in decreasing order use greater<int>() => sort(a, a + 6, greater<int>());
  // if we do sort(a+2,a+6) => it sorts as {1, 3, 2, 4, 5, 7}

  // for (int i = 0; i < 4; i++)
  // {
  //   cout << arr[i].st << ":" << arr[i].et << "\n";
  // }

  // We also have binary search algo from algorithm headerfile
  int a[] = {1, 2, 3, 5, 7, 8};
  // cout << binary_search(a, a + 6, 9);
  // make sure the list is in increasing order

  // to know the index, we have lower_bound(arr,arr+n,val) where we get the pointer to that position
  // cout << lower_bound(a, a + 6, 2);
  // to get the index, we have [1,2,3,4,5] where lower_bound(a,a+n,3) gives us (arr+2) pointer(as 3 on the 2nd position).
  // to get the index we have to do (arr+2) - (arr) or lower_bound(...) - arr
  // cout << lower_bound(a, a + 6, 5) - a;
  // if the lower_bound() is unable to find the element then it returns the pointer to next element so in the
  // above array, it will return the pointer of 5 if we find lower_bound(a,a+n,4)
  // for multiple occurences, it returns the first instance

  // There is also upper_bound() similar to lower_bound() which returns the pointer to the next element of the array, so if we search 3, we get pointer to 5
  // cout << upper_bound(a, a + 6, 5) - a;
  // this returns 4 which is index of 7 here

  // gcd - greatest common divisor
  // cout << gcd(10, 6);

  // pow()
  // cout << pow(2, 5);
  // pow(2.2,5) returns long double

  // swap() to swap 2 ele -> utility.h
  // int x = 5, y = 4;
  // cout << x << ":" << y << "\n";
  // swap(x, y);
  // cout << x << ":" << y;

  // maximum - max() and min() -> utility.h
  // cout << max(100, 690) << ": " << min(420, 1000);

  return 0;
}