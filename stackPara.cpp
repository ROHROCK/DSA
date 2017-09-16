#include<iostream>
#define MAX 20
using namespace std;

class stack
{
	char array[MAX];
	int top;

	public:
		stack()
		{
			top=-1;
		}
		int isFull()
		{
			if(top > MAX-1)
				return 1;
			else
				return 0;
		}
		int isEmpty()
		{
			if(top == -1)
				return 1;
			else
				return 0;
		}
		void push(char data)
		{
			if(isFull())
			{
				cout<<"Stack is full !"<<endl;
			}else
			{
				top++;
				array[top] = data;
				cout<<data<<"is pushed"<<endl;
			}
		}

		int pop()
		{
			if(isEmpty())
			{
				cout<<"Stack is empty !"<<endl;
			}
			else
			{
				int temp = array[top];
				top--;
				return temp;
			}
			return 0;
		}
}s;

void add()
{
	char str[MAX];
	cout<<"Enter the following: "<<endl;
	cout<<"[ , { , ( , ) ,} , ]"<<endl;
	cin>>str;
	int i=0,cnt=0;
	while(str[i]!='\0')
	{
		//opening bracket concept !
		if(str[i] == '[')
			s.push(str[i]);
		else if(str[i] == '{')
			s.push(str[i]);
		else if(str[i] == '(')
			s.push(str[i]);

			int temp=0;
		switch(str[i])
		{
			case ')':
				temp = s.pop();
				if(temp == '{' || temp == '[')
					cout<<"Not Balanced !(";
			break;

			case '}':
				temp = s.pop();
				if(temp == '[' || temp == '(')
					cout<<"Not Balanced !}";
			break;

			case ']':
				temp = s.pop();
				if(temp == '{' || temp == '(')
				cout<<"Not Balanced !]";
			break;
		}
		i++;
	}	
		if(!s.isEmpty())
			cout<<"Not Balanced !";
}


int main()
{	
	add();
	return 0;
}