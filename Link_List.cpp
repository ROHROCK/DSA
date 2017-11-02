#include<iostream>
#include<stdlib.h>
#include<stdio.h>
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
		if (head == NULL)
			return ;

		node *ptr;
		cout<<"Deleting the negative node in the list";
		prev = headV;
	    ptr = headV->next;	
	    if(prev->data<0)
	    {
	    	if(prev->next==NULL)
	    	{
	    		delete(prev);
	    		head=NULL;
	    	}
	    	else{
	    		
	    	}
	    }
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
			prev=ptr;
			ptr=ptr->next;
		}
		cout<<"Done !"<<endl;
	}
	//this function will first join the link list and then sort the complete link list 
	//so it will take two arguments the negative header and postive header  
	void merge()
	{
		node *ptr;
		node *mainptr;
		ptr = neg;
		//set to negative link list
		while(ptr != NULL)
		{
			insert(ptr->data,head);
		}
		//set to postive link list
		ptr = pos;
		while(ptr != NULL)
		{
			insert(ptr->data,head);
		}
	}
	

	/*
	This function is used to take the main list and split it by checking the data ..
	if positive then .. add to posHeader and delete from main header ..
	if neg then .. add to negHeader and delete form main header ...
	In the end the Main list will be empty !
	*/
	void split()
	{
		cout<<"Called the split function"<<endl;
		//first traverse the list
		node *ptr;
		ptr = head;

		while(ptr != NULL)
		{
			if (ptr->data > 0)
			{
				//add the data to postive list
				pos = insert(ptr->data,pos);
				//then delete the node from current list
				deleteNode(ptr);
			}else
			{
				//add the data to negative list
				neg = insert(ptr->data,neg);
				//then delete the node from the current list
				deleteNode(ptr);
			}
			ptr = ptr->next;
		}
	}

	/*
	This function will delete the node from the main list 
	it will accept the node pointer 
	and this funciton will execute the code for begin/middle/end depending on where the ptr is..
	*/
	void deleteNode(node *ptr)
	{
		cout<<"Called the delete node function"<<endl;
		//this should delete the node .. there are three conditions .. 
		//delete from head .. from middle .. from end all these conditons should be checked..

		//this code meant for deletion from the start
		cout<<"Code check: "<<endl;
		if(head != NULL)
			cout<<"Value of head->next->data: "<<head->data<<endl;
		else
			cout<<"The link list is empty !"<<endl<<endl;
		cout<<"Value of ptr->data: "<<ptr->data<<endl;
		cout<<"Code check end: "<<endl;


		if (head->data == ptr->data)
		{
			cout<<"Code check: "<<endl;
			cout<<"Delete From Begin"<<endl;
			head = ptr->next;
			delete(ptr);
		}
		//meaning deletion from the end
		else if(ptr->next == NULL){
			cout<<"Delete from End"<<endl;
			node *prev;
			prev = traverseSecondLast(); 
			prev->next = NULL;
			delete(ptr);
		}
		else
		{
			//this code is for deletion from the middle 
			//the ptr is in the middle
			cout<<"The ptr node is in the middle: "<<endl;
			node *prev;
			prev = traverseSecondLast();
			prev->next = ptr->next;
			delete(ptr);
		}
	}

	/*
	this funciton will traverse till the second last node and 
	return the node to the caller ..
	can be used for deleletion from the end and middle purpose
	*/
	node* traverseSecondLast()
	{
			cout<<"Called the traversal function"<<endl;
			node *prevNode;
			prevNode = head;
			//traverse till the second last
			while(prevNode->next != NULL)
			{
				prevNode = prevNode->next;
			}
		return prevNode;
	}

	/*Program to sort the postive link list*/
	void posSort()
	{
			node *lptr = NULL;
			node *ptr;

			int swapped ;
			do{
				ptr = pos
				swapped = 0;
				while(ptr->next != lptr)
				{
					if (ptr->data > ptr->next->data)
					{
						swap(ptr,ptr->next);
						swapped = 1;
					}
					ptr = ptr->next;
				}
				lptr = ptr; //set the lptr to ptr where ptr is pointing to the last element
				//the last element is at the correct pos
			}while(swapped);
	}

	void negSort()
	{
		cout<<"Entered the negSort"<<endl;
		node *lptr = NULL;
		node *ptr;
		int swapped ;

		do{
			cout<<"Entered do while"<<endl;
			swapped = 0;
			ptr = head;
			while(ptr->next != lptr)
			{
				if (ptr->data > ptr->next->data)
				{
					cout<<"Before swap"<<endl;
					swap(ptr,ptr->next);
					swapped = 1;
					cout<<"After swap"<<endl;
				}
				ptr = ptr->next;
			}
			lptr = ptr; //set the lptr to ptr where ptr is pointing to the last element
			//the last element is at the correct pos
		}while(swapped);
	}

	void swap(node *a,  node *b)
	{
		cout<<"Swapping tech"<<endl;
	    int temp = a->data;
	    a->data = b->data;
	    b->data = temp;
	    cout<<"Swapped !"<<endl;
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
		cout<<"4.To Split postive and negative data into diffrent list"<<endl;
		cout<<"5.To Merge positive and negative link list order"<<endl;
		cout<<"6.To sort the positive and negative list in acending order"<<endl;
		cout<<"7.To Exit"<<endl;
		cout<<"***********"<<endl;
		cout<<"Enter your choice: "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 7:
				exit(EXIT_SUCCESS);
			break;

			case 6:
				l.posSort();
				l.negSort();
			break;

			case 4:
				//this code should a function to split the main list to two different list
				//function needed is delete and addTopost and addToNeg
				l.split();
			break;

			case 5:
					//Code to be added the merge code ..
					//you can create a funtion which takes the head and point to negative list
					//and just traverse it to the end ... let the last node point of the neg node point to the
					//head of next list 
			break;

			case 1:
		  		cout<<"Enter the element you want to add: "<<endl;
				cin>>data;
			    l.head = l.insert(data,l.head);
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
