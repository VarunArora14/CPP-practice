#include "iostream"
#include "queue"
using namespace std;

int SUM = 0;
class node
{
  // by default private
public:
  int val;
  node *left, *right;
};

node *create(int inf)
{
  node *ptr = new node;
  ptr->val = inf;
  ptr->left = nullptr;
  ptr->right = nullptr;
}

void preorder(node *roo)
{
  if (roo == nullptr)
    return;
  cout << roo->val << " ";
  preorder(roo->left);
  preorder(roo->right);
}

void inorder(node *roo)
{
  if (roo == nullptr)
    return;
  inorder(roo->left);
  cout << roo->val << " ";
  inorder(roo->right);
}

void postorder(node *roo)
{
  if (roo == nullptr)
    return;
  postorder(roo->left);
  postorder(roo->right);
  cout << roo->val << " ";
}

node *insert(node *roo, int inf) // recursively move in a way that we find the position to insert in and then return roo
{
  if (roo == nullptr) // create root node
    roo = create(inf);

  if (roo->val > inf) // move to left
  {
    insert(roo->left, inf);
  }
  else
  {
    insert(roo->right, inf);
  }
  return roo;
}

void find(int inf, node *roo)
{
  if (roo == nullptr)
    cout << "empty root";
  else if (roo->val == inf)
  {
    cout << "search successful";
  }
  else if (roo->val < inf)
  {
    find(inf, roo->right);
  }
  else
  {
    find(inf, roo->left);
  }
}

int max1(node *roo)
{
  if (roo == nullptr)
    cout << "The tree is empty";
  else
  {
    while (roo->right != nullptr)
    {
      roo = roo->right;
    }
    return roo->val;
  }
  return -1;
}

int min1(node *roo)
{
  if (roo == nullptr)
    cout << "empty tree";
  else
  {
    while (roo->left != nullptr)
    {
      roo = roo->left;
    }
    return roo->val;
  }
  return -1;
}

node *min2(node *roo) // return the node and not just value
{
  if (roo == nullptr)
    cout << "empty tree";
  else
  {
    while (roo->left != nullptr)
    {
      roo = roo->left;
    }
    return roo;
  }
}

int tree_height(node *roo)
{
  if (roo == nullptr)
    return 0;
  return max(tree_height(roo->left), tree_height(roo->right)) + 1;
}

// number of elements
int sum_ele(node *roo)
{
  if (roo == nullptr)
    return -1;
  SUM += sum_ele(roo->left) + 1;
  SUM += sum_ele(roo->right) + 1;
}

void level_order(node *roo)
{

  if (roo == nullptr)
  {
    cout << "empty tree. exiting...";
    exit(0);
  }
  queue<node *> q;
  q.push(roo);
  while (!q.empty())
  {
    node *curr = q.front();
    cout << curr->val << " ";
    if (curr->left != nullptr)
      q.push(curr->left);
    if (curr->right != nullptr)
      q.push(curr->right);
    q.pop();
  }
}

node *delnode(node *roo, int val)
{
  if (roo == nullptr)
  {
    // cout << "tree is empty. exiting...";
    // exit(0);
    // don't say that the tree is empty bcos of recursion in this function
    return roo;
    // outputs nothing as the val is null
  }
  // finding the ele with value
  if (val > roo->val)
  {
    roo->right = delnode(roo->right, val); // store the valur being returned
  }
  else if (val < roo->val)
  {
    roo->left = delnode(roo->left, val);
  }
  else // when val==roo->val
  {
    // check for cases
    // case 1 when left and right both null
    if (roo->left == nullptr && roo->right == nullptr)
    {
      delete roo;
      roo = nullptr; // avoid dangling pointer as it just removes the value
      return roo;
      // if this was the max element then roo->right = null for if(val>roo->val) and the roo called recursively will become the new max
    }
    else if (roo->left == nullptr) // left empty, right not
    {
      node *temp = roo;
      roo = roo->right;
      cout << temp->val << " has been deleted.\n";
      delete temp;
    }
    else if (roo->right == nullptr) // right empty, left not
    {
      node *temp = roo;
      roo = roo->left;
      cout << temp->val << " has been deleted. \n";
      delete temp;
    }
    // when both have values, find the min from right subtree or max from left subtree and replace roo with that and remove the max/min node
    else
    {
      node *temp = min2(roo->right); // finding min of right subtree
      roo->val = temp->val;
      // now we delete the temp node making this condition to case 1 or 2
      roo->right = delnode(temp, roo->val);
    }
  }
  return roo;
}

int main()
{
}