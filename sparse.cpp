//Akshay modify the functions
#include<iostream>
#include<stdlib.h>
#define MAX 3
using namespace std;

class sparse 
{
	int mat1[MAX][MAX] ,mat2[MAX][MAX],sp1[MAX][3]sp2[MAX][3];
	
	public : 
	void addSparse()
	{
		
	}
	void inMat()
	{
		cout<<"Enter the elements for Matrix 1: "<<endl;
		for(int i=0;i<MAX;i++)
		{
			for(int j = 0  ; j<MAX ; j++)
			{
				cin>>mat1[i][j];	
			}
			
		}

		cout<<"Enter the elements for Matrix 2: "<<endl;
		for(int i=0;i<MAX;i++)
		{
			for(int j = 0  ; j<MAX ; j++)
			{
				cin>>mat2[i][j];	
			}
		}		
	}

	void opMat()
	{
		cout<<"Matrix 1: "<<endl;
		for(int i=0;i<MAX;i++)
		{
			for(int j = 0  ; j<MAX ; j++)
			{
				cout<<mat1[i][j]<<" ";	
			}
			cout<<"\n";
		}

		cout<<"Matrix 2: "<<endl;
		for(int i=0;i<MAX;i++)
		{
			for(int j = 0  ; j<MAX ; j++)
			{
				cout<<mat2[i][j]<<" ";	
			}
			cout<<"\n";
		}		
	}

	void add()
	{
		cout<<"The addition of Matrix is: "<<endl;
		for(int i=0;i<MAX;i++)
		{
			for(int j = 0  ; j<MAX ; j++)
			{
				cout<<(mat1[i][j]+mat2[i][j])<<"\t";	
			}
			cout<<"\n";
		}
	}

	void Transpose()
	{
		cout<<"The Transpose of Matrix 1:"<<endl;
		for(int i=0;i<MAX;i++)
		{
			for(int j = 0  ; j<MAX ; j++)
			{
				cout<<mat1[j][i]<<" ";	
			}
			cout<<"\n";
		}
		cout<<"The Transpose of Matrix 2:"<<endl;
		for(int i = 0 ; i < MAX ; i++)
		{
			for(int j= 0 ; j<MAX ;j++)
				cout<<mat2[j][i]<<" ";
			cout<<"\n";
		}
	}

	//code for fast transpose 
	void FastTranspose()
	{
		//taking a two dimensional array to store the col and rows of the non-zero values
		int cnt=0,cnt1=0;
		//To find the number of elements which are non-zero
		for(int i=0;i<MAX;i++){
			for(int j=0;j<MAX;j++)
			{
				if(mat1[i][j] != 0)
					cnt++;	
				if(mat2[i][j] != 0)
					cnt1++;
			}	
		}

		int array[cnt][3],array1[cnt1][3];

		int s = 0; //this will be used to traverse the matrix
		for(int i=0;i<MAX;i++) 
		{
			for(int j=0;j<MAX;j++)
			{
				if(mat1[i][j] != 0)
				{
					array[s][0] = i; cout<<"row: "<<s<<endl;//rows 
					array[s][1] = j; cout<<"col: "<<"1"<<endl;//columns
					array[s++][2] = mat1[i][j]; 
				}
			}
			cout<<endl;
		}	

		s = 0; 
		for(int i=0;i<MAX;i++) 
		{
			for(int j=0;j<MAX;j++)
			{
				if(mat2[i][j] != 0)
				{
					array1[s][0] = i; 
					array1[s][1] = j; 
					array1[s++][2] = mat2[i][j]; 
				}
			}
			cout<<endl;
		}	

		cout<<"The sparse matrix 1 is: "<<endl;
		cout<<"Rows\tCol\tData"<<endl;

		for(int i = 0 ; i<cnt;i++){
			for(int j = 0 ; j<3;j++)
			{
				cout<<array[i][j]<<"\t";
			}
			cout<<"\n";		
		}

		cout<<"The sparse matrix 2 is: "<<endl;
		cout<<"Rows\tCol\tData"<<endl;

		for(int i = 0 ; i<cnt1;i++){
			for(int j = 0 ; j<3;j++)
			{
				cout<<array1[i][j]<<"\t";
			}
			cout<<"\n";		
		}}
	
};

int main()
{
	sparse s;
	int ch;
	char status;
	do{
		cout<<"***MENU***"<<endl;
		cout<<"1.Enter the data for Matrix"<<endl;
		cout<<"2.Display the Matrix"<<endl;	
		cout<<"3.Display the Transpose Matrix"<<endl;
		cout<<"4.Addition of Matrix"<<endl;
		cout<<"5.Fast Transpose"<<endl;
		cout<<"6.Exit"<<endl;		
		cout<<"**********"<<endl;
		cout<<"Enter your choice: "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1: s.inMat(); break;
			case 2: s.opMat(); break;
			case 3: s.Transpose(); break;
			case 4: s.add(); break;
			case 5: s.FastTranspose(); break;
			case 6: exit(EXIT_SUCCESS);
			default:
				cout<<"Wrong Choice !";
			 
		}
		cout<<"Do you want to continue ? [Y/N]"<<endl;
		cin>>status;
	}while(status == 'Y' || status == 'y');
	return 0;
}
