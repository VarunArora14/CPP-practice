#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <process.h>
using namespace std;

class node
{

public:
    int info;
    void insert1(node *);
    void insert2(node *);
    void delete1();
    void reverse(node *);
    void show(node *);

    node *next;
} * start, *last, *ptr, *newptr;

node *create(int i)
{
    ptr = new node;
    ptr->info = i;
    ptr->next = NULL;
    return ptr;
}

int main()
{
    node l;
    char ch = 'y';

    start = last = ptr = newptr = NULL;
    do
    {
        system("cls");

        cout << "Here are the following choices - " << endl;
        cout << "1. Insert top" << endl
             << "2. Insert end" << endl
             << "3. Delete top" << endl
             << "4. Reverse list" << endl
             << "5.Show list" << endl;
        cout << endl
             << "Enter choice";
        int x;
        cin >> x;
        int i;
        do
        {

            switch (x)
            {

            case 1:
                cout << endl
                     << "Enter the element";
                cin >> i;

                newptr = create(i);
                if (newptr == NULL)
                {
                    cout << "memory not allocated";
                    exit(0);
                }
                l.insert1(newptr);
                l.show(start);
                break;

            case 2:
                cout << "Enter the info";
                cin >> i;
                newptr = create(i);
                if (newptr == NULL)
                {

                    cout << "Memory not allocated";
                    exit(0);
                }
                l.insert2(newptr);
                l.show(start);
                break;
            case 3:
                if (start == NULL)
                {

                    cout << "No data in the list";
                    exit(0);
                }
                else
                {
                    l.delete1();
                    l.show(start);
                }
                break;
            case 4:
                l.reverse(start);
                l.show(start);
                break;
            case 5:
                if (start == NULL)
                {
                    cout << "Empty ";
                }
                else
                {
                    l.show(start);
                }

            default:
                cout << "No such option available . kindly do it again";
            }
            cout << endl
                 << " Continue current operation? ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');

        cout << endl
             << "Continue operations?";
        cin >> ch;
    } while (ch == 'y');
    getch();
}

void node::insert1(node *n)
{
    node *temp;
    if (start == NULL)
    {
        start = last = n;
    }
    else
    {
        temp = start;
        start = n;
        start->next = temp;
    }
}

void node::insert2(node *n)
{

    if (last == NULL)
    {

        start = last = n;
    }
    else
    {
        last->next = n;
        last = n;
    }
}

void node::delete1()
{
    node *temp;
    temp = start;
    start = start->next;
    delete temp;
}

void node::show(node *a)
{
    while (a->next != NULL)
    {
        cout << a->info << "->";
        a = a->next;
    }
    cout << a->info;
}

void node::reverse(node *head)
{

    class node *prevNode, *curNode;

    if (head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; // Make first node as last node

        while (head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode; // Make last node as head
    }
}
/*

1. Create two more pointers other than head namely prevNode and curNode that will hold the
 reference of previous node and current node respectively.
Make sure that prevNode points to first node i.e. prevNode = head.
head should now point to its next node i.e. the second node head = head->next.
curNode should also points to the second node i.e. curNode = head.

      head
        |
        v
10_ -> 20_ -> 30_ -> 40X (X means null)
 ^      ^  
 |      |
prev   curr

2. Now, disconnect the previous node i.e. the first node from others. We will make sure that it
points to none. As this node is going to be our last node. Perform operation
 prevNode->next = NULL.


3. Move head node to its next node i.e. head = head->next.

             head
               |
               v
10X    20_ -> 30_ -> 40X
 ^      ^
 |      |
prev   curr

4. Now, re-connect the current node to its previous node i.e. curNode->next = prevNode;.

                  head
                   |
                   v
10X <- 20_  30_ -> 40X
^      ^
|      |
prev   curr

5. Point the previous node to current node and current node to head node. Means they 
should now point to prevNode = curNode; and curNode = head.


                  head
                   |
                   v
10X <- 20_  30_ -> 40X
        ^    ^
        |    |
       prev curr

6. Repeat steps 3-5 till head pointer becomes NULL.

                 head
                   |
                   v
10X <- 20_ <- 30_  40X
        ^      ^
        |      |
       prev   curr

7. Now, after all nodes has been re-connected in the reverse order. Make the last node
as the first node. Means the head pointer should point to prevNode pointer. Perform head 
= prevNode;. Finally you end up with a reversed linked list of its original.
                 head
                   |
                   v
10X <- 20_ <- 30_  40X
              ^     ^
              |     |
             prev  curr


*/