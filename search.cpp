#include <iostream>
#include<stdlib.h>
#define MAX 30
using namespace std;

int min(int a,int b){return (a<=b)?a:b;}

class student
{
		public :
		int stud[MAX],size,key;

		void getData()
		{
			cout<<"Enter the number of students present: "<<endl;
			cin>>size;
			cout<<"Enter their roll numbers.."<<endl;
			for (int i = 0; i < size; ++i)
				cin>>stud[i];
		}
		void getKey()
		{
			cout<<"Enter the roll number you want to search: "<<endl;
			cin>>key;
		}
		void sentinentalSearch()
		{
			getKey();
			//main searching code 
			int last = stud[size-1];
			stud[size-1] = key;
			int i= 0;
			while(stud[i] != key)
			{
				i++;
			}
			stud[size-1] = last;
			if ((i<size-1)||(last == key))
				cout<<"Present !";
			else
				cout<<"Not Present !";
		}

		void linearSearch()
		{
			getKey();
			int f = 0;
			for (int i = 0; i < size; ++i)
			{
				if (stud[i] == key)
				{
					/* code */
					cout<<"Found !"<<stud[i];
					break;
					f =1;
				}
			}
			if (f = 0)
				cout<<"Not found !"<<endl;
		}


		int binarySearch(int arr[], int l, int r, int x)
		{
		   if (r >= l)
		   {
		        int mid = l + (r - l)/2;
		 
		        // If the element is present at the middle itself
		        if (stud[mid] == x)  return mid;
		 
		        // If element is smaller than mid, then it can only be present
		        // in left subarray
		        if (stud[mid] > x) return binarySearch(stud, l, mid-1, x);
		 
		        // Else the element can only be present in right subarray
		        return binarySearch(arr, mid+1, r, x);
		   }
		 
		   // We reach here when element is not present in array
		   return -1;
		}

	void sort()
	{
		cout<<"Sorting the array in ascending order..."<<endl;
		int min ;
		min = stud[0];
		for (int i = 0; i < size; ++i)
		{
			min = i;
			for (int j = i+1; j < size; j++)
			{
				if (stud[min] > stud[j])
				{
					min = j;
				}
			}
			if (min != i)
			{
				int temp = stud[i];
				stud[i] = stud[min];
				stud[min] = temp;
			}
		}
	}
	int fibonacciSearch();
};

//code for fibonacci
int student::fibonacciSearch()
{
	//sort the array
	sort();
	//get the key from the user
	getKey();
	//comparing last element 
	if(stud[size-1]==key)
		return size-1;

	//assigning fibonacci values to var : fibM2 ,fibM1 ,fibM 
	int fibM,fibM1,fibM2;

	fibM1=1,fibM2=1;
	fibM=fibM1+fibM2;
	while(fibM<size)
	{
		fibM2=fibM1;
		fibM1=fibM;
		fibM=fibM1+fibM2;
	}

	//initiating  offset=-1
	int i=0;
	int offset=-1;

	//search element in arry till greater fibM greter than 1
	while(fibM>1)
	{
		i=min(offset+fibM2,size-1);

		if(stud[i]<key)
		{
			fibM=fibM1;
			fibM1=fibM2;
			fibM2=fibM-fibM1;
			offset=i;
		}
		else if(stud[i]>key)
		{
			fibM=fibM2;
			fibM1=fibM1-fibM;
			fibM2=fibM-fibM1;
		}

		//element not foundn :)
		else 
			return i;
	}

	//element not found :|
	return -1;
}
int main()
{
	student s;
	int ch,key,res;
	char status;
	do{
		cout<<"1.To enter the Roll number"<<endl;
		cout<<"2.To search using Sentinental search"<<endl;
		cout<<"3.To search using Linear search"<<endl;
		cout<<"4.To search using Binary search"<<endl;
		cout<<"5.To search using Fibonacci search"<<endl;
		cout<<"6.To exit"<<endl;
		cout<<"***************************\nEnter your choice: "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1: s.getData(); break;
			case 2: s.sentinentalSearch(); break;
			case 3: s.linearSearch(); break;
			case 4: 
				s.sort();
				s.getKey();
				res = s.binarySearch(s.stud,0,s.size-1,s.key); 
				if (res == -1)
				{
					cout<<"Not Found !"<<endl;
				}else
					cout<<"found !"<<res<<endl;
			break;
			case 5: 
				res = s.fibonacciSearch(); 
				if(res == -1)
					cout<<"Element not found !"<<endl;
				else
					cout<<"Element found at: "<<res<<endl;					
			break;
			case 6: exit(EXIT_SUCCESS); break;
			default: 
					cout<<"Wrong choice !"<<endl;
		}
		cout<<"Do you want to continue ? [Y/N]"<<endl;
		cin>>status;
	}while(status == 'Y' || status == 'y');
	
	return 0;
}
