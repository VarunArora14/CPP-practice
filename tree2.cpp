#include<iostream>
#include<queue>
using namespace std;

struct tree2
{

    
public:
  int val;
    tree2* left;
    tree2* right;
  
}*root,*ptr;

tree2* create(int i)
{
    ptr=new tree2;
    ptr->val=i;
    ptr->left=nullptr;
    ptr->right=nullptr;
    return ptr;
}
int max1(tree2* t)
{
    if(t==nullptr)
    cout<<"the tree is empty";
    while(t->right!=nullptr)
    {
        t=t->right;

    }
    return t->val;
}

int min1(tree2* t)
{
    if(t==nullptr)
    cout<<"the tree is empty";
    while(t->left!=nullptr)
    {
        t=t->left;

    }
    return t->val;
}

tree2* min2(tree2* roo)
{
    if(roo==nullptr)
    return;
    while(roo->left!=nullptr)
    {
        roo=roo->left;
    }
    return roo;
}

/* You just cannot initilaise values by typing if root==null then root->val=v
Since it involves pointers, correct methods of invocation have to be used which using create 
function allocating memory for the left and right pointers of the root
*/
 tree2* insert(tree2* roo, int v)
{
    if(roo==nullptr)
    {
        roo=create(v);
    }
    else if(v <= roo->val)
    {
        insert(roo->left,v);
    }
    else
    {
        insert(roo->right,v);
    }

    //since in the main function it is given as root=insert(root,n) , we have to return roo
    return roo;
    // since returning roo, it has return type node* not void
}

tree2* del(tree2* roo, int i)
{
    /* 3 cases are there bascially - 
    1. no child
    2. 1 child
    3. 2 children

    for the first case, simply remove it as delete root but since dangling pointer which may
    have its address so declare root=NULL and then at last return root.
    Now since previous call resumed of root->left=del_node(root->left,val) or for right
    and then in this case root->left =(returned root)NULL and so the node gets deleted.

    For 2nd case we have to find that element and change the pointers by just root=root-right 
    or left
    if the left child is null then the right one has to be move or shifted. For that we create
    another pointer temp/t which stores its value and depending on left==null, root=root->right
    in which value copied into the parent node and then delete temp/t

    */

    if(roo==nullptr)
    return roo;

    else if(i>roo->val) //since greater value, move to right subtree
    {
        roo->right=del(roo->right,i);
    }

    else if(i<roo->val)// since lesser value move to left subtree
    {
        roo->left=del(roo->left,i);
    }

    else
    {
        // Case1: no child
        if(roo->left==nullptr && roo->right==nullptr)
        {
            delete roo;
            // deleting removes the value in it but stores the address plus now
            //it is a dangling pointer with any value so we declare it null and return it
            roo=nullptr;
            return roo;
        }

    else if (roo->left==nullptr)
    {
        //create a new node and copy value of previous in it and change the pointers
        tree2* t; //earlier struct tree2* t;
        t=roo;
        roo=roo->right;
        cout<<t->val<<" has been deleted";
        delete t;
    }
    else if(roo->right==nullptr)
    {
        tree2* t;
        t=roo;
        roo=roo->left;
        cout<<t->val<<" has been deleted";
        delete t; 
    }
    else
    {
        //Have 2 children
        /* Here we can exchange the root to be deleted with either max value in the left
        subtree or min value in the right subtree. We choose min here sp*/

        tree2* t=min2(roo->right) ;
        roo->val=t->val;
        //Copied the value of min value in the right subtree
        /*Now the pointers of the right subtree of new roo have to be changed as node to
        be deleted and so we declare roo->right=del(roo->right,t->val) to find the value of
        node which was copied and then delete it
        */
       roo->right=del(roo->right,t->val);
           }
    
    }
    return roo;
}

void levelorder(tree2* roo)
{
    
    if(roo==nullptr)
    return ;
    queue<tree2*> q;
    q.push(roo);
    while(!q.empty())
    {
        tree2* curr=q.front();
        cout<<curr->val<<" ";
        if(curr->left!=nullptr)
        {q.push(curr->left);
        }
        if(curr->right!=nullptr)
        {
            q.push(curr->right);
        }
        q.pop(); //popping the root element
    }
}

int height(tree2* roo)
{   if(roo==nullptr)
    return -1; 
    return max(height(roo->left),height(roo->right))+1;
    
}   int count=0;
int sum(tree2* roo)//sum of nodes of tree
{   
    // to find the sum of nodes we can just do any traversal and count++
    count++;
    sum(roo->left);
    sum(roo->right);
    return count;
}

void preorder(tree2* roo)
{   
    if(roo==nullptr)
    return;

    cout<<roo->val<<" ";
    preorder(roo->left);
    preorder(roo->right);
}

void inorder(tree2* roo)
{
    if(roo==nullptr)
    return ;
    inorder(roo->left);
    cout<<roo->val;
    inorder(roo->right);
}

void postorder(tree2* roo)
{
    if(roo==nullptr)
    return;

    postorder(roo->left);
    postorder(roo->right);
    cout<<roo->val<<" ";
}
int main()
{
    int s;

}