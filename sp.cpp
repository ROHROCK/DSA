#include<iostream>
#include<stdlib.h>
#define MAX 20
using namespace std;


class sp
{
	int mat1[MAX][MAX],mat2[MAX][MAX];
	int sp1[MAX][3],sp2[MAX][3],sp3[MAX][3];
	int c1,r1,c2,r2;
	int cntNZ1 , cntNZ2 ;
public:
	//to accept the matrix info
	void getMat()
	{
		cout<<"Enter the row size"<<endl;
		cin>>r1;
		cout<<"Enter the col size"<<endl;
		cin>>c1;

		for (int i = 0; i < r1; ++i)
		{
			for (int j = 0; j < c1; ++j)
			{
				cout<<"Enter data for mat1["<<i<<"]["<<j<<"]: ";
				cin>>mat1[i][j];
				cout<<endl;
			}
		}

		cout<<"Enter the row size"<<endl;
		cin>>r2;
		cout<<"Enter the col size"<<endl;
		cin>>c2;

		for (int i = 0; i < r2; ++i)
		{
			for (int j = 0; j < c2; ++j)
			{
				cout<<"Enter data for mat2["<<i<<"]["<<j<<"]: ";
				cin>>mat2[i][j];
				cout<<endl;
			}
		}
	}

	void disp()
	{
		cout<<"Mat 1: "<<endl;
		for (int i = 0; i < r1; ++i)
		{
			for (int j = 0; j < c1; ++j)
			{
				cout<<mat1[i][j]<<" ";
			}
			cout<<endl;
		}

		cout<<"Mat 2: "<<endl;
		for (int i = 0; i < r2; ++i)
		{
			for (int j = 0; j < c2; ++j)
			{
				cout<<mat2[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	//sparse matrix 
	void sparse()
	{
		cntNZ1 = 0;
		cntNZ2 = 0;
		//since the sparse matrix row 0 contains the info of sparse matrix 
		sp1[0][0] = r1;
		sp1[0][1] = c1;
	
		//seperate counter for sparse matrix
		int z=1;
		for (int i = 0; i < r1; ++i) 
		{
			for (int j = 0; j < c1; ++j)
			{
				if (mat1[i][j] != 0)
				{
					sp1[z][0] = i; //copy the row 
					sp1[z][1] = j; //copy the col 
					sp1[z][2] = mat1[i][j]; //copy the val
					z++;
					cntNZ1++;
				}
			}
		}
		sp1[0][2] = cntNZ1;


		sp2[0][0] = r2;
		sp2[0][1] = c2;
		z = 1;
		for (int i = 0; i < r1; ++i)
		{
			for (int j = 0; j < c2; ++j)
			{
				if (mat2[i][j] > 0)
				{
					sp2[z][0] = i; //copy the row 
					sp2[z][1] = j; //copy the col 
					sp2[z][2] = mat2[i][j]; //copy the val
					z++;
					cntNZ2++;
				}
			}
		}
		sp2[0][2] = cntNZ2;

		cout<<"Non zero values: "<<cntNZ1<<endl;
		cout<<"The sparse matrix 1 is: "<<endl;
		cout<<"Rows\tCol\tData"<<endl;

		for(int i = 0 ; i<=cntNZ1;i++){
			for(int j = 0 ; j<3;j++)
			{
				cout<<sp1[i][j]<<"\t";
			}
			cout<<"\n";		
		}

		cout<<"Non zero values: "<<cntNZ2<<endl;
		cout<<"The sparse matrix 2 is: "<<endl;
		cout<<"Rows\tCol\tData"<<endl;

		for(int i = 0 ; i<=cntNZ2;i++){
			for(int j = 0 ; j<3;j++)
			{
				cout<<sp2[i][j]<<"\t";
			}
			cout<<"\n";		
		}
	}

	void addSparse()
	{
		int k1,k2,k3;
		int total1,total2;
		//addition of sparse matrix 
		if (sp1[0][0] != sp2[0][0] || sp1[0][1] != sp2[0][1])
		{
			cout<<"Invalid matrix size"<<endl;
			exit(EXIT_SUCCESS);
		}

		total1 = sp1[0][2]; //store no. non-Zero ele
		total2 = sp2[0][2]; 
		k1 = k2 = k3 = 1;
		while(k1 <= total1 && k2 <= total2)
		{
			if (sp1[k1][0] < sp2[k2][0]) //find smallest row
			{
				sp3[k3][0] = sp1[k1][0];
				sp3[k3][1]= sp1[k1][1];
				sp3[k3][2] = sp1[k1][2];
				k3++;
				k1++;
			}else if(sp1[k1][0] > sp2[k2][0])
			{
				sp3[k3][0] = sp2[k2][0];
				sp3[k3][1]= sp2[k2][1];
				sp3[k3][2] = sp2[k2][2];
				k3++;
				k2++;
			}
			else if(sp1[k1][0] == sp2[k2][0])
			{
				//if row is = then check for 
				//col cmp
				if (sp1[k1][1] < sp2[k2][1])
				{
					sp3[k3][0] = sp1[k1][0];
					sp3[k3][1]= sp1[k1][1];
					sp3[k3][2] = sp1[k1][2];
					k3++;
					k1++;
				}else if(sp1[k1][1] >sp2[k2][1])
				{
					sp3[k3][0] = sp2[k2][0];
					sp3[k3][1]= sp2[k2][1];
					sp3[k3][2] = sp2[k2][2];
					k3++;
					k2++;
				}else
				{
					sp3[k3][0] = sp2[k2][0];
					sp3[k3][1] = sp2[k2][1];
					sp3[k3][2] = sp1[k1][2] + sp2[k2][2];
					k3++; //inc all as they are same
					k2++;
					k1++;
				}
			}
		}

		//this is for remaining part ...
		//if there is any elements remaining
		while ( k1 <=total1 )
		{
			sp3[k3][0] = sp1[k1][0];
			sp3[k3][1] = sp1[k1][1];
			sp3[k3][2] = sp1[k1][2];
			k3++;k1++;
		} 
	
		while ( k2 <= total2 )
		{
			sp3[k3][0] = sp2[k2][0];
			sp3[k3][1] = sp2[k2][1];
			sp3[k3][2] = sp2[k2][2];
			k3++;k2++;
		} 

		sp3[0][0] = sp1[0][0];
		sp3[0][1] = sp1[0][1];
		sp3[0][2] = k3-1;

		cout<<"The sparse matrix 2 is: "<<endl;
		cout<<"Rows\tCol\tData"<<endl;
		cout<<"The addition of sparse matrix is: "<<endl;
		for (int i = 0; i < k3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cout<<sp3[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	void transpose(int b1[][3],int b2[][3])
{
    int i,j,k,n;
    b2[0][0]=b1[0][1];
    b2[0][1]=b1[0][0];
    b2[0][2]=b1[0][2];
    
    k=1;
    n=b1[0][2];
    
    for(i=0;i<b1[0][1];i++)
        for(j=1;j<=n;j++)
            //if a column number of current triple==i then insert the current triple in b2
            if(i==b1[j][1])
            {
                b2[k][0]=i;
                b2[k][1]=b1[j][0];
                b2[k][2]=b1[j][2];
                k++;
            }
}
};

int main()
{
	sp s;
	s.getMat();
	s.disp();
	s.sparse();
	cout<<"***************************"<<endl;
	s.addSparse();
	cout<<"***************************"<<endl;
	s.transpose(); //normal transpose()
	cout<<"***************************"<<endl;
	s.fastTranspose(); //fast transpose()
	cout<<"***************************"<<endl;
	return 0;
}