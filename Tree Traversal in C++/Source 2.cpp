#include <iostream>
#include<string>                 // By M.Abdullah
                                 //Without Using Stack Library, it is tougher for me to understand though I have tried to do it.
using namespace std;

void Vpush(int);
int Vpop();                                       // For Operand Stack

int Operations(int, int, char);                   // Required Functions
int Evaluation(string);

int *VArray = NULL;                               // Operand Stack
int Vtop = -1;

int main()
{
	cout << "Evaluated Prefix Expression = " <<Evaluation("++*123-21");

	cout << endl << endl;
	system("pause");
}

void Vpush(int C)
{
	Vtop++;
	VArray[Vtop] = C;
}

int Vpop()
{
	int x;
	x = VArray[Vtop];
	Vtop--;
	return x;
}

int Operations(int X, int Y, char Operator)
{
	switch (Operator)
	{
	case '+': return X + Y;
	case '-': return X - Y;
	case '*': return X * Y;
	case '/': return X / Y;
	case '^': return X ^ Y;
	}
}

int Evaluation(string Expressions)
{
	VArray = new int[Expressions.length()];                             //Stack Creation

	for (int i = Expressions.length() - 1 ; i >= 0; i--)
	{
		if (Expressions[i] == ' ')
			continue;                                                     //Ignoring Spaces in Expression
		else if (isdigit(Expressions[i]))
		{
			Vpush(Expressions[i] - '0');                    // ASCII of 0 Because Expression is in character so
			                                                // it needs to be change into int for solving 
		}
		else if (Expressions[i] == '+' || Expressions[i] == '-' || Expressions[i] == '*' || Expressions[i] == '/' || Expressions[i] == '^')
		{
			int X = Vpop();                                          //When Operator found, instanly perform action
			int Y = Vpop();                                          // on it then push value into stack of operands  
			char Z = Expressions[i];
			Vpush(Operations(X, Y, Z));
				
		}
		else if (Expressions[i] == '(' || Expressions[i] == ')')
		{
			cout << "ERROR, BRACKETS ARE NOT ENCOUNTERED IN PREFIX EVALUATION !!";
			break;
		}
	}
	return Vpop();
}