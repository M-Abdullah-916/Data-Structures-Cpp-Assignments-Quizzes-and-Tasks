#include <iostream>
#include<string>                 // By M.Abdullah
                                 //Without Using Stack Library, it is tougher for me to understand though I have tried to do it.
using namespace std;


char *OArray = NULL;                              // Operator Stack
int Otop = -1;

void Opush(char C);
int Opop();
int Precedence(char Operator);
int Check(string Expressions);                    // Required Function
string In_To_Post(string Expression);
string In_To_Pre (string Expression);
string Pre_To_In (string Expression);
string Post_To_In(string Expression);


int main()
{
	string Expression;
	int opt,i;
	cout << "----------------------------------------------" << endl;
	cout << endl << "Write your Expression : ";
	cin >> Expression;
	cout << endl << "Given Expression is : "; i = Check(Expression);
	cout << endl;
	
	switch (i)
	{
	case 1:
	{
		cout << endl;
		cout << " Press 1 to Change into Infix !! " << endl;
		cout << " Press 2 to Change into PostFix !! " << endl;
		cin >> opt;
		
		break;
	}
	case 2:
	{
		cout << endl;
		cout << " Press 1 to Change into Infix !! " << endl;
		cout << " Press 2 to Change into Prefix !! " << endl;
		cin >> opt;
		break;
	}
	case 3:
	{
		cout << endl;
		cout << " Press 1 to Change into Prefix !! " << endl;
		cout << " Press 2 to Change into Postfix !! " << endl;
		cin >> opt;
		if (opt == 1)
		{
		}
		else if (opt == 2)
		{
			cout << endl << "PostFix = " << In_To_Post(Expression);
		}
		else
			cout << endl << "Invalid Entry !!" << endl;
		break;
	}
	default:
		cout << "Invalid Entry !! " << endl;
	}


	cout << endl << endl;
	system("pause");
}

void Opush(char C)
{
	Otop++;
	OArray[Otop] = C;
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


int Check(string Expressions)
{
	int j = Expressions.length() - 1, i = 0;
	
	for (int i = 0; i < Expressions.length(); i++)
	{
		if (Expressions[i] == ' ')
			continue;
		else if (Expressions[i] == '+' || Expressions[i] == '-' || Expressions[i] == '*' || Expressions[i] == '/' || Expressions[i] == '^')
		{
			cout << "PreFix !";
			return 1;
			break;
		}
		else if (Expressions[j] == '+' || Expressions[j] == '-' || Expressions[j] == '*' || Expressions[j] == '/' || Expressions[j] == '^')
		{
			cout << "PostFix !";
			return 2;
			break;
		}
		else
		{
			cout << "InFix !";
			return 3;
			break;
		}
	}
}

string In_To_Post(string Expression)
{
	OArray = new char[Expression.length()];
	string Final;

	for (int i = 0; i < Expression.length(); i++)
	{
		if ((Expression[i] >= 'a' && Expression[i] <= 'z') || (Expression[i] >= 'A' && Expression[i] <= 'Z') ||
			(Expression[i] >= '1' && Expression[i] <='9' ))
		{
			Final = Final + Expression[i];
		}
		else if (Expression[i] == '(')
		{
			Opush(Expression[i]);
		}
		else if (Expression[i] == ')')
		{
			while (Otop != -1 && OArray[Otop] == '(')
			{
				char opt = Opop();
				Final = Final + opt;
			}
			Opop();
		}
		else
		{
			while (Otop != -1 && Precedence(OArray[Otop]) >= Precedence(Expression[i]))
			{
				char opt = Opop();
				Final = Final + opt;
			}
			Opush(Expression[i]);
		}
	}
	while (Otop != -1)
	{
		char opt = Opop();
		Final = Final + opt;
	}
	return Final;
}