#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <string>
#include <climits>

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define print3(x, y, z) cout << #x << '=' << x << ',' << #y << '=' << y << ',' << #z << '=' << z << endl
#define nline cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define pb push_back
#define sz(x) ((long long)(x).size())
#define ppb pop_back
#define ff first
#define ss second

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpii = vector<pair<int, int>>;

const int mod = 1000000007;
const int max_n = 1000000;

int maxval = INT_MIN, minval = INT_MAX;

int nullmarker = -1;

struct node
{
  int val;
  node *left, *right;
};

node *newNode(int value)
{
  node *temp = new node();
  temp->val = value;
  temp->left = temp->right = nullptr;
  return temp;
}

void inorder(node *roo)
{
  if (roo == nullptr)
    return;
  inorder(roo->left);
  cout << roo->val << " ";
  inorder(roo->right);
}

// can be done preorder as well as postorder
string serialize(node *root, vector<string> &vec)
{
  if (root == nullptr)
  {
    return "#";
  }

  string left = serialize(root->left, vec);
  string right = serialize(root->right, vec);
  string curr = to_string(root->val) + ',' + left + ',' + right;
  vec.push_back(curr);
  return curr;
}

int main()
{
  node *root = newNode(20);
  root->left = newNode(8);
  root->right = newNode(22);
  root->left->left = newNode(4);
  root->left->right = newNode(12);
  root->left->right->left = newNode(10);
  root->left->right->right = newNode(14);
  vector<string> vec;
  serialize(root, vec);

  for (auto v : vec)
    cout << v << "\n";
  return 0;
}