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
	public:
		int num;
	void getData()
	{
		cout<<"Enter the amount of students : ";
		cin>>num;
		for(int i = 0 ; i < num;i++)
			cin>>arr[i];
	}

	//this function will sort the array and print the sorted array and the top five marks 
	// A utility function to swap two elements
	void swap(float * a, float * b)
	{
		int t = *a;
		*a = *b;
		*b = t;
	}

	/* This function takes last element as pivot, places
	the pivot element at its correct position in sorted
		array, and places all smaller (smaller than pivot)
	to left of pivot and all greater elements to right
	of pivot */
	int partition ( int low, int high) // 0 , -1
	{
		float pivot = arr[high]; // pivot //gc
		int i = (low - 1); // Index of smaller element // -1

		for (int j = low; j <= high- 1; j++)
		{
			// If current element is smaller than or
			// equal to pivot
			if (arr[j] <= pivot)
			{
				i++; // increment index of smaller element
				swap(&arr[i], &arr[j]);
			}
		}
		this->swap(&arr[i + 1], &arr[high]);
		return (i + 1);
	}

	/* The main function that implements QuickSort
	arr[] --> Array to be sorted,
	low --> Starting index,
	high --> Ending index */
	void quickSort( int low, int high)
	{
		if (low < high)
		{
			/* pi is partitioning index, arr[p] is now
			at right place */
			int pi = this->partition( low, high);//2
			// Separately sort elements before
			// partition and after partition
			quickSort(low, pi - 1); //0
			quickSort(pi + 1, high);
		}
	}

	/* Function to TOP 5 marks */
	void display(int num)
	{
		for (int i = 0; i < num; ++i)
		{
			/* code */
			cout<<arr[i]<<" ";
		}
		cout<<"The top five Score is: "<<endl;
		int i = num-1;
		int cnt = 5;
		while(cnt!=0)
		{
			cout<<arr[i]<<" ";
			i--;
			cnt--;
		}
	}

};


int main()
{
	marks m;
	int ch;
	char status;
	do{
		cout<<"1.Enter the marks for students"<<endl;
		cout<<"2.Sort using quick sort"<<endl;
		cout<<"****************************"<<endl;
		cout<<"Enter your choice : "<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				m.getData();
			break;
			case 2:
				m.quickSort(0,m.num-1);
				break;
			case 3:
				m.display(m.num);
			break;
			default:
					cout<<"Invalid Choice !"<<endl;
		}
		cout<<"Do you want to continue ?[Y/N]"<<endl;
		cin>>status;
	}while(status == 'y' || status == 'Y');
	return 0;
}