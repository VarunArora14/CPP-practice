#include <iostream>
#include <stdlib.h>
#include<process.h>
using namespace std;

struct node
{
    int info;
    node *next;
} * start, *rear, *ptr, *newptr, *temp;

node *create(int i)
{
    ptr = new node;
    ptr->info = i;
    ptr->next = nullptr;
    return ptr;
}
void insert1(node *n) //insert at head
{
    if (start == nullptr)
    {
        start = rear = n;
    }
    else
    {
        temp = start;
        start = n;
        start->next = temp;
    }
}

void insert2(node *n)
{
    if (rear == nullptr)
    {
         rear = n;
    }
    else
    {
        rear->next = n;
        rear = n;
    }
}

void del()
{   
    if(start==nullptr)
    {
        cout<<"list empty";
        exit(1);
    }
    temp = start;
    start = start->next;
    cout << "deleted pointer is " << temp->info;
}

void show(node *n)
{
    if (start == nullptr)
    {
        cout << "empty list";
    }
    else
    {
        while (n->next != nullptr)
        {
            cout << n->info << "->";
            n = n->next;
        }
        cout << n->info;
    }
}

/*for bubble sort 3 functions -
 1. insertbegin - for inserting at head    
 2. bubble sort - sorting list by bubble sort
 3. swap(a,b) - swap data of 2 nodes
*/
void bubblesort(node *n)
{
    struct node *b, *f, *i;
    int p;
    for (i = n; i->next != nullptr; i = i->next)
    {
        b = n;
        f = n->next;
        while (f != nullptr)
        {
            if (b->info > f->info)
            {
                p = b->info;
                b->info = f->info;
                f->info = p;
            }
            b = f;
            f = f->next;
        }
    }
}
int main()
{
    int x, i;
    char ch = 'y';
    start = rear = temp = ptr = newptr = nullptr;
    system("cls");
    do
    {
        system("cls");

        cout << "choices - " << endl;
        cout << "1. insert head" << endl
             << "2. insert tail" << endl
             << "3. delete head" << endl
             << "4. show" << endl
             << "5. bubble sort" << endl
             << "enter - " << endl;
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "enter info";
            cin >> i;
            newptr = create(i);
            insert1(newptr);
            show(start);
            break;

        case 2:
            cout << "enter info";
            cin >> i;
            newptr = create(i);
            insert2(newptr);
            show(start);
            break;

        case 3:
            del();
            break;

        case 4:
            show(start);
            break;

        case 5:
            bubblesort(start);
            show(start);
            break;

        default:
            cout << "no such option";
        }
        cout << "continue ? ";
        cin >> ch;
    } while (ch == 'y');

    return 0;
}
