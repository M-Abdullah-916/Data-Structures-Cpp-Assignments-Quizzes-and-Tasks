#include <iostream>
using namespace std;

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
			//Root = Current;
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

	void Max_root()                                                                // Showing Maximum value
	{
		if (Root != NULL)
		{
			Node *temp = Root;
			while (temp->Right_Node != NULL)
			{
				temp = temp->Right_Node;
			}
			cout << endl << " Max Node is : " << temp->Data << endl;
		}
		else
			cout << "Tree is Empty !!" << endl;

	}

	void Min_root()                                                               //Showing Minimum value
	{
		if (Root != NULL)
		{
			Node *temp = Root;
			while (temp->Left_Node != NULL)
			{
				temp = temp->Left_Node;
			}
			cout << endl << " Min Node is : " << temp->Data << endl;
		}
		else
			cout << "Tree is Empty !!" << endl;
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
		cout << " Press 1 to Enter a Node                !" << endl;
		cout << " Press 2 to Check Maximum Value of Node !" << endl;
		cout << " Press 3 to Check Minimum Value of Node !" << endl;
		cout << " Press 0 to Exit through System         !" << endl;
		cout << "=================================================" << endl;
		cout << " Enter Choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << endl << "Enter Value for the Node :";
			cin >> value;
			Tree.Root = Tree.Insertion(Tree.Root, value);
			system("pause");
			break;
		}
		case 2:
		{
			cout << endl;
			Tree.Max_root();
			cout << endl;
			system("pause");
			break;
		}
		case 3:
		{
			cout << endl;
			Tree.Min_root();
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
		}

	}


	cout << endl << endl;
	system("pause");
}