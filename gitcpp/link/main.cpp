#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
using namespace std;

class node
{

public:
    int info;
void insert1(node*);
void insert2(node*);
void delete1();
void show(node*);

node *next;
}
*start,*last,*ptr,*newptr;

node* create(int i)
{
    ptr=new node;
    ptr->info=i;
 // ptr->next=NULL;
    return ptr;

}



int main()
{
    node l;
    char ch='y';

 start=last=ptr=newptr=NULL;
 do
 {
 system("cls");

 cout<<"Here are the following choices - "<<endl;
 cout<<"1. Insert top"<<endl<<"2. Insert end"<<endl<<"3. Delete top"<<endl<<"4.Show list"<<endl;
 cout<<endl<<"Enter choice";
 int x;
 cin>>x;
 int i;
 do
 {


 switch(x)
 {

     case 1:
	 cout<<endl<<"Enter the element";
	     cin>>i;

	     newptr=create(i);
	     if(newptr==NULL)
     {
	 cout<<"memory not allocated";
     exit(0);
     }
	     l.insert1(newptr);
	     l.show(start);
	     break;

     case 2:
      cout<<"Enter the info";
      cin>>i;
      newptr=create(i);
       if(newptr==NULL)
     {

	 cout<<"Memory not allocated";
      exit(0);
     }
      l.insert2(newptr);
      l.show(start);
      break;
     case 3:
	if(start==NULL)
	{

	    cout<<"No data in the list";
	    exit(0);
	}
	else{
	    l.delete1();
	    l.show(start);
	}
	break;
	case 4: if(start==NULL)
	{
	cout<<"Empty ";
	}
	else{
	    l.show(start);
	}

	default: cout<<"No such option available . kindly do it again";
 }
 cout<<endl<<" Continue current operation? ";
 cin>>ch;
 }while(ch=='y'||ch=='Y');

 cout<<endl<<"Continue operations?";
 cin>>ch;
 }while(ch=='y');
getch();
}

void node::insert1(node *n)
{
    node* temp;
    if(start==NULL)
    {
	start=last=n;
    }
    else{
	temp=start;
	start=n;
	start->next=temp;
    }

}

void node::insert2(node* n)
{

    if(last==NULL)
    {

	start=last=n;
    }
    else{
	last->next=n;
	last=n;
    }
}

void node::delete1()
{
    node* temp;
    temp=start;
    start=start->next;
    delete temp;
}

void node::show(node* a)
{
    while(a->next!=NULL)
    {
	cout<<a->info<<"->";
	a=a->next;
    }
    cout<<a->info;
}
