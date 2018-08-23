#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
//using namespace std;

class TwoWayStack
{
	private:
	int capacity;
	int top_left;
	int top_right;
	int *ptr;
	public:
		TwoWayStack(int cap)
		{
			capacity=cap;
			top_left=-1;
			top_right=capacity;
			ptr=new int[capacity];
		}
		~TwoWayStack()
		{
			delete []ptr;
		}
			void push_Left(int data);
	void push_Right(int data);
	int pop_Left();
	int pop_Right();
	int peep_Left();
	int peep_Right();
	int empty_Left();
	int empty_Right();
	int isFull();
		
};
		

void TwoWayStack::push_Left(int data)
{
	if(isFull())
	{
		  cout<<"\nStack is Full";
    }
	else
	{
	 top_left++;
	 ptr[top_left]=data;
    }
}

void TwoWayStack::push_Right(int data)
{
	if(isFull())
	 {
	 	 cout<<"\nStack is Full";
	 }
	else
	{
	 top_right--;
	 ptr[top_right]=data;
	 }
}

int TwoWayStack::pop_Left()
{   
    int val;
	if(empty_Left())
	{
		cout<<"\n List is empty";
			return -1;
	}
	else
	{
		top_right--;
		val=top_left;
		return val;
	}
		
	
}

int TwoWayStack::pop_Right()
{   
    int val;
	if(empty_Right())
	{
		cout<<"\n List is empty";
			return -1;
	}
	else
	{
		val=ptr[top_right];
		top_right++;
		return val;
	}
	
}
int TwoWayStack::peep_Left() 
{
	if(empty_Left())
	{
     	cout<<"\n List is empty";
		return (-1);
	}
    else
    return (ptr[top_left]);

}
int TwoWayStack::peep_Right()
{
	if(empty_Right())
	{
		cout<<"\n List is empty";
			return -1;
	}
    else
    return (ptr[top_right]);
}
int TwoWayStack::empty_Left()
{
	if(top_left==-1)
		return (1);
	else
	    return (0);
}
int TwoWayStack::empty_Right()
{
	if(top_right==capacity)
		return (1);		
	else
	    return (0);
}
int TwoWayStack::isFull()
{
	if(top_left+1==top_right)
	  return (1);
	else
	  return (0);	
}
int main()
{
	
	int capacity,choice,data;
	cout<<"\nEnter size for stack";
	cin>>capacity;
    TwoWayStack t1(capacity);
    while(1)
    {
    	cout<<"\n1.Push left";
    	cout<<"\n2.Push right";
		cout<<"\n3.Pop left";
		cout<<"\n4.Pop right";
		cout<<"\n5.Peep left";
		cout<<"\n6.Peep right";
		cout<<"\n7.Empty left";
		cout<<"\n8.Empty right";
		cout<<"\n9.Stack full or not";
		cout<<"\n10.Exit";
        cout<<"\n\nEnter your choice";
        cin>>choice;
        switch(choice)
        {
        	case 1:
        		cout<<"\nEnter a new data";
        		cin>>data;
        		t1.push_Left(data);
        		break;
        	case 2:
        		cout<<"\nEnter a new data";
        		cin>>data;
        		t1.push_Right(data);
        		break;
        	case 3:
        		data=t1.pop_Left();
        		cout<<"\nPoped left value is"<<data;
        		break;
        	case 4:
        		data=t1.pop_Right();
        		cout<<"\nPoped right value is"<<data;
        		break;
        	case 5:
        		data=t1.peep_Left();
        		cout<<"\nPeeped left value is"<<data;
        		break;
        	case 6:
        		data=t1.peep_Right();
        		cout<<"\nPeeped right value is"<<data;
        		break;
        	case 7:
        		data=t1.empty_Left();
        		if(data==1)
        		cout<<"\nStack is empty ";
        		else
        		cout<<"\nStack is not empty";
        		break;
        	case 8:
        		data=t1.empty_Right();
        		if(data==1)
        		cout<<"\nStack is empty ";
        		else
        		cout<<"\nStack is not empty";
        		break;
        	case 9:
        		data=t1.isFull();
        		if(data==1)
        		cout<<"\nStack is Full ";
        		else
        		cout<<"\nStack is not Full";
        		break;
        	case 10:
			exit(0);
        	default:
        		cout<<"\n\nInvalid option";
		}
	
	}
		return 0;
}
