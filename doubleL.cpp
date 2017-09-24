#include<iostream>
using namespace std;

typedef struct node
{
	int d;
	struct node *prev;
	struct node *next;
}NODE;

class dll
{
	NODE *st,*lt;

public:
	dll() {st = lt = NULL;}
	NODE* createNode(int d);
	void insert(int d);
	void delAll();
	void del(int d);
	void display();
	void merge(dll & , dll&);
};

NODE* dll::createNode(int d)
{

	NODE *temp = new(NODE);
	temp->d = d;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

void dll::insert(int d)
{
	NODE *t = createNode(d);
	if(st==NULL)
	{
		st =t ;
		lt =t;
		return;
	}
	else
	{
		lt->next=t;
		t->prev = lt;
		lt=t;
	}
}

void dll::del(int d)
{
	NODE *t,*temp;
	if(st->d == d)
	{
		t =st;
		if(st==lt)
			lt=st=NULL; //if only one node left
		else
			st=st->next; //if only there is more than one node increment
		
		delete(t);
		return;
	}
	else if(lt->d==d)
	{
		t=lt;
		if(st==lt)
			lt=st=NULL;
		else
		{
			lt=lt->prev;
			lt->next=NULL;
		}

		delete(t);
		return;
	}
	//storing the starting node to temp
	temp = st;
	//if there is more than one node in link list
	while(temp->next != NULL)
	{
		if(temp->d == d)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete(temp);
			break;
		}
		temp = temp->next;
	}
	return;
}

void dll::display()
{
	NODE *temp=st;
	if (temp == NULL)
	{
		/* code */
		cout<<"list empty !"<<endl;
		return;
	}
	cout<<"Link list: "<<endl;
	while(temp!=NULL)
	{
		cout<<temp->d<<"->";
		temp=temp->next;
	}
}

void dll::merge(dll &x , dll &y)
{
	while(x.st!=NULL && y.st!= NULL)
	{
		if (x.st->d <= y.st->d)
		{
			/* code */
			insert(x.st->d);
			x.del(x.st->d);
		}
		else
		{
			insert(y.st->d);
			y.del(y.st->d);
		}
	}

	while(x.st!=NULL)
	{
		insert(x.st->d);
		x.del(x.st->d);
	}

	while(y.st!=NULL)
	{
		insert(y.st->d);
		y.del(y.st->d);
	}
}

int main()
{
	dll x,y,z;
	int opt,d;
	while(true)
	{
		cout<<"***************************"<<endl;
		cout<<"\n1.insert at X\n2.insert at y\n3.display x\n4.display y\n5.merge into z\n6.display z\n7.exit\nchoose opt :";
		cout<<"*************"<<endl;
		cin>>opt;
		
		if(opt==7)
			break;
		switch(opt)
		{
			case 1:
				cout<<"\nEnter data :";
				cin>>d;
				x.insert(d);
				break;
		
			case 2:
				cout<<"\nEnter data :";
				cin>>d;
				y.insert(d);
				break;
			case 3:
				cout<<"\nList x :";
				x.display();
				break;
			case 4:
				cout<<"\nList y :";
				y.display();
				break;
			case 5:
				z.merge(x,y);
				break;
			case 6:
				cout<<"\nList z :";
				z.display();
				break;
		}
	}
	return 0;
}