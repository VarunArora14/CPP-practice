#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;
int SUM = 0;
struct node
{
    int info;
    node *left;
    node *right;
} * root, *ptr, temp;

node *create(int i)
{
    ptr = new node;
    ptr->info = i;
    ptr->left = nullptr;
    ptr->right = nullptr;
    return ptr;
}

node *insert(node *roo, int i)
{
    if (roo == nullptr)
    {
        roo = create(i);
    }
    else if (i <= roo->info)
    {
        roo->left = insert(roo->left, i);
    }
    else
    {
        roo->right = insert(roo->right, i);
    }
    return roo;
}

node *search(node *root, int i)
{
    if (root == nullptr)
    {
        cout << "empty root " << endl;
    }
    else if (root->info == i)
    {
        cout << "search succesful ";
    }

    else if (i <= root->info)
    {
        return search(root->left, i);
    }
    else
    {
        return search(root->right, i);
    }
}

int min1(node *root)
{
    if (root == nullptr)
    {
        cout << "the tree is empty";
        return -1;
    }
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root->info;
}

int max1(node *root)
{
    if (root == nullptr)
    {
        cout << "the tree is empty";
        return -1;
    }
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root->info;
}

node *min2(node *root)
{
    if (root == nullptr)
    {
        cout << "the tree is empty";
        // return ;
    }
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

int findheight(node *root) //*
{
    if (root == nullptr)
        return -1;
    return max(findheight(root->left), findheight(root->right)) + 1;
}

int sum(node *r1)
{
    if (r1 == nullptr)
        return -1;
    SUM += sum(r1->left) + 1;
    SUM += sum(r1->right) + 1;
    return SUM;
    //  return sum(r1->left)+sum(r1->right)+1;
}
/*                  Depth-wise traversal
1. Preorder - In this we first go to the root , then the left subtree and then the right subtree.
Also , while traversing , we print the data , do recursive call of root->left and root->right
succesively

2. Inorder - In this we first go to the left subtree , then the root and then the right subtree.
Also , while traversing , we recursively call root->left , print the data and then recursive
call to root->right .

3. Postorder- In this we first go to the left subtree , then the right subtree and then the 
root . Also , while traversing , we do recursive call to root->left , then root->right and then
print the data .


In all the above methods, even though we dont use any other data structure like queue , 
here we have to allocate the stack memory for the function for the recursive calls of the 
fuction . This is dependent on the height of the binary tree and so space complexity is
O(h) - here h is the height of the binary tree .

The inorder traversal of the binary tree is also termed as binary search tree as it would
give elements in the sorted order.

Time complexity of all these is O(n) because it traverses all the nodes only once .

*/

void preorder(node *root)
{
    if (root == nullptr)
        return;

    cout << root->info << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->info;
    inorder(root->right);
}

void postorder(node *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->info;
}

/*
Inorder to check for the binary tree we could traverse the binary tree from root to the nodes
recursively and check whether the node->left is less than node and node->right is greater
than the node , i.e. , check for each subtree for a binary tree.


bool isbst(node *root)
{
if(root==nullptr)
{
    return true;
}
if( issubtreeless(root->left,root->data)&& issubtreegreat(root->right,root->data)&& 
isbst(root->left) && isbst(root->right))
return true;

else return false;
}


bool issubtreegreat(node *root,int val)
{
    if(root==nullptr)
    return true;

if(root->data > value && issubtreegreat(root->left,val) && issubtreegreat(root->right,val)) 
// THe above checks for all the nodes on right to bre greater than its parent node
return true;
else
return false;
}

bool issubtreeless(node *root,int val)
{
    if(root==nullptr)
    return true;

if(root->data < value && issubtreeless(root->left,val) && issubtreeless(root->right,val))
// THe above checks for all the nodes on left to bre lesser than its parent node
return true;
else
return false;
}


Now , this could turn out to be problematic as many times recursion and on the same node it 
checks for different values so it is not a great idea.

We can do something different...If while moving across the nodes we check that the nodes values
are in bounds of the values , it could be easy.
root node can have any value(INT_MIN,INT_MAX)
root->left can have value(INT_MIN,root>data)
root->right can have value(root->data,INT_MAX) // greater than root->data and less than INT_MAX

Do the above recursively as an IF statement

so, now the new code for checking the bst(binary search tree) is - 

bool isbstutil(node *root, int minval , int maxval)
{
    if(root==nullptr)
    return true;

    if(root->data < minval && root->data > maxval && isbstutil(root->left,minval,root->data)
     && isbstutil(root->right,root->data,maxval))
     return true;

     else return false;
}

bool isbst(node *root)
{
    return bstutil(root,INT_MIN,INT_MAX);
}

So in this rather than checking subtrees separately for bst and then checking all nodes to be
lesser we just use two int variables for checking the upper and lower bounds of these values
for the coditions of bst.

Time complexity in this is O(n) as we check for each node only once.
Previous was O(n*n)

** First thing which came in my mind was just doing the inorder traversal and find the 
increasing order. So, we just have to find a way in which O(n) recursive time does not 
take place by taking two int variables for measurement by just keeping teack of previously 
read node and data in next node greater than previous read data.
*/

node *del_node(node *root, int info);
void levelorder(node *root) // orders the tree and outputs it
{

    /*First it takes the node which is the root at start and puts it in the queue . Then it 
    shows the queue data and takes its children's addresses into the queue and then displays them
    again taking their children's addresses one by one . First it takes the left node's address
     then the right one's . Then it shows left node data and enqueues its left and right
     children's addresses and so now the queue has the parent right node and the children of
     left node parent . Then the parent right node data shows and its children's data is
     enqueued and is in the order from left to right breadth-wise in a binary tree
     */

    if (root == nullptr)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    //till there is at least one discoverable node
    while (!q.empty())
    {
        node *curr = q.front(); // pointer to node which gives the front element to the curr
        cout << curr->info << " ";
        if (curr->left != nullptr)
            q.push(curr->left); // push curr->left node into the queue
        if (curr->right != nullptr)
            q.push(curr->right); // push curr->right node into the queue
        q.pop();                 // now remove the first element from the queue after putting
        // its child nodes as the node has now been visited and data displayed
    }
}

node *del_node(node *root, int info) // not void but node* as error void ought to be came
//because fn returned root and so, node* del_node(args) , not void del_node(args)
{
    if (root == nullptr)
        return root;// return root and not say that tree is empty as recursion
    else if (info > root->info) // right subtree
    {
        root->right = del_node(root->right, info); // recursive call and at point of delete,
        // declares root->right passed in function as null and then initial root->right becomes null
    }
    else if (info < root->info)
    {
        root->left = del_node(root->left, info);
    }
    //the root of the left child may change after recursion but the good thing is that by adding
    // root->left=del_node(root->left,info) will return address of modified root of subtree
    else // for the info = root->info
    {
        //case 1: no child
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root; // deleting removes the value in it but stores the address plus now
            //it is a dangling pointer with any value so we declare it null and return it
            root = nullptr;
            return root;
        }

        // case 2: one child
        else if (root->left == nullptr)
        {
            /* in this we store the node value in another node ,  we do not move
     //*    to right as root->right but change the pointer from root to root->right so now at
         that location 3 is there and not 6 as it hs been stored in another pointer and deleted
        and then return the root pointer with deleting the temporary node
        */

// We change the root to root->right which means now root has values/attributes of root->right
       //which means its left and right are same as root->right. The root will then be returned and 
       //tree maintained
            struct node *t = root;
            root = root->right;
            cout << t->info << " has been deleted";
            delete t; //initially delete temp so error - changed to delete t
            /*
                16
              /    \
            6        17
              \
               13 

         Here left child is null and right child is there so to delete 6 we move 6->right to 13
         


            */
        }

        else if (root->right == nullptr)
        {
            /* in this we store the node value in another node , move to right as root->left 
        and then return the root pointer with deleting the temporary node
        */
            struct node *t = root;
            root = root->left;
            cout << t->info << " has been deleted";
            delete t;
        }
        // Case 3: with 2 children
        else
        {
            /*
        In this we can do 2 things . Before that, one thing which may cme in our mind is 
        that we may just remove that node and then we can change positions but that's not
        possible as while changing them, the bst property needs to be checked and put in back
        again for both the left and right subtrees due to various cases . 
        So the improved solution is to find
        1. min value from the right subtree(with only one or no children)
        2. max value from left subtree(with only one or no children)

        Place them in place of deleted value and then remove the duplicate value from the child's
        place and adjust it as it becomes one or no child case.
        */

            // I am finding the min element in the right subtree

            struct node *t = min2(root->right); // the min
                                                /*
        Here we have to create min1 fn which returns minimum values node*. Initial min1
        created returned the value so new fn to be created.
        */
            root->info = t->info;
            //set the data in node to be deleted as min of right subtree
            root->right = del_node(root->right, t->info); //*

            /*
The above step is a crucial one as it follows recursive movement 
deleting 5
Consider this   5   -                          
               / \
              3   7     -> minimum 7 found and value put in root(here)
             /   / \       del_node() is passed with pointer of "7" and value 7
            1   6   9    

              
                7
               / \
              3   7     -> Intermediate with 7 value. Now since "7" on right subtree has
             /   / \       2 children, else condition is met and again min is found
            1   6   9    



                7
               / \
              3   9     -> here the min is 9 which is then copied into the previous "7"
             /   / \       pointer and root->right=del_node("9" pointer,9) is made.
            1   6   9    now last child 9 has no children so first condition met return null

                7
               / \
              3   9     ->  the function had returned null pointer and now the root->right
             /   / \        became null and that is right of "9" pointer. This is how 
            1   6   null    recursively deletion is done

*/
        }
    }
    return root; // since has to be done in all statements
}

int main()
{
    root = nullptr;
    char ch = 'y';
    int x, n, y;
    do
    {
        cout << "you have following choices - " << endl
             << "1. insertion " << endl
             << "2. search" << endl
             << "3. minimum element " << endl
             << "4. max element" << endl
             << "5. Height " << endl
             << "6. Preorder traversal" << endl
             << "7. Inorder Traversal " << endl
             << "8. Postorder Traversal " << endl
             << "9. Delete node " << endl
             << "10. Level Order Traversal " << endl
             << " 11. Sum of nodes " << endl
             << "12. Exit " << endl;
        cout << "enter your choice ";
        cin >> x;
        system("cls");
        switch (x)
        {
        case 1:
            cout << "enter info";
            cin >> n;
            root = insert(root, n);
            /* constant-expression */
            /* code */
            break;

        case 2:
            cout << "enter the number to search ";
            cin >> y;
            search(root, y);
            break;

        case 3:
            cout << "the minimum element is  " << min1(root) << endl;
            break;

        case 4:
            cout << "the max element is " << max1(root) << endl;
            break;

        case 5:
            cout << "THe height of the tree is " << findheight(root) << endl;
            break;
        case 6:
            cout << "The preorder traversal of tree is " << endl;
            preorder(root); // do not cout<<preorder(root) as void return type
            break;
        case 7:
            cout << "The inorder traversal of tree is " << endl;
            inorder(root);
            break;
        case 8:
            cout << "The postorder traversal of tree is " << endl;
            postorder(root);
            break;
        case 9:
            cout << "enter info to be deleted";
            int info;
            cin >> info;
           root= del_node(root, info); //problem*
           // works even with del_node(root,info) but since returns root, this preferred
           // as the root address may change in memory
            break;
        case 10:
            levelorder(root);
            break;
        case 11:
            cout << sum(root);
            break;
        case 12:
            exit(0);
        default:
            cout << "no such value exists";
        }
        cout << "do you want to continue ? ";
        cin >> ch;
    } while (ch == 'y');
}
