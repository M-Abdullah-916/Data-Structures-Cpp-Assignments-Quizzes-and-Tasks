#include <iostream>
#include<string>                 // By M.Abdullah
                                 //Without Using Stack Library, it is tougher for me to understand though I have tried to do it.
using namespace std;

void Evaluation(string Expressions);
int *VArray = NULL;                               // Operand Stack
int Vtop = -1;

int main()
{
	cout << "Given Expression is : "; Evaluation("21-321*++") ;
	cout << endl;
	cout << "Given Expression is : "; Evaluation("++*321-21");
	cout << endl;
	cout << "Given Expression is : "; Evaluation("(3+2+1)*(2-1)");

	cout << endl << endl;
	system("pause");
}

void Evaluation(string Expressions)
{
	VArray = new int[Expressions.length()];                               //Stack Creation
	int j = Expressions.length() - 1, i = 0;
	
	for (int i = 0; i < Expressions.length(); i++)
	{
		if (Expressions[i] == ' ')
			continue;
		else if (Expressions[i] == '+' || Expressions[i] == '-' || Expressions[i] == '*' || Expressions[i] == '/' || Expressions[i] == '^')
		{
			cout << "PreFix !";
			break;
		}
		else if (Expressions[j] == '+' || Expressions[j] == '-' || Expressions[j] == '*' || Expressions[j] == '/' || Expressions[j] == '^')
		{
			cout << "PostFix !";
			break;
		}
		else
		{
			cout << "InFix !";
			break;
		}
	}
}