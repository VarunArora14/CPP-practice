/* check a tree symmetric about its root and all subtrees symmetric
                5
              /   \
            7       7
          /  \    /   \
        4     9  9     4
        The above is symmetric 
*/
#include <iostream>
#include <process.h>

using namespace std;

struct node
{
    int info;
    node *left;
    node *right;
} * root, *ptr, *temp;

node *create(int n)
{
    ptr = new node;
    ptr->info = n;
    ptr->left = nullptr;
    ptr->right = nullptr;
    return ptr;
}

void insert(node *n, int i) // inserting in tree
{
    if (n == nullptr) // insert in empty
    {
        n = create(i);
    }
    else if (i < n->info)
    {
        insert(n->left, i);
    }
    else
    {
        insert(n->right, i);
    }
}


v
void inorder(node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->info;
    inorder(root->right);
}

int main()
{
    
}