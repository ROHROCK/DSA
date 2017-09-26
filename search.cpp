#include <iostream>
#define MAX 30
using namespace std;

class student
{
		public :
		int stud[MAX],num,key;

		void getData()
		{
			cout<<"Enter the number of students present: "<<endl;
			cin>>num;
			cout<<"Enter their roll numbers.."<<endl;
			for (int i = 0; i < num; ++i)
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
			int last = stud[num-1];
			stud[num-1] = key;
			int i= 0;
			while(stud[i] != key)
			{
				i++;
			}
			stud[num-1] = last;
			if ((i<num-1)||(last == key))
				cout<<"Present !";
			else
				cout<<"Not Present !";
		}

		void linearSearch()
		{
			getKey();
			int f = 0;
			for (int i = 0; i < num; ++i)
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
		    earsort();
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
		cout<<"Sorting the array in ascending order: "<<endl;
		int min ;
		min = stud[0];
		for (int i = 0; i < num; ++i)
		{
			min = i;
			for (int j = i+1; j < num; j++)
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
	void fibonacciSearch();
};

void student::fibonacciSearch()
{
	cout<<"Entered fib search"<<endl;
}
int main()
{
	student s;
	int ch,key,res;
	char status;
	do{
		cout<<"1.To enter the roll number"<<endl;
		cout<<"2.To search using sentinental search"<<endl;
		cout<<"3.To search using linear search"<<endl;
		cout<<"4.To search using binary search"<<endl;
		cout<<"5.To search using fibonacci search"<<endl;
		cout<<"6.To sort the array"<<endl;
		cout<<"7.To exit"<<endl;
		cout<<"***************************\nEnter your choice: "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1: s.getData(); break;
			case 2: s.sentinentalSearch(); break;
			case 3: s.linearSearch(); break;
			case 4: 
				s.getKey();
				res = s.binarySearch(s.stud,0,s.num-1,s.key); 
				if (res == -1)
				{
					cout<<"Not Found !"<<endl;
				}else
					cout<<"found !"<<res<<endl;
			break;
			case 5: s.fibonacciSearch(); break;
			case 6: s.sort(); break;
			case 7: exit(EXIT_SUCCESS); break;
			default: 
					cout<<"Wrong choice !"<<endl;
		}
		cout<<"Do you want to continue ? [Y/N]"<<endl;
		cin>>status;
	}while(status == 'Y' || status == 'y');
	
	return 0;
}