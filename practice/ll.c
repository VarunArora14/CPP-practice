#include <stdio.h>
#include <stdlib.h>
struct node //linked list declaration
{
    int data;
    struct node *next;
};
struct node *head;
//function declaration for certain operations on circular linked list
void insert_front();
void delete_end();
void display();
void search();
main() //main program
{

    int choice = 0;
    while (choice != 5) //while loop for operations on list
    {
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n1.Insert at front\n2.Delete from end \n3.Search for an element\n4.Show\n5.Exit\n");
        printf("\nEnter your choice\n");
        scanf("\n%d", &choice);
        switch (choice) //switch operation for insertion , deletion , displaying and searching
        {
        case 1:
            insert_front();
            break;
        case 2:
            delete_end();
            break;
        case 3:
            search();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}
void insert_front() //function to insert element at front.
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW"); //message pops if the list is full
    }
    else
    {
        printf("\nEnter the node data");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
        printf("\nnode inserted\n");
    }
}

void delete_end() // function to delete element at end .
{
    struct node *ptr, *preptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW"); //message pops if the list is empty
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        printf("\nnode deleted\n");
    }
}

void search() // function to search a certain  element in a list.
{
    struct node *ptr;
    int item, i = 0, flag = 1;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n"); //message pops if the list is empty
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item);
        if (head->data == item)
        {
            printf("item found at location %d", i + 1);
            flag = 0;
        }
        else
        {
            while (ptr->next != head)
            {
                if (ptr->data == item)
                {
                    printf("item found at location %d ", i + 1);
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
                i++;
                ptr = ptr->next;
            }
        }
        if (flag != 0)
        {
            printf("Item not found\n");
        }
    }
}

void display() // function to display elements in the final list .
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\nnothing to print"); //message pops if the list is empty
    }
    else
    {
        printf("\n printing values ... \n");

        while (ptr->next != head)
        {

            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
}
