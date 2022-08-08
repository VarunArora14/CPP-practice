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
  node *left, *right;
  int val;

  node(int val)
  {
    this->val = val;
    left = right = nullptr;
  }
};

vector<int> pre, post, in;
void traversal(node *root)
{
  stack<pair<node *, int>> st;
  st.push({root, 1});
  if (root == NULL)
    return;

  while (!st.empty())
  {
    auto it = st.top();
    st.pop();

    // this is part of pre
    // increment 1 to 2
    // push the left side of the tree
    if (it.second == 1)
    {
      pre.push_back(it.first->val);
      it.second++;
      st.push(it);

      if (it.first->left != NULL)
      {
        st.push({it.first->left, 1}); // new ele always preorder
      }
    }

    // this is a part of in
    // increment 2 to 3
    // push right
    else if (it.second == 2)
    {
      in.push_back(it.first->val);
      it.second++;
      st.push(it);

      if (it.first->right != NULL)
      {
        st.push({it.first->right, 1});
      }
    }
    // don't push it back again
    else
    {
      post.push_back(it.first->val);
    }
  }
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

  traversal(root);
  for (int i : pre)
    cout << i << " ";
  cout << "\n";

  for (int i : in)
    cout << i << " ";
  cout << "\n";

  for (int i : post)
    cout << i << " ";
  cout << "\n";
  return 0;
}

/*
we here use the fact that a node can have 3 states, 1-2-3 where 1 is when we reach it, 2 for when no left node and 3 when we have seen both left and right and are
going back upwards
If state==1 then add to preorder and state++ and push left node in stack with same state=1 as it is in preorder
if state==2  then add to inorder and state++ and if right exists, push into stack with state=1 as thats a new node in preorder rn
if state==3 simply pop
*/