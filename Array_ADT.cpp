#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class ArrayADT
{
	int capacity;
	int lastindex;
	int *ptr;
	public:
	ArrayADT()
	{
		capacity=0;
		lastindex=-1;
		ptr=NULL;
	}
		~ArrayADT()
	{
		delete []ptr;
	}
	ArrayADT (ArrayADT &list)
	{
		capacity=list.capacity;
		lastindex=list.lastindex;
		ptr=new int(capacity);
		for(int i=0;i<=lastindex;i++)
		ptr[i]=list.ptr[i];
	}
	void createarray(int capacity);
	int getitem(int index);
	int setitem(int index,int value);
	void edititem(int index,int value);
	int countitem();
	void removeitem(int index);
	int searchitem(int value);
	void shortitem();
	friend ostream& operator<<(ostream&,ArrayADT);
};
ostream& operator<<(ostream &dout,ArrayADT l)
{
	if(l.lastindex==-1)
	cout<"\nList is empty";
	for(int i=0;i<l.countitem();i++)
		cout<<" "<<l.getitem(i);
		return(dout);
}
void ArrayADT::shortitem()
{
	int r,i,t;
	for(r=1;r<countitem();r++)
	{
		for(i=0;i<countitem()-r;i++)
		if(ptr[i]>ptr[i+1])
		{
			t=ptr[i];
			ptr[i]=ptr[i+1];
			ptr[i+1]=t;
		}
	}
}
int ArrayADT::searchitem(int value)
{
	if(lastindex==-1)
	{
		cout<<"\nInvalid index number";
		return (-1);
	}
	int i;
	for(i=0;i<=lastindex;i++)
	{
		if(ptr[i]==value)
		return(i);
	}
	return (-1);
}
void ArrayADT::removeitem(int index)
{
	int i;
	if(index<0 || index>lastindex)
	  cout<<"\nInvalid index option";
	else if(index < lastindex)
	{
		i=index;
		while(i!=lastindex)
		{
			ptr[index]=ptr[i+1];
			i++;
		}
		lastindex--;
	}
	else if(index==lastindex)
	  lastindex--;
}
int ArrayADT::countitem()
{
	return (lastindex+1);
}
void ArrayADT::edititem(int index,int value)
{
	if(index<0||index>lastindex)
	
		 cout<<"\nInvalid index number";
	else
	     ptr[index]=value;  
	
}
int ArrayADT::setitem(int index,int value)
{
	int i;
	if(index==lastindex-1)
	cout<<"\nIndex is overflow";
	else if(index>capacity-1||index<0)
	cout<<"\nInvalid index option";
	else if(index>lastindex+1)
	cout<<"\nInvalid index option";
	else if(index<=lastindex)
	{
		lastindex++;
		i=lastindex;
		while(i!=index)
		{
			ptr[i]=ptr[i-1];
			i--;
		}
		ptr[index]=value;
	}
	else if(index==lastindex+1)
	{
		lastindex++;
		ptr[index]=value;
	}
}
int ArrayADT::getitem(int index)
{
	if(lastindex==-1)
	{
	cout<<"\nList is empty";
	return (-1);
    }
    if(index>lastindex||index<0)
    {
    	cout<<"\nInvalid index number";
    	return(-1);
	}
	return (ptr[index]);
}
void ArrayADT::createarray(int capacity)
{
	this->capacity=capacity;
	lastindex=-1;
	ptr=new int [capacity];
}
int main()
{
	ArrayADT l1;
	int a,b,c,d;
	while(1)
 {
	cout<<"\n1.Create array list";
	cout<<"\n2.Set items in the array";
	cout<<"\n3.Search item in the array";
	cout<<"\n4.Remove any item in the array";
	cout<<"\n5.Count item in the array";
	cout<<"\n6.Edit item in the array";
	cout<<"\n7.Getitem in the array";
	cout<<"\n8.Sort items in the array";
	cout<<"\n9.Exit";
	cout<<"\n10.Show the array list";
    cout<<"\n\nEnter your choice";
	cin>>a;
	switch(a)
	{
		case 1:
			cout<<"\nHow many array value will be create";
			scanf("%d",&b);
			l1.createarray(b);
			break;
	    case 2:
	    	cout<<"\nEnter the index and value";
	    	cin>>b>>c;
	    	d=l1.setitem(b,c);
	    	cout<<"\nYour set item is:"<<d;
	    	break;
		case 3:
			cout<<"\nEnter whose value will you search";
			scanf("%d",&b);
			c=l1.searchitem(b);
			cout<<"\n"<<c;
			break;
		case 4:
			cout<<"\nEnter index to remove value";
			cin>>b;
			l1.removeitem(b);
			break;
		case 5:
		    c=l1.countitem();
		    cout<<"\nThe number of item is:"<<c;
            break;	
		case 6:
			cout<<"\nEnter index and value to be edit";
			cin>>b>>c;
			l1.edititem(b,c);
			break;
		case 7:
			cout<<"Enter your value to get item";
			scanf("%d",&b);
			c=l1.getitem(b);
			cout<<"\nyour get value is:"<<c;
			break;
		case 8:
			l1.shortitem();
			break;
		case 9:
			exit(0);
			break;
		case 10:
			cout<<l1;
			break;
		default:
			cout<<"\n\nInvalid option";
	 } 
	 getch();
  }
	 return 0;
} 
    
