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

class node
{
public:
  int val;
  node *left, *right;

  // for new node(value)
  node(int val)
  {
    this->val = val;
    left = right = nullptr;
  }
};

void bottom_view(node *roo)
{
  // we use unordered_map for mapping the nums and values as tree->val
  if (roo == nullptr)
    return;

  unordered_map<int, int> um;
  vi ans;

  // need to associate nodes with values
  queue<pair<node *, int>> q;

  q.push({roo, 0});

  while (!q.empty())
  {
    auto [curr, pos] = q.front();
    q.pop();

    um[pos] = curr->val; // pos is the key and we keep overriding it's values

    if (curr->left != nullptr)
      q.push({curr->left, pos - 1}); // -1 for left

    if (curr->right != nullptr)
      q.push({curr->right, pos + 1}); // +1 for right
  }

  // now map has all the values which are can be seen from the bottom so we print them

  for (auto &[key, val] : um)
  {
    cout << val << " ";
  }

  // we do level-order again and keep storing in the map values even if they were allready there as we want new values
  // we need a way so that we associate a node with the value as where they are at the tree considering root as centre with 0 value and left smaller and right
  // larger values
}

int main()
{
  node *root = new node(20);
  root->left = new node(8);
  root->right = new node(22);
  root->left->left = new node(5);
  root->left->right = new node(3);
  root->right->left = new node(4);
  root->right->right = new node(25);
  root->left->right->left = new node(10);
  root->left->right->right = new node(14);

  bottom_view(root);

  return 0;
}

/*
Consider a tree which has small number of leaf nodes, and we can see nodes from bottom which occur above like here -
https://takeuforward.org/data-structure/bottom-view-of-a-binary-tree/ => image here shows what we see from the bottom and work on that

To solve this, we assign a value at each where 0 is for root and as we go left we assign negative values or curr-1 for left child and curr+1 for right child
To make sure we use the final value, we use a map for value of node assigned as val where key is the number(0,-1,1 etc) and we keep changing it as we go down

At last, we print or store the map ele(values) in a vvector which is the ans
*/