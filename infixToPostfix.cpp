//This program is used to convert infix expression to postfix expression and it can
// convert the prefix to postfix expression
//This is a incomplete program ! 
/*
Erase the following once your done Akshay : 
1.prefix to infix
2.postfix to infix
*/
#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;

class conversion{
public:
	//it will accept the infix expression
	string infixToPostfix(string expression)
	{
		//Declaring a stack from std template library
		stack<char> S;
		string postfix = "";
		for (int i = 0; i < expression.length();i++)
		{
			/* code */
			//scan left to right
			//if there is any spaces or , then just continue ..
			if (expression[i] == ' ' || expression[i] == ',')
				continue;
			else if(IsOperator(expression[i]))
			{
				//the stack is not empty and the operator is has higher precedance then TOP and it is not a openining
				//parathensis
				while(!S.empty() && hasHigherPrecedance(S.top(),expression[i]) && S.top() != '(')
				{
					postfix += S.top();
					S.pop();
				}
				//then push the operator to the stack
				S.push(expression[i]);
			}
			else if(IsOperand(expression[i]))
			{
				postfix += expression[i];
			}
			//If there is a opening para then push the elements as it will push the contents 
			//of eg: (A-B
			else if(expression[i]== '(')
			{
				S.push(expression[i]);
			}
			//This will make sure the - operator will not be overriden by the other higher operator 
			//so to that when the closing para is found then do the following...
			else if (expression[i] == ')')
			{
				while(S.top() != '(' && !S.empty())
				{
					postfix += S.top(); //store the operand in between the para
					S.pop();
				}
				S.pop(); //this is to pop the closing bracket
			}
	}

	//this condition is for when the expression is over and 
	while(!S.empty())
	{
		postfix +=+S.top();
		S.pop();
	}

	return postfix;
	
	}

	//to check if the operand exist in these ranges 
	bool IsOperand(char exp)
	{
		if(exp >= '0' && exp <= '9') return true;
		if(exp >= 'a' && exp <= 'z') return true;
		if(exp >= 'A' && exp <= 'Z') return true;
		return false;
	}

	int IsOperator(char exp)
	{
		if(exp == '+' ||exp == '-' || exp == '/' || exp =='^' || exp == '*')
			return true;

		return false;
	}
	//this will return the va
	int getOperatorWeight(char a)
	{
		int weight = -1;
		switch(a)
		{
			case '+':
			case '-':
				weight = 1;
			break;
		
			case '*':
			case '/':
				weight = 2;
			break;
			
			case '^':
				weight = 3;
			break;
		}
		return weight;
	}

	//this will compare the top element and the exp ...
	//it will return true IF the top element has higher value then expression char
	int hasHigherPrecedance(char top , char exp)
	{
		int topweight = getOperatorWeight(top);
		int expweight = getOperatorWeight(exp);

		//if both the weights are equal then check the precendence 
		//if it is a right precedance then false like ^
		//if it is a left precefance then true like + , / , - , * 
		if (topweight == expweight)
		{
			if (rightAssociative(topweight))
				return false;
			else
				return true;
		}
		return (topweight>expweight)?true:false;
	}

	int rightAssociative(char check)
	{
		if (check == '^')
		 	return 1;
		else
			return 0;
	}

	string customRev(string exp)
	{
		string rev;
		for (int i = 0; i < exp.length(); ++i)
		{
			if(exp[i] == ')')
				rev+='(';
			else if(exp[i] == '(')
				rev+=')';
			else
				rev+=exp[i];
		}
		return rev;
	}

	void preToPostfix(string exp)
	{
		stack<string> S;
		int i= 0;
		string str1,str2;
		i = exp.length() - 1;
		//read the elements from right to left
		while(i >= 0)
		{
			if (IsOperand(exp[i]))
			{
				str1 = "";
				str1 = exp[i];
				S.push(str1); //push the operand
			}
			else if(IsOperator(exp[i]))
			{
				str1 = S.top();
				S.pop();
				str2 = S.top();
				S.pop();
				str2+= exp[i]; //append the second last element and the operator eg : B+
				S.push(str1+str2);
			}
			i--;
		}
		string postfix  = S.top();
		S.pop();
		cout<<"The posfix expression is: "<<postfix<<endl;
	}
};

int main()
{
	int ch;
	conversion c;
	string exp;
	char status;
	//string res = c.infixToPostfix(exp);
	//cout<<"The result is: "<<res<<endl;
	do{
		cout<<"****MENU*****"<<endl;
		cout<<"1.To convert infix To prefix: "<<endl;
		cout<<"2.To convert prefix To postfix: "<<endl;
		cout<<"3.To convert prefix to infix: "<<endl;
		cout<<"4.To convert postfix to infix"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"************"<<endl;
		cout<<"Enter your choice: "<<endl;
		cin>>ch;
		string prefix,infixRev;
		switch(ch)
		{
			case 1:
				cout<<"Enter the infix expression"<<endl;
				cin>>exp;
				infixRev = c.customRev(exp);
				reverse(infixRev.begin(),infixRev.end());
			    prefix = c.infixToPostfix(infixRev);
				reverse(prefix.begin(),prefix.end());
				cout<<"The prefix is: "<<prefix<<endl;
			break;

			case 2:
				cout<<"Enter the prefix expression: "<<endl;
				cin>>prefix;
				c.preToPostfix(prefix);
			break;

			case 3:
				//Enter the code for prefix to infix
			break;

			
			case 4:
				//Enter the code for postfix to infix
			break;

			case 5:
				exit(EXIT_SUCCESS);
			break;

			default:
				cout<<"Wrong choice !"<<endl;
		}
		cout<<"Do you want to continue ?[Y/N]"<<endl;
		cin>>status;
	}while(status == 'y' || status == 'y');
	return 0;
}