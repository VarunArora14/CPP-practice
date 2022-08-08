#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int data;   
    struct node *next;  
};  
struct node *front;  
struct node *rear;   
void insert (); //function for inserting the element in a linked queue.
void dequeue (); //function for deleting the element in a linked queue.
void display();  //function for displaying all  the elements after performing operation  in a linked queue.
 main ()   // main function
{   
    int choice;   
    while(choice != 4)   //while loop for carrying out insert and delete operations multiple times.
    {     
        printf("\n*************************Main Menu*****************************\n");  
        printf("\n=================================================================\n");  
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice ?");  
        scanf("%d",& choice);  
        switch(choice)  //switch operation for user to interact with main menu
        {  
            case 1:  
            insert();  
            break;  
            case 2:  
            dequeue();  
            break;  
            case 3:  
            display();  
            break;  
            case 4:  
            exit(0);  
            break;  
            default:   
            printf("\nEnter valid choice??\n");  
        }  
    }  
}  
void insert()  // function definition to insert element in a linked queue
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  //allocate the memory for the new node ptr
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  //if the queue is full and more elements are being added to it 
        return;  
    }  
    else  
    {   
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)   // if the condition front = NULL becomes true
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   // if the condition front = NULL becomes false
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void  dequeue()   // function definition to delete element from  a linked queue
{  
    struct node *ptr;  
    if(front == NULL)  
    {   // if the condition front == NULL becomes true
        printf("\nUNDERFLOW\n");  //if the queue is empty and delete operation is carried out
        return;  
    }  
    else   // if the condition front == NULL becomes false
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  
void display ()  // function definition to display all the  elements in a linked queue
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values .....\n");  
        while(ptr != NULL)   
        {  
            printf("\n%d\n",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}  
