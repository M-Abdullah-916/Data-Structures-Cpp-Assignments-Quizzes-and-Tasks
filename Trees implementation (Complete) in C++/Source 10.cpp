#include <iostream>
using namespace std;                                                                  // Not Sure About Splittion, Tried but....

struct Node                                                                              // Node Construction
{
	int Data;
	Node *Left_Node;
	Node *Right_Node;
};

class Bst_Tree                                                                          // Class for Tree Formation
{
public:
	Bst_Tree()
	{
		Root = NULL;
	}
	Node *Root;

	Node *Insertion(Node *Current, int data)                                           // Insertion of Nodes
	{
		if (Current == NULL)
		{
			Current = new Node;
			Current->Data = data;
			Current->Left_Node = NULL;
			Current->Right_Node = NULL;
			return Current;
		}
		else if (data < Current->Data)                                                // If Data is lesser than Root
		{
			Current->Left_Node = Insertion(Current->Left_Node, data);
		}
		else if (data >= Current->Data)                                               // If Data is greater than Root
		{
			Current->Right_Node = Insertion(Current->Right_Node, data);
		}
		return Current;
	}

	void In_Order(Node* temp)
	{
		if (temp == NULL)
			return;

		In_Order(temp->Left_Node);
		In_Order(temp->Right_Node);
		cout << " " << temp->Data;
	}

};


int main()
{
	Bst_Tree Tree;
	int choice = 0, value = 0, i = 1;

	while (i != 0)
	{
		system("cls");
		cout << "=================================================" << endl;
		cout << " Press 1 to Enter Values in Tree by an Array  !" << endl << endl;
		cout << " Press 2 to Check Height of the Tree for Monk !" << endl << endl;
		cout << " Press 0 To Exit From The System              !" << endl;
		cout << "=================================================" << endl;
		cout << " Enter Choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int Aray[10] = { 7,3,8,2,9,5,4,1,6,10 };                                   // Array Based Values Input
			for (int i = 0; i < 10; i++)
			{
				Tree.Root = Tree.Insertion(Tree.Root, Aray[i]);
			}
			cout << endl << "Array Based Values Are Inputted !" << endl;
			system("pause");
			break;
		}
		case 2:
		{
			cout << endl << "Enter Key to Reverse Tree : ";
			cin >> value;
			cout << endl << "After Reversing, We Get In-Order as : ";
			Tree.In_Order(Tree.Root);
			cout << endl;
			system("pause");
			break;
		}
		case 0:
		{
			cout << endl << "You have exited from the system !" << endl;
			i = 0;
			break;
		}
		default:
			cout << endl << "Invalid Entry !" << endl;
			system("pause");
			break;
		}

	}


	cout << endl << endl;
	system("pause");
}
