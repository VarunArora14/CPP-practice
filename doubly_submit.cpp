#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct node
{
    int info;
    node *next;
    node *prev;
} * start, *rear, *ptr, *newptr, *temp;

node *create(int i)
{
    ptr = new node;
    ptr->info = i;
    ptr->next = nullptr;
    ptr->prev = nullptr;
    return ptr;
}

void insert1(node *n) //insert at head
{
    if (start == nullptr)
    {
        n->next = NULL; //ptr before
        n->prev = NULL;
        start = n;
    }
    else
    {
        start->prev = n;
        n->next = start;
        start = n;
    }
    cout << "element inserted at the head" << endl;
}

void insert2(node *n) //insert at tail
{
    if (start == nullptr)
    {
        n->next = NULL;
        n->prev = NULL;
        start = n;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
        n->next = NULL;
    }
    cout << "element inserted at the end" << endl;
}

/*void del()
{
    temp = start;
    start = start->next;
    cout << "deleted pointer is " << temp->info;
}
*/

void show(node *temp)
{
    if (start == nullptr)
    {
        cout << "empty list";
    }
    cout << "Forward: ";
    while (temp != NULL)
    {
        cout << temp->info << "->";
        temp = temp->next;
    }
    printf("\n");
}

struct node *p;

void del_end()
{

    if (start == nullptr)
    {
        cout << "list empty";
        exit(0);
    }
    else if (start->next == nullptr)

    {
        start = nullptr;
        delete start;
        cout << "node deleted" << endl;
    }

    else
    {
        node *m;
        p = start;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        m = p;
        p = p->prev;
        p->next = nullptr;
        delete m; // we can show which element is deleted  . thats why m was allocated
        cout << "node deleted at end" << endl;
    }
}

void del_start()
{
    if (start == nullptr)
    {
        cout << "the list already empty";
    }
    else if (start->next == nullptr)

    {
        start = nullptr;
        delete start;
        cout << "node deleted" << endl;
    }

    else
    {
        temp = start;
        start = start->next;
        start->prev = nullptr;
        delete temp;
        cout << "deleted at head" << endl;
    }
}

struct node *f, *a, *b;

void del_node(int w)
{

    if (start == nullptr)
    {
        cout << "the list already empty";
    }
    else if (start->next == nullptr)

    {
        start = nullptr;
        delete start;
        cout << "node deleted";
    }

    f = start;
    for (int i = 1; i < w; i++)
    {
        f = f->next;
    }
    b = f->next; //going to next pointer
    a = f->prev; //going to previous pointer

    a->next = b;
    b->prev = a; //updating positions
    delete f;
    cout << "the node at position " << w << " has been deleted ";

    show(start);
}

void insert_any(node *n, int pos)
{
    if (start == nullptr)
    {
        cout << "the list already empty";
    }

    f = start;
    for (int i = 1; i < pos; i++)
    {

        f = f->next;
    }

    b = f;       //going to next pointer as new element between f and f->prev
    a = f->prev; //going to previous pointer

    a->next = n;
    n->prev = a;
    n->next = f;
    f->prev = n;
}

int m(node *n) // this fn returns the total elements in the list
{
    int i = 0;
    while (n != nullptr)
    {
        i += 1;
        n = n->next;
    }
    return i;
}
int main()
{
    int x, i, w, pos;
    int q;
    char ch = 'y';
    start = rear = temp = ptr = newptr = nullptr;
    system("cls");
    do
    {
        // system("cls");

        cout << endl
             << "choices - " << endl;
        cout << "1. insert head" << endl
             << "2. insert tail" << endl
             << "3. insert any " << endl
             << "4. delete head" << endl
             << "5. delete tail" << endl
             << "6. delete between nodes" << endl
             << "7. show" << endl
             << "8. Exit " << endl
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
            cout << "enter the info";
            cin >> i;
            newptr = create(i);
            cout << endl
                 << "enter the position";
            cin >> pos;

            q = m(start);
            if (pos < 0 || pos > q + 1)
            {
                cout << "inavlid position " << endl;
                exit(1);
            }

            if (pos == q + 1)
            {
                insert2(newptr);
            }
            else if (pos == 1) // only if then infinite loop
            {
                insert1(newptr);
            }
            else
            {
                insert_any(newptr, pos);
            }
            show(start);
            break;

        case 4:
            del_start();
            show(start);

            break;

        case 5:
            del_end();
            show(start);

            break;

        case 6:
            cout << "enter the position";
            cin >> w;
            q = m(start);
            if (w < 0 || w > q + 1)
            {
                cout << "inavlid position " << endl;
                exit(1);
            }

            if (w == q + 1)
            {
                del_end();
            }
            else if (w == 1) // only if then infinite loop
            {
                del_start();
            }
            else
            {
                del_node(w);
            }
            show(start);

            break;

        case 7:
            show(start);
            break;
        case 8:
            exit(0);
        default:
            cout << "no such option";
        }
        cout << "continue ? ";
        cin >> ch;
    } while (ch == 'y');

    return 0;
}
