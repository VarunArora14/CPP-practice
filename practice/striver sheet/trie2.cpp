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

struct Node
{
  Node *links[26];
  bool flag = false;

  // checks if current char in the Node
  bool containsChar(char ch)
  {
    return (links[ch - 'a'] != nullptr);
    // pointing to nullptr means the char not in the trie
  }

  // creates a new Node and assigns it to the given char
  void put(char ch, Node *newnode)
  {
    links[ch - 'a'] = newnode; // make the current char have the value of this new node
  }

  // move to the next node if it exists
  Node *get(char ch)
  {
    return links[ch - 'a'];
  }

  // make the flag true for last node
  void setEnd()
  {
    flag = true;
  }

  // checks for end of word
  bool isEnd()
  {
    return flag;
  }
};

class Trie
{
private:
  Node *root;

public:
  Trie()
  {
    root = new Node();
  }
  // insert the word in the trie
  void insert(string word)
  {
    int len = word.length();
    Node *node = root; // dummy node for searching and assigning values

    for (int i = 0; i < len; i++)
    {
      char ch = word[i];
      if (!node->containsChar(ch))
      {
        // add to it as we are inserting, create a new node and pass it
        node->put(ch, new Node());
      }
      node = node->get(ch);
    }

    // once node at last empty node, we set that node's flag as true
    node->setEnd();
  }

  bool search(string word)
  {
    int len = word.length();
    Node *node = root; // dummy node for searching and assigning values

    for (int i = 0; i < len; i++)
    {
      char ch = word[i];
      // takes care of finding the char as well as nullptr
      if (!node->containsChar(ch))
      {
        cout << "Search not succesful";
        return false;
      }
      node = node->get(ch);
    }

    // for word to be found, we have to check if current node has flag=true
    return node->isEnd(); // if flag=true meaning word has ended then search successful otherwise not
  }

  bool startsWith(string prefix)
  {
    int len = prefix.length();
    Node *node = root; // dummy node for searching and assigning values

    for (int i = 0; i < len; i++)
    {
      char ch = prefix[i];
      // takes care of finding the char as well as nullptr
      if (!node->containsChar(ch))
      {
        cout << "Search not succesful";
        return false;
      }
      node = node->get(ch);
    }
    return true; // if we havent found a nullptr till now it means there is a prefix
    // whether it is complete word or just prefix does not matter here
  }
};

int main()
{
  int n = 5;
  vector<int> type = {1, 1, 2, 3, 2};
  vector<string> value = {"hello", "help", "help", "hel", "hel"};
  Trie trie;
  for (int i = 0; i < n; i++)
  {
    if (type[i] == 1)
    {
      trie.insert(value[i]);
    }
    else if (type[i] == 2)
    {
      if (trie.search(value[i]))
      {
        cout << "true"
             << "\n";
      }
      else
      {
        cout << "false"
             << "\n";
      }
    }
    else
    {
      if (trie.startsWith(value[i]))
      {
        cout << "true"
             << "\n";
      }
      else
      {
        cout << "false"
             << "\n";
      }
    }
  }
}