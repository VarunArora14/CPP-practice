#include <iostream>
#include <stdlib.h>
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
        ptr->next = NULL;
        ptr->prev = NULL;
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

void insert2(node *n) //insert at head
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

void reverseprint()
{
    node *temp = start;
    if (temp == NULL)
        return; // empty list, exit
    // Going to last Node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Traversing backward using prev pointer
    printf("Reverse: ");
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->prev;
    }
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
    printf("Forward: ");
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
    /*  if (start == nullptr)
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
    }*/
}

void del_end()
{
    node *p;

    if (start == nullptr)
    {
        cout << "list empty";
        exit(0);
    }
    else if (start->next == nullptr)

    {
        start = nullptr;
        delete start;
        cout << "node deleted";
    }

    else
    {
        p = start;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->prev->next = nullptr;
        delete ptr;
        cout << "node deleted";
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
             /* << "5. bubble sort" << endl*/
             << "5. reverse print " << endl
             << " 6. delete tail" << endl
             << "7. delete between nodes" << endl
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

            /*   case 3:
            del();
            break;*/

        case 4:
            show(start);
            break;

        /*case 5:
            bubblesort(start);
            show(start);
            break;
*/
        case 5:
            reverseprint();
            break;

            case 6: del_end();
            break;

        default:
            cout << "no such option";
        }
        cout << "continue ? ";
        cin >> ch;
    } while (ch == 'y');

    return 0;
}
