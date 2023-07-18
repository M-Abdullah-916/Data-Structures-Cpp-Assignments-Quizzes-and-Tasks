#include <iostream>
#include<string>                 // By M.Abdullah
                                 //Without Using Stack Library, it is tougher for me to understand though i have tried to do it.
using namespace std;

void Vpush(int);
int Vpop();                                       // For Operand Stack
void Opush(char);
int Opop();                                       // For Operator Stack

int Precedence(char);
int Operations(int, int, char);                   // Required Functions
int Evaluation(string);

int *VArray = NULL;                               // Operand Stack
int Vtop = -1;

char *OArray = NULL;                              // Operator Stack
int Otop = -1;


int main()
{
	cout << "Evaluated Infix Expression = " <<Evaluation("(1+3+4)*(3+1)/(2+2)");

	cout << endl << endl;
	system("pause");
}

void Vpush(int C)
{
	Vtop++;
	VArray[Vtop] = C;
}
void Opush(char C)
{
	Otop++;
	OArray[Otop] = C;
}

int Vpop()
{
	int x;
	x = VArray[Vtop];
	Vtop--;
	return x;
}

int Opop()
{
	char x;
	x = OArray[Otop];
	Otop--;
	return x;
}

int Precedence(char Operator)
{
	if (Operator == '+' || Operator == '-')
		return 1;
	else if (Operator == '*' || Operator == '/')
		return 2;
	else if (Operator == '^')
		return 3;
	else
	return 0;
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
	OArray = new char[Expressions.length()];

	for (int i = 0; i < Expressions.length(); i++)
	{
		if (Expressions[i] == ' ')
			continue;                                                     //Ignoring Spaces in Expression
		else if (isdigit(Expressions[i]))
		{
			int exp = 0;
			while (i < Expressions.length() && isdigit(Expressions[i]))
			{
				exp = (exp * 10) + (Expressions[i] - '0');                 // ASCII of 0 Because Expression is in character so
				i++;                                                      // it needs to be change into int for solving and if
			}                                                             // there is 2 digit number than this can control it
			Vpush(exp);
			i--;
		}
		else if (Expressions[i] == '(')
		{
			Opush(Expressions[i]);
		}
		else if (Expressions[i] == ')')
		{
			while (Otop!=-1 && OArray[Otop]!='(')
			{
				int X = Vpop();
				int Y = Vpop();                                         // Runs Until () fullfil
				char Z = Opop();
				Vpush(Operations(Y, X, Z));
			}
			Opop();                                                    //Poping ( at last
		}
		else if (Expressions[i] == '+' || Expressions[i] == '-' || Expressions[i] == '*' || Expressions[i] == '/' || Expressions[i] == '^')
		{
			if (Otop == -1)
			{
				Opush(Expressions[i]);
			}
			else if (Otop != -1 && Precedence(OArray[Otop]) <= Precedence(Expressions[i]))
			{
				while (Otop != -1 && Precedence(OArray[Otop]) >= Precedence(Expressions[i]))
				{
					int X = Vpop();
					int Y = Vpop();                                            //Reacting according to Precedence
					char Z = Opop();
					Vpush(Operations(Y, X, Z));
				}
				Opush(Expressions[i]);
			}
			else if(Otop != -1 && Precedence(OArray[Otop]) >= Precedence(Expressions[i]))
			Opush(Expressions[i]);
		}
	}
	if (Vtop != -1)
	{
		while (Otop != -1 )
		{
			int X = Vpop();
			int Y = Vpop();                                // If Any Operator Remains
			char Z = Opop();
			Vpush(Operations(Y, X, Z));
		}
	}
	return Vpop();
}