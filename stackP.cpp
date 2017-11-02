#include<iostream>
#include<cstring>
#include<stack>

using namespace std;
//function to check the pair or not 
bool pairing(char start , char end)
{
	if(start == '(' && end == ')') return true;
	else if(start == '{' && end == '}') return true;
	else if(start == '[' && end == ']') return true;
	else
		return false;
}

bool checkParameter(string exp)
{
	stack<char> s;
	int i = 0;
	while(exp[i] != '\0')
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			s.push(exp[i]);
		else if(s.empty() || pairing(exp[i],s.top()))
			return false;
		else
			s.pop();

		i++;
	}

	return s.empty()?true:false;
}

int main()
{
	string expression;
	cout<<"Enter an expression:  "; // input expression from STDIN/Console
	cin>>expression;
	if(checkParameter(expression))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";

	return 0;
}
