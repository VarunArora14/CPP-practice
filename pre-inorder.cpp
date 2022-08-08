/* Given an  array of preorder and inorder traversals, check whether the tree exists, output it
and show its postorder traversal.
Maybe iterative or recursive(prefer recursive)
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


void build(int pre[], int in[],  int strt , int len)
{
    int i,j,pos,flag=0,l;
    for(i=strt;i<=len;i++)
    {
        for(j=0;j<=len;j++)
        {
            if(pre[i]==in[j])
            {   l=pre[i];
                flag=1;
                pos=j;
                break;
            }
        }
        if(flag==0)
    {
        cout<<"not found node";
        exit(0);
    }
    /* now we have to put the node in the binary tree and invoke the same for its left and
    right subtrees.
    
    */
  
    }
     insert(root,l);
     build(pre,in,strt,pos-1);
     build(pre,in,pos+1,len);


}

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
    int pre[10], in[10];
    int i, j, s1;
    cout << "enter the preorder size";
    cin >> s1;
    cout << "enter the preorder";
    for (i = 0; i < s1; i++)
    {
        cin >> pre[i];
    }
    cout << "enter postorder";
    for (i = 0; i < s1; i++)
    {
        cin >> in[i];
    }
    int pos = 0, flag = 0;
    build(pre, in, 0, s1-1);
}