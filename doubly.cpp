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
        n->next = NULL;       //ptr before
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
    cout << "Reverse: ";
    while (temp != NULL)
    {
        cout << temp->info << "->";
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
        delete m;       // we can show which element is deleted  . thats why m was allocated
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

void bubble_sort()
{
    bool is_true = false; // * 
    node *temp = start;
    while (!is_true) // *
    {

        is_true = true;
        temp = start;  // * 
        while (temp->next != nullptr) // * 
        {
            if (temp->next->info < temp->info)
            {
                is_true = false;    // * 
                if (temp == start)
                {
                    start = start->next;       // 2nd pointer now start
                    node *after = start->next; // pointer of 3rd node to maintain second node next
                    start->prev = nullptr;
                    start->next = temp; //maintaing start->next and temp->prev pointers
                    temp->prev = start;
                    temp->next = after; // maintainng new 2nd pointer temp->next pointers
                    after->prev = temp; // with 3rd node prev pointers

                    temp = start->next; // * for next 2 items to sort
                }

                else if (temp->next->next == nullptr) // for the last node
                {
                    node *back, *tempnext;
                    tempnext = temp->next; // last node
                    //last=last->prev;
                    back = temp->prev;

                    temp->next = nullptr;  // now temp is tail , its next is null
                    temp->prev = tempnext; // its previous link to tempnext
                    tempnext->next = temp; // next link of tempnext to temp
                    tempnext->prev = back; // its previous link to back
                    back->next = tempnext; // the next link of back to tempnext
                }

                else
                {                                   // any node
                    node *back = temp->prev;        // back is node before temp initially
                    node *after = temp->next->next; // * after is node after temp->next initially
                    node *tempnext = temp->next;    // declaring tempnext as whole to avoid confusion

                    back->next = tempnext; // next link of back pointer to tempnext
                    tempnext->prev = back; // previous link of tempnext to back
                    temp->prev = tempnext; //previous link of temp to tempnext
                    tempnext->next = temp; // next link of tempnext to temp
                    after->prev = temp;    // previous link of after to temp
                    temp->next = after;    // next link of temp to after

                    temp = after->prev;     // * moving to next node
                }
            }
            else
            {
                temp = temp->next;
            }
        }
    }
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

int m(node *n)      // this fn returns the total elements in the list
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
        system("cls");

        cout << "choices - " << endl;
        cout << "1. insert head" << endl
             << "2. insert tail" << endl
             << "3. insert any " << endl
             << "4. delete head" << endl
             << "5. delete tail" << endl
             << "6. delete between nodes" << endl
             << "7. show" << endl
             << "8. reverse print " << endl
             << "9. bubble sort" << endl
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
            reverseprint();
            break;

        case 9:
            bubble_sort();
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

/*
   2.

   void bubblesort()
{
    node *temp = head;
    int len = length();
    for(int i=0;i<(len - 1);i++)
    {
        cout<<i<<endl;
        temp = head;
        int c=0;
        while(c<(len - i - 1))
        {
            cout<<"Temp: "<<temp->data<<" ";
            cout<<"Temp: "<<temp->next->data<<" "<<endl;
            if(temp->next->data < temp->data)
            {
                if(temp == head)
                {
                    cout<<"HEAD"<<endl;
                    head = head->next;
                    node *after = head->next;
                    head->prev = NULL;
                    temp->prev = head;
                    head->next = temp;
                    temp->next = after;
                    after->prev = temp;
                    temp = head->next;
                }
                else if(temp->next == tail)
                {
                    cout<<"TAIL"<<endl;
                    node *back = temp->prev;
                    temp->next = NULL;
                    tail->next = temp;
                    temp->prev = tail;
                    back->next = tail;
                    tail->prev = back;
                    tail = tail->next;
                    tail->next=NULL;
                    temp= tail;

                }
                else
                {
                    cout<<"ANY"<<endl;
                    node *back = temp->prev;
                    node *after = temp->next->next;

                    back->next=temp->next;
                    temp->prev = temp->next;
                    after->prev->next = temp;
                    after->prev->prev = back;
                    after->prev = temp;
                    temp->next = after;
                    temp = after->prev;
                }
            }
            else
            temp = temp->next;
            display();
            display0();
            cout<<"HEAD: "<<head->data<<endl;
            cout<<"Tail: "<<tail->data<<endl;
            cout<<endl;
            c++;
        }   
    }
}*/

/*
X1 = currPtr->previoius;
  X2 = currPtr->next->next;
  currNext = currPtr->next;
  currNext->previous = currPtr->previous;
  currPtr->previous = currPtr->next;
  currPtr->next = currNext->next;
  currNext->next = currPtr;
  X1->next = currPtr->previous;
  X2->previous = currPtr;
// graphical explanation is below...
// original state
//     X1-> <-curr-> <-currNext-> <-X2
// currNext->previous = currPtr->previous;
//     X1-> <-curr----,           <-X2
//       \             \         /
//        '-------------currNext->
// currPtr->previous = currPtr->next;
//     X1-> ,-curr--------,        <-X2
//       \   \..........,  \      /
//        '-------------currNext->
// currPtr->next = currNext->next;
//     X1->  -curr---------------> <-X2
//       \   \..........,         /
//        '-------------currNext->
// currNext->next = currPtr;
//         /''''''''''''\
//     X1-' <-currNext-> <-curr-> .-X2
//                     \........./
// X1->next = currPtr->previous;
//     X1-> <-currNext-> <-curr-> .-X2
//                     \........./
// X2->previous = currPtr;
//     X1-> <-currNext-> <-curr-> <-X2
*/
