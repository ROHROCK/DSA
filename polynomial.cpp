//prg to realize polynomial eq
#include<iostream>
#include<stdlib.h>
#include<math.h>
#define MAX 20
using namespace std ;

class poly{
	int p[MAX];
	int deg;
	int x;
public:
	poly()
	{
		for (int i = 0; i < deg; ++i)
			p[i] = 0;
	}
	void acceptPoly()
	{
		cout<<"Enter the degree: "<<endl;
		cin>>deg;
		cout<<"Enter the coefficient: "<<endl;
		for (int i = 0; i <= deg; i++)
		{
			cout<<"Enter for deg: "<<i<<endl;
			cin>>p[i];
		}
	}

	void displayPoly()
	{
		cout<<"The entered polynomial is: "<<endl;
		for (int i = deg; i >= 0; i--)
		{
			if(i == 0)
			{
				cout<<p[i];
			}else
				cout<<p[i]<<"x^"<<i<<"+";
		}
	}

	void evalPoly()
	{
		int x;
		cout<<"Evaluation of polynomial: "<<endl;
		cout<<"Enter the value of x : "<<endl;
		cin>>x;
		float val = 0;
		for (int i = deg; i >= 0 ; i--)
		{
			if (i == 0)
			{
				val = val + p[i];	
			}
			else
				val = val + pow(p[i],i);
		}

		displayPoly();
		cout<<"The evaluation of poly: "<<endl;
		cout<<val<<endl;
	}


	void add(poly &p1)
	{
		int highestD = max(deg,p1.deg);
		int res[highestD];

		for (int i = 0; i <=highestD; ++i)
			res[i] = 0;

		for (int i = 0; i <= highestD; ++i)
		{
			res[i] = p[i]+p1.p[i]; //adding to the resultant array
		}

		cout<<"The result is: "<<endl;
		//displaying the result ..
		for (int i = highestD; i >= 0; i--)
		{
			if(i == 0)
			{
				cout<<res[i];
			}else
				cout<<res[i]<<"x^"<<i<<"+";
		}
		//then u can evalute all the cal urself !
		//cout<<"Enter the value of X"<<endl;
	}

};


int main()
{
	poly p1,p2;
	p1.acceptPoly();
	p1.displayPoly();
	p2.acceptPoly();
	p2.displayPoly();
	p1.add(p2); //function to be added ! 
	return 0;
}
