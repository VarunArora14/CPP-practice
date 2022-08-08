// https://youtu.be/dBGUmUQhjaM
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

// there will always be a reference node and for every character there will be a reference link
struct Node
{
  Node *links[26]; // each link pointing to max 26 characters of the alphabets
  bool flag = false;

  // check if current Node contains the key
  bool containsKey(char ch)
  {
    return (links[ch - 'a'] != nullptr); // if not pointing to null means true else false
  }

  // puts ch in current node's pointer
  void put(char ch, Node *node)
  {
    links[ch - 'a'] = node; // this new node is passed to the func
  }

  // node which is at the given character
  Node *get(char ch)
  {
    return links[ch - 'a'];
  }

  // set the flag as true for node
  void setEnd()
  {
    flag = true;
  }

  // return the flag value for checking if word has ended
  bool isEnd()
  {
    return flag;
  }
};

class Trie
{
private:
  // for a trie we initially require a root
  Node *root;

public:
  Trie()
  {
    root = new Node(); // constructor creating new node for each object of the class
  }

  // inserts the word in trie, tc is O(len)
  void insert(string word)
  {
    // always start with the root
    Node *node = root; // dummy node initially pointing to root

    for (int i = 0; i < word.length(); i++)
    {
      // check if word[i] not in trie or not
      if (!node->containsKey(word[i]))
      {
        // if it does not have then we create a new node and put current char in it
        node->put(word[i], new Node());
      }

      // after putting you have to move to the reference trie
      node = node->get(word[i]);
    }

    // once word is over set the flag as true
    node->setEnd();
  }

  // searches for the word in trie
  bool search(string word)
  {

    // for searching always start with root so have a pointer at that
    Node *node = root;
    int len = word.length();

    for (int i = 0; i < len; i++)
    {
      char ch = word[i];
      if (!node->containsKey(ch))
      {
        cout << "Does not contain";
        return false;
      }

      // if it contains then move to it's next char
      node = node->get(ch);
    }
    // here we cannot return true as the exact word must be there so we check if flag is true
    return node->isEnd();
  }

  // checks if prefix is in the trie from the start
  bool startsWith(string prefix)
  {
    Node *node = root; // dummy point at root
    int len = prefix.length();

    for (int i = 0; i < len; i++)
    {
      char ch = prefix[i];
      if (!node->containsKey(ch))
      {
        cout << "Does not contain for startsWith";
        return false;
      }
      node = node->get(ch);
    }
    return true;
  }
};

int main()
{

  return 0;
}
/*
First we create a TrieNode having 2 items - 1. TrieNode[26] which means each trieNode can point to 26 chars max(0 to 25) for indicating alphabets a to z
for each character and 2. isEnd bool variable to mark end of the word
This array is used to store the current character occurence and then create a new TrieNode[26] if isEnd is not true or we have not reached end of word and
move to this new TrieNode.

apple ball are 2 words then a->p->p->l->e->[empty,end=true] but for ball b->a->l->l->[empty,end=true]
Note here a does not point to 'a' of ball.

If we search for a word using trie and if end of curr_word also has the TrieNode isEnd=true then we have found that word
For search functionality we use the isEnd flag=true as necessary so that apple is not same as appl.

StartsWith functionality - Start checking from root if that char exists and go to next. If at the end of word, u stand at non-null position, it means
the curr word is a valid prefix
If you encounter a null while searching startsWith then it does not exist.
*/