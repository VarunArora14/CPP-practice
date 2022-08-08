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

int main()
{

  return 0;
}

/*
Given there are N cakes in a line and array of tastes(N), she wants to eat till she gets M total taste and in this comes another small
change that she can make max K distinct subarrays of tastes and in those she wants to choose min possible number of cakes
The total taste she wants is M and to get this, we can make K unique subarrays and add their taste together

Consider [5,3,2,2,3,10] and M=20 for this we create subarrays [5,3,2] and [10] and min cakes she eats is 1([10]).

One way can be to create all the distinct subarrays and map their sum as key to their subarray length. m1[arr_sum] = len
we can do better by doing m1[arr_sum] = min(m1[arr_sum], curr_len);

Once this is done, we will have map of sum associated with min len subarrays, now we traverse all these sums by pushing them in a vector
Idea is we choose 1 to k elements from this sum and see if they satisfy the ans.
k=1, find in vector sum[i] where sum[i]==M and use it's m1[sum[i]]

k=2, do k=1 first and then find 2 sum[i] and sum[j] as they add to M and use it's m1[sum[i]] which has min subarray len and store it in another
variable for comparison

To create all distinct subarrays, we have to create a suffix tree => https://stackoverflow.com/questions/17513359/number-of-distinct-subarrays
*/