#include<iostream>
#include<math.h>
using namespace std;

struct p{
	int co;
	int power;
};

class poly{
	 public:
        int deg;
        p arr[10];
       
        poly()
        {
        			deg=0;
        			for (int i = 0; i < 10; ++i)
        			{
        				arr[10].co= 0;
        				arr[10].power=0;
        			}
        }
        friend istream & operator >>(istream &input , poly &p)
        {
                		cout<<"enter the degree value: "<<endl;
                		input>>p.deg;
                		int temp = p.deg;
                		cout<<"Enter the Coefficient"<<endl;
                        for (int i = 0; i <=p.deg; i++)
                        {
                       		input>>p.arr[i].co;
                       		p.arr[i].power = temp; //storing the degree value
                       		temp--;
                        }
                        return input; 
        }
        friend ostream & operator<<(ostream &output , poly &p)
        {
                	output<<"The entered polynomial is: "<<endl;
                	int val = p.deg;
                	for (int i = 0; i <=p.deg; ++i)
                	{
                		if(i == p.deg)
                		{
                			output<<p.arr[i].co;
                		}
                		else
                			output<<p.arr[i].co<<"x^"<<p.arr[i].power<<"+";
                	}
                	cout<<endl;
                	return output;
        }
        void add(poly p1)
        {
            p temp[10]; //to store the total power and coefficients 
            p *highestptr , *otherptr; //to point to the highest degree index
            int highestDegree,otherDegree;

            if (deg > p1.deg)
          	{
        		otherDegree = p1.deg;
             	highestDegree = deg;
                highestptr = this->arr;
             	otherptr = p1.arr;	
          	}else
        	{
             	otherDegree = deg;
                highestDegree = p1.deg;
                highestptr = p1.arr;
                otherptr = this->arr;
            }
	            cout<<"adjusting the array coefficients"<<endl;
	            p s[highestDegree];
	            int a = 0;
	            for(int i = highestDegree ; i>=0 ; i--)
	            {
	            	if( a <= otherDegree){
	            		s[i].co = otherptr[a].co;
	            		s[i].power = otherptr[a].power;
	            	}
	            	else{
	            		s[i].co = 0;
	            		s[i].power = otherptr[a].power;
	            	}
	            	a++;
	            }
        
          
            for (int i = 0; i <= highestDegree; i++)
            {
				cout<<"Checking if"<<highestptr[i].co<<"=="<<s[i].co<<endl;
				{
					temp[i].co = highestptr[i].co + s[i].co;
					temp[i].power = highestptr[i].power;
					cout<<"The value inserted at temp [ "<<i<<"] is = "<<temp[i].co<<endl;
					cout<<highestptr[i].co<<"+"<<otherptr[i].co<<"="<<temp[i].co<<" power : "<<temp[i].power<<endl;
				}
            }
	        cout<<"Termination of the addition code !! ******"<<endl;
	               	
	      	//cout<<"The complete addition in polynomial format is : "<<endl;
	      	int t = highestDegree ;
	       	cout<<"Code check: highestDegree value is: "<<highestDegree;
	       	int result=0,x=0;
	       cout<<"Enter the value of x: "<<endl;
	       cin>>x;
	        for(int i = 0; i <= highestDegree; ++i)
	        {
	         if(i == highestDegree)
	         {
	            cout<<temp[i].co;
	            result += temp[i].co;
	         }
	         else{
	            cout<<temp[i].co<<"x^"<<temp[i].power<<"+"; 
	            result += temp[i].co*(pow(x,temp[i].power));
	            }  		
	        }

	        cout<<"The addition of polynomial is: "<<result;
	    }           
};

int main(){
	poly p1,p2;
	cin>>p1;
	cout<<p1;
	cin>>p2;
	cout<<p2;
	p1.add(p2);
	return 0;
}
