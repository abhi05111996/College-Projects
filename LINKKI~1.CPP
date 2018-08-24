#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
//using namespace std;
class LinkedListADT
{
	public:
		typedef struct node
		{
			int item;
			node *next;
		}node;
		node* start;
		LinkedListADT()
		{
			start=NULL;
		}
node *Search(int data)
{
	node *t;
	if(start==NULL)
		return NULL;
	t=start;
	while(t->next!=NULL)
	{
		if(t->item==data)
		return (t);
		t=t->next;
	}
	return (NULL);
}

	void InsertAtStart(int data);
	void InsertAtLast(int data);
	void InsertAtAfter(int curentdata,int data);
   // int search(int data);
	int DeleteFirst();
	int DeleteLast();
	int DeleteCurrentItem(int currentdata);
	int EditItem(int currentitem,int newdata);
	int CountItem();
	int GetFirstItem();
	int GetLastItem();
	void ViewList();
	int SearchItem(int data);
	void SortList();
};
void LinkedListADT::SortList()
{
	node *p,*t;
	int r,i,x,n;
	n=CountItem();
	for(r=1;r<=n-1;r++)
	{
		t=start;
		for(i=0;i<=n-1-r;i++)
		{
			if(t->item > t->next->item)
			{
				x=t->item;
				t->item=t->next->item;
				t->next->item=x;
			}
			t=t->next;
		}
	}
}
int LinkedListADT::SearchItem(int data)
{
	node *t;
	t=start;
	while(t!=NULL)
	{
		if(t->item==data)
		return 1;
		t=t->next;
	}
	return 0;
}
void LinkedListADT::ViewList()
{
	if(start==NULL)
	  cout<<"\nList is empty";
	else
 {
	node *t;
	t=start;
	while(t!=NULL)
	{   cout<<"\n "<<t->item;
		t=t->next;
	}
 }
}
int LinkedListADT::GetLastItem()
{
	if(start==NULL)
	{
		cout<<"\nList is empty";
		return -1;
	}
	node *t;
	t=start;
	while(t!=NULL)
	{
		t=t->next;
	}
	return t->item;
}
int LinkedListADT::GetFirstItem()
{
	if(start==NULL)
	{
		cout<<"\nList is empty";
		return -1;
	}
	return start->item;
 }
int LinkedListADT::CountItem()
{
	int count=0;
	node *t;
	t=start;
	while(t!=NULL)
	{
		count++;
		t=t->next;
	}
	return count;
}
int LinkedListADT::EditItem(int currentitem,int newdata)
{
	node *t=Search(currentitem);
	if(t==NULL)
	cout<<"\nItem not found";
	else
	t->item=newdata;
	return 0;
}
int LinkedListADT::DeleteFirst()
{
	if(start==NULL)
	{
		cout<<"\nUnderflow";
		return 0;
	}
	node *r;
	r=start;
	start=start->next;
	delete r;
	return 1;
}
int LinkedListADT::DeleteLast()
{
	if(start==NULL)
	{
		cout<<"\nUnderflow";
	}
	if(start->next!=NULL)
	{
		delete(start);
		start=NULL;
		return 1;
	}
	node *t1,*t2;
	t1=t2=start;
	do {
		t2=t1;
		t1=t1->next;
	}
	while(t1->next!=NULL);
	t2->next=NULL;
	delete t1;
	return 1;
}
int LinkedListADT::DeleteCurrentItem(int currentdata)
{
	node *t=Search(currentdata);
	if(t==NULL)
	{
		cout<<"\nItem not found";
		return 0;
	}
	while(t->next!=NULL)
	{
		t->item=t->next->item;
		t=t->next;
	}
	DeleteLast();
	return(0);

}

void LinkedListADT::InsertAtStart(int data)
{
	node *n=new node;
	n->item=data;
	n->next=start;
	start=n;
}
void LinkedListADT::InsertAtLast(int data)
{
	node *n,*t;
	n=new node;
	n->item=data;
	n->next=NULL;
	if(start==NULL)
	start=n;
	else
	{
		t=start;
		while(t->next!=NULL)
		 t=t->next;
		t->next=n;
	}

}
void LinkedListADT::InsertAtAfter(int currentdata,int data)
{
  node *t=Search(currentdata);
  if(t==NULL)
  cout<<"\nNo such value exits";
  else
  {
	node *n=new node;
	n->item=data;
	n->next=t->next;
	t->next=n;
  }
}
void main()
{
	LinkedListADT l1;
	int list,choice,data,data1,return1;
   while(1)
       {
	clrscr();
	cout<<"***********************  Welcome to Link list program  *************************";
	cout<<"\n\n1.Insert at first position: ";
	cout<<"\n2.Insert at last position:";
	cout<<"\n3.Insert at specific position:";
	cout<<"\n4.Delete at first position:";
	cout<<"\n5.Delete at last position:";
	cout<<"\n6.Delete at current position:";
	cout<<"\n7.Edit Item:";
	cout<<"\n8.Count Item:";
	cout<<"\n9.Get first item:";
	cout<<"\n10.Get last item:";
	cout<<"\n11.View list:";
	cout<<"\n12.Search item:";
	cout<<"\n13.Sort list:";
	cout<<"\n14.Exit";
	cout<<"\n\n\n Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
	    case 1:
		cout<<"\nEnter a Integer data";
		cin>>data;
		l1.InsertAtStart(data);
		cout<<"\nYour data is insetted";
		break;
	    case 2:
		cout<<"\nEnter a Integer data";
		cin>>data;
		l1.InsertAtLast(data);
		cout<<"\nYour data is insetted";
		break;
	    case 3:
		cout<<"\nEnter a position and new data:";
		cin>>data>>data1;
		l1.InsertAtAfter(data,data1);
		break;
	    case 4:
		l1.DeleteFirst();
		cout<<"\nYour first data is successfuly deleted";
		break;
	    case 5:
		 l1.DeleteLast();
		 cout<<"\nYour lasr data is successfuly deleted";
		 break;
	    case 6:
		 cout<<"\n Enter the data will be delete in the list";
		 cin>>data;
		 l1.DeleteCurrentItem(data);
		 cout<<"\nYour data is successfuly deleted";
		 break;
	    case 7:
		 cout<<"\nEnter the old data:";
		 cin>>data;
		 cout<<"\nEnter the new data:";
		 cin>>data1;
		 l1.EditItem(data,data1);
		 cout<<"\nYour list are successfuly Edited";
		 break;
	    case 8:
		 return1=l1.CountItem();
		 cout<<"\n"<<return1<<"item available";
		 break;
	    case 9:
		return1=l1.GetFirstItem();
		cout<<"\n"<<return1<<" is first item";
		 break;
	    case 10:
		 return1=l1.GetLastItem();
		 cout<<"\n"<<return1<<" is last item";
		 break;
	    case 11:
		 l1.ViewList();
		 cout<<"\nYour list are: \n";
		 break;
	    case 12:
		 cout<<"\nWhat you want to search enter the data";
		 cin>>data;
		 return1=l1.SearchItem(data);
		 if(return1 != NULL)
		     cout<<"\nYour data is exist";
		 else
		     cout<<"\nYour data is not exist";
		 break;
	    case 13:
		 l1.SortList();
		 cout<<"\nYour list are successfuly sorted";
		 break;
	    case 14:
		 clrscr();
		 cout<<"\n\n\n\n Thank you.";
		 getch();
		 exit(0);
	    default:
		cout<<"\nInvalid option chose valid option";
		break;
	}
	getch();

      }
}

/*l1.InsertAtStart(34);
	l1.InsertAtLast(56);
	l1.InsertAtStart(57);
	list=l1.GetFirstItem();
	l1.ViewList();
	l1.CountItem();
	cout<<endl<<list;
  */