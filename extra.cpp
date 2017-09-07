#include<iostream>
using namespace std;

void main()
{
	int n ;
	cout<<"Enter the number: "<<endl;
	cin>>n;
	int remainder = 0, div = 0,cnt = 0;

	while(n > 0) 
	{
		remainder = n % 2; 
		n = n/2;
		if(remainder > 0)
			cnt++;
		
		if(remainder <= 0)
			cnt = 0;
		
	}
	cout<<cnt;
}