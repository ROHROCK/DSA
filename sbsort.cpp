//Selection and bubble sort and print the top ten marks 
#include<iostream>
#include<stdlib.h>
#define MAX 20
using namespace std;

class sortClass{
	float arr[MAX];
	int size;
public:
	void swap(float *a , float *b)
	{
		float temp = *a;
		*a = *b;
		*b = temp;
	}

	void getArray()
	{
		cout<<"Enter the size of array: "<<endl;
		cin>>size;
		cout<<"Enter the float numbers: "<<endl;
		for (int i = 0; i < size; ++i)
			cin>>arr[i];
	}	
	void SelectionSort()
	{
		getArray();
		cout<<"Selection sort started !"<<endl;
		int maxi = 0;
		for (int i = 0; i < size; ++i)
		{
			maxi = i;
			for (int j = i + 1; j < size; ++j)
			{
				if (arr[maxi] < arr[j])
					maxi = j;
			}
			if (maxi != i)
			{
				swap(&arr[maxi],&arr[i]);
			}
		}
		display();
	}

	void bubbleSort()
	{
		getArray();
		cout<<"Bubble sort started !"<<endl;
		for (int i = 0; i < size -1; ++i)
		{
			for (int j = 0; j < size - i -1; ++j)
			{
				if (arr[j] < arr[j+1])
				{
					swap(&arr[j],&arr[j+1]);
				}
			}
		}

		cout<<"The sorted array is: "<<endl;
		display();
	}

	void display()
	{
		for (int i = 0; i < size; ++i)
			cout<<arr[i]<<" ";
	}
};

int main()
{
	int ch;
	char status;
	sortClass s;
	do{
		cout<<"****MENU*****"<<endl;
		cout<<"1.To sort using Selection Sort: "<<endl;
		cout<<"2.To sort using Bubble sort: "<<endl;
		cout<<"3.Exit"<<endl;
		cout<<"************"<<endl;
		cout<<"Enter your choice: "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				s.SelectionSort();
			break;
				
			case 2:
				s.bubbleSort();
			break;

			case 3:
				exit(EXIT_SUCCESS);
			break;

			default:
				cout<<"Wrong choice !"<<endl;
		}
		cout<<"Do you want to continue ?[Y/N]"<<endl;
		cin>>status;
	}while(status == 'y' || status == 'y');
	return 0;
}