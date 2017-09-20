// Group E : program No. 35
//Write C++ program to store first year percentage of students in array. Write function for
//sorting array of floating point numbers in ascending order using
//a) Selection Sort b) Bubble sort and display top five scores.
#include<iostream>
#define MAX 20
using namespace std;

class marks
{
	float arr[MAX];
	int num;

public:
	//this function will sort the array and print the sorted array and the top five marks 
	void bubbleSort()
	{
		for (int i = 0; i < num; i++)
		{
			for (int j = i+1; j < num; j++)
			{
				if (arr[i] > arr[j])
				{
					//swarrp
					float temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}

		cout<<"The sorted array is: "<<endl;
		for (int i = 0; i < num; ++i)
		{
			cout<<arr[i]<<" ";
		}

	}
	//same as above just the method is different
	void selectionSort()
	{
		int i=0,j,min = 0,temp=0;
		
		//considering the index value 
		for(i = 0 ; i < num ; i++)
		{
			min = i;
			for (int j = i+1; j < num; j++)
			{
				/* code */
				if(arr[min] > arr[j])
				{
					min = j;
				}
			}
			if(min!=i)
			{
				temp = arr[min];
				arr[min] = arr[i];
				arr[i] = temp;
			}
		}
		cout<<"The sorted array is: "<<endl;
		for (int i = 0; i < num; ++i)
		{
			cout<<arr[i]<<" ";
		}
	}
	void getData()
	{
		cout<<"Enter the amount of students : ";
		cin>>num;
		for(int i = 0 ; i < num;i++)
			cin>>arr[i];
	}
};


int main()
{
	marks m;
	int ch;
	char status;
	do{
		cout<<"1.Enter the marks for students"<<endl;
		cout<<"2.Sort using bubble sort"<<endl;
		cout<<"3.Sort using selection sort"<<endl;
		cout<<"****************************"<<endl;
		cout<<"Enter your choice : "<<endl;
		cin>>ch;
		switch(ch){
			case 1:
					m.getData();
			break;
			case 2:
					m.bubbleSort();
				break;
			case 3:
				m.selectionSort();
			break;
			default:
					cout<<"Invalid Choice !"<<endl;
		}
		cout<<"Do you want to continue ?[Y/N]"<<endl;
		cin>>status;
	}while(status == 'y' || status == 'Y');
	return 0;
}