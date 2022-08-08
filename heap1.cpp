#include<iostream>

using namespace std;

int main()
{
    /* fns are

    1. getMax() - gets the root of the element
    2. extractMax() - extracts the root of the element but maintains the heap property O(log n)
    3.  Decreases value of key. The time complexity of this operation is O(Logn). 
        If the decreases key value of a node is greater than the parent of the node, 
        then we don’t need to do anything. Otherwise, we need to traverse up to fix the
        violated heap property.
    4. insert() -  Inserting a new key takes O(Logn) time. We add a new key at the end of 
                the tree. IF new key is less than its parent, then we don’t need to do anything. 
                   Otherwise, we need to traverse up to fix the violated heap property.

    5. delete(): Deleting a key also takes O(Logn) time. We replace the key to be deleted with
                 minum infinite by calling decreaseKey(). After decreaseKey(), the minus
                  infinite value must reach root, so we call extractMin() to remove the key.
                  */

                 

}