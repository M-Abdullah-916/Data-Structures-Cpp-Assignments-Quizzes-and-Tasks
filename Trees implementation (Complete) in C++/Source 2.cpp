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

	int Count_Leaf(Node *Temp)                                                         // Counting Leaf Nodes
	{
		if (Temp == NULL)
			return 0;
		if (Temp->Left_Node == NULL && Temp->Right_Node == NULL)
			return 1;
		else
			return Count_Leaf(Temp->Left_Node) + Count_Leaf(Temp->Right_Node);

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
		cout << " Press 1 to Enter a Node                      !" << endl;
		cout << " Press 2 to Check Total Numbers of Leaf Nodes !" << endl;
		cout << " Press 0 To Exit From The System              !" << endl;
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
			value = 0;
			value = Tree.Count_Leaf(Tree.Root);
			cout << "Total Number of Leaf Nodes Are : " << value << endl;
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