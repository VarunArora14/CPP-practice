#include "iostream"
#include "set"
#include "map"
#include "unordered_map"

using namespace std;

int main()
{ // pair is like linkedlist with 2 values and can have repetition unline key-value pairs of maps. Search takes O(n) unline map which takes O(log n)
  // pair<int, int> p;
  // p = make_pair(1, 5);
  // pair<int, int> q(2, 6);
  // cout << p.first << " " << p.second << "\n"
  //      << q.first << " " << q.second;

  // set is a list of values without any repetition generally used to see if there is no repetition in an array/list of elements
  // set<int> s;
  // int a[] = {1, 2, 3, 4, 5, 6, 5};
  // for (int i = 0; i < 7; i++)
  // {
  //   s.insert(a[i]);
  // }

  // set<int>::iterator i;
  // for (i = s.begin(); i != s.end(); i++)
  // {
  //   cout << *i << " ";
  //   // no repetition included
  // }
  // // we have another function called find() for set which returns an iterator
  // if (s.find(41) != s.end())
  // {
  //   cout << "\nele found";
  // }
  // else
  // {
  //   cout << "\nnot found ele";
  // }
  // set is implemented in cpp using a balanced bst taking O(log n) time for search

  // MAP
  // To store key-value pairs. Let's say we have array where nums are getting repeated, and we want to store the occurences of each
  // {1,2,3,4,1,1,3} => 1->3, 2->1, 3->2, 4->1
  // unordered_map<int, int> map1;
  // int a[] = {1, 2, 3, 4, 5, 6, 5};
  // for (int i = 0; i < 7; i++)
  // {
  //   map1[a[i]] = map1[a[i]] + 1;
  //   //map1[a[i]] means map1[1] for a[0]=1. The map1[a[i]]++ increases the count from 0 or we can do map1[a[i]]=map1[a[i]]+1;
  //   // all map values initialise at 0 we can use map iterator for movement
  // }
  // unordered_map<int, int>::iterator it;
  // for (it = map1.begin(); it != map1.end(); it++)
  // {
  //   cout << it->first << ":" << it->second << "\n";
  // }
  // map1.erase(5); // erases the key of value 5 and it's value

  // cout << "\n";
  // for (it = map1.begin(); it != map1.end(); it++)
  // {
  //   cout << it->first << ":" << it->second << "\n";
  // }

  // maps are implemented through bst meaning O(log n) insert, delete and search.

  // There is another map called unordered_map which uses hash table an NOT bst. This means the find, insert and delete takes O(1) avg time in unordered_map
  // the worst case is O(1)
  // replace the word map with unordered_map in the program and vice versa
  // Note the order in which elements are entered is not same as stored/shown on output bcos it is unordered bcos it does not save the order of the elements

  // Other common DS stl are list(implemented using doubly ll), stack, queue, priority_queue.
  // Use them based on the problem saked to be solved
}