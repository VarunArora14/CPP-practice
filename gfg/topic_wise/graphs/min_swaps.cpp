// https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
// https://www.interviewbit.com/blog/minimum-swaps-problem/
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
the imp thing here is that there are n elements from 1 to n and so we can view these elements connected to each other like graph
elements in cycles.
graph is made up of many non-intersecting cycles where edge from current node to the index it should be at
To form the graph, we need to know at what position will the current element go in the final array
Store the Pair of (elements, indexes) in a list.
Sort the list on the basis of the first entity (elements).
Using the indexes of the sorted list and the original list, we can add the edges for the graph.
*/