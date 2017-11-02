//WAP for string operations - concatenate , copy , check substring , equal , reverse , and length 
#include<iostream>
#define MIN 20
#define MAX 40 
using namespace std;

class stringClass{
	char arr1[MIN] , arr2[MIN],res[MAX];

	public:
		void copy()
		{
			cout<<"You have entered the copy funtion"<<endl;
			int i = 0 ;
			for(int i= 0 ; i < MIN ; i++)
				arr2[i] = arr1[i];
		
			cout<<"The Copied String is: "<<arr2<<endl;
		}
		void concatenate()
		{
			int cnt = 0 , i = 0;
			while(arr1[i] != '\0')
			{
				res[i] = arr1[i];
				i++;
				cnt++;
			}
			i = 0;
			while(arr2[i] != '\0')
			{
				res[cnt++] = arr2[i];
				i++;
			}
			cout<<"The Concatenated String is: "<<res<<endl;
		}
		void checkSubString()
		{
				char sub[5];
				//accept the substring 
				cout<<"Enter the substring: "<<endl;
				cin>>sub;
				int i=0,j=0,index;
				//this is the main code
				while(arr1[i] != '\0')
				{
						//first check if the intial alphabet is present in the main string
						//if intial is not found then exit the while as that index points to null
						//if the intial is found exit as the index is pointing to the start alpha
						while(arr1[i] != sub[0] && arr1[i] == '\0')
							i++;
						//this if will check the char of arr[index] .. if it is null exit 
						//if it is NOT null it is pointing the initial sub char
						if(arr1[i] == '\0'
							exit(EXIT_SUCCESS);
						   
						//copy the initial char to the a variable
						index = i;
					//this is personally compare the arr[] and sub[] making sure they both dont end up empty
					//and inc to count if they are equal... then keep incrementing..
					//else exit the loop
					    while (arr1[i] == sub[j] && arr1[i] != '\0' && sub[j] != '\0') 
					    {
        					 i++;
        					 j++;
      					}

					//if the sub array incremented till the end means .. the whole substring has been 
					//traversed .. hence the position is found at main string and print the index var
      					if (sub[j]=='\0')
      						cout<<"The substring is found at location: "<<index;
      					//if the whole string is traversed till the end .. then the substring is not found..
      					if(arr1[i] == '\0')
      						cout<<"Substring is not found !"<<endl;

					//skip the index till the index saved as there is no inital char in that range ..
					//then add 1 to increment the index for the Main string
      					i = index + 1;
					//set the substring index to 0 as to reset for the next check..
      					j = 0;
				}
		}
		void equal()
		{
			int c = 0;

			 while (arr1[c] == arr2[c]) 
			 {
      			if (arr1[c] == '\0' || arr2[c] == '\0')
         			break;
     			c++;
  			 }
			if(arr1[c] == '\0' && arr2[c] == '\0')
				cout<<"The string is Equal !"<<endl;
			else
				cout<<"The String is not equal !"<<endl;
		}
		void rev()
		{
			char rev[MAX];
			int cnt =0,i=0,j = 0;
			while(arr1[i] != '\0')
			{
				cnt++;
				i++;
			}
			i=0;
			cout<<"The reverse of string is: ";
			while(cnt >= 0)
			{
				cout<<arr1[cnt];
				cnt--;
			}
			cout<<endl;

		}
		int len()
		{
			int cnt = 0;
			while(arr1[cnt] != '\0')
			{
				cnt++;
			}
			return cnt;
		}
		void getString1()
		{
			cout<<"Enter the string: "<<endl;
			cin>>arr1;
		}
		void getString2()
		{
			for (int i = 0; i < MAX; ++i)
			{
				arr1[i] = '0';
				arr2[i] = '0';
			};
			cout<<"Enter the first String: "<<endl;
			cin>>arr1;
			cout<<"Enter the second String: "<<endl;
			cin>>arr2;
		}
};

int main()
{
	stringClass s;
	int ch ;
	char status;
	do{
		cout<<"*********MENU***********"<<endl;
		cout<<"1.To Copy"<<endl;
		cout<<"2.To Concatenate"<<endl;
		cout<<"3.To find Substring"<<endl;
		cout<<"4.To Check if Equal"<<endl;
		cout<<"5.To Reverse String"<<endl;
		cout<<"6.To Find the Length"<<endl;
		cout<<"7.Exit"<<endl;
		cout<<"************************"<<endl;
		cout<<"Enter your choice: "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				s.getString1();
				s.copy();
			break;

			case 2:
				s.getString2();
				s.concatenate();
			break;

			case 3:
				s.getString1();
				s.checkSubString();
			break;

			case 4:
				s.getString2();
				s.equal();
			break;

			case 5:
				s.getString1();
				s.rev();
			break;

			case 6:
				s.getString1();
				cout<<"The length is: "<<s.len();
			break;

			case 7:
				exit(EXIT_SUCCESS);
			break;

			default:
				cout<<"Invalid Choice !"<<endl;
		}
		cout<<"Do you want to Re-run the programs ? [Y/N]";
		cin>>status;
	}while(status == 'Y' || status == 'y');
	return 0;
}
