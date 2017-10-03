#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node *next;
};

class link
{
	node *prev;
	public:
	node *head,*pos,*neg,*mHeader;
		link()
		{
			head = NULL;
			prev = NULL;
			pos = NULL;	
			neg = NULL;
		}
	node* insert(int data,node* headV)
	{
		node *temp = new node;
		temp->next = NULL;
		if(headV == NULL)
		{
			temp->data = data;
			headV = temp;
			return headV;
		}
		else
		{
			cout<<"Entered the different condition"<<endl;
			node *ptr = new node ;
			ptr = headV;
			while(ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			temp->data = data;
			ptr->next = temp;
			return headV;
		}
		return headV;
	}

	void disp(node *headV)
	{
		if(headV == NULL)
		{
			cout<<"Link list is empty !"<<endl;
			
		}else{
			node *ptr ;
			ptr = headV;
			while(ptr != NULL)
			{
				cout<<ptr->data<<" -> ";
				ptr = ptr->next;
			}
		}
	}
	void delNegative(node *headV)
	{
		node *temp ,*ptr;
		cout<<"Deleting the negative node in the list";
		prev = headV;
		ptr = headV->next;
		while(ptr != NULL)
		{
			if(ptr->data < 0)
			{
				//this will code the deletion operation
				//first point the prev node to the next node
				prev->next = ptr->next ;
				cout<<"Deleted: "<<ptr->data;
				delete(ptr);
				ptr = prev;
			}
			ptr=ptr->next;
		}
		cout<<"Done !"<<endl;
	}
	//this function will first join the link list and then sort the complete link list 
	//so it will take two arguments the negative header and postive header  
	node* merge(node *posHeader , node * negHeader)
	{
		//for now just sort the link list 
		node *ptr ;
		node *nextPtr;
		ptr = negHeader;
		while(ptr != null)
		{
			if (ptr->data > ptr->data)
			{
				int Sdata; // to swap the data

			}
			ptr = ptr->next;
		}
		//now all the negative elements are copied in the megered header
		return mHeader;
	}
};



int main()
{
	link l;
	char status;
	int data=0,ch=0,option = 0;
	do{
		cout<<"***MENU****"<<endl;
		cout<<"1.To Add Elements"<<endl;
		cout<<"2.To Delete Negative Elements"<<endl;
		cout<<"3.To Display the link list"<<endl;
		cout<<"4.To Merge positive and negative link list order"<<endl;
		cout<<"4.To Exit"<<endl;
		cout<<"***********"<<endl;
		cout<<"Enter your choice: "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 5:
				exit(EXIT_SUCCESS);
			break;

			case 4:
					l.mHeader = l.merge(l.pos,l.neg);
					l.disp(l.mHeader); //it needs to update its value
			break;
			case 1:
				cout<<"1.To Enter to the main link list"<<endl;
				cout<<"2.To Enter to the positve link list"<<endl;
				cout<<"3.To Enter to the negative link list"<<endl;
				cout<<"************************************"<<endl;
				cin>>option;
				switch(option)
				{
					case 1:
						cout<<"Enter the element you want to add: "<<endl;
						cin>>data;
						l.head = l.insert(data,l.head);
					break;

					case 2:
						cout<<"Enter the element you want to add: "<<endl;
						cin>>data;
						if(data > 0)
							l.pos = l.insert(data,l.pos);
						else
							 cout<<"Please enter a positive number !"<<endl;

					break;

					case 3:
						cout<<"Enter the element you want to add: "<<endl;
						cin>>data;
						if(data < 0)
							l.neg = l.insert(data,l.neg);
						else
							cout<<"Please enter a negative number !"<<endl;


				}
			break;

			case 2:
				l.delNegative(l.head);
			break;
			case 3:
				cout<<"1.To Display the main link list"<<endl;
				cout<<"2.To Display the positive link list"<<endl;
				cout<<"3.To Display the negative linkl list"<<endl;
				cin>>option;
				switch(option)
				{
					case 1:
						l.disp(l.head);
					break;
					case 2:
						l.disp(l.pos);
					break;
					case 3:
						l.disp(l.neg);
					break;
				}
			break;

			default:
				cout<<"Wrong choice !";
		}
		cout<<"Do you want to continue ?[Y/N]"<<endl;
		cin>>status;
	}while(status == 'y' || status == 'Y');
	return 0;
}