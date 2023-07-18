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

	void In_Order(Node *C)                                                          // In order traversal
	{
		if (Root == NULL)
		{
			cout << endl << "Tree is Empty !" << endl;
			return;
		}
		else
		{
			if (C == NULL)
				return;

			In_Order(C->Left_Node);
			cout << " " << C->Data;
			In_Order(C->Right_Node);
		}

	}

	void Pre_Order(Node *C)                                                          // Pre Order traversal
	{
		if (Root == NULL)
		{
			cout << endl << "Tree is Empty !" << endl;
			return;
		}
		else
		{
			Node *temp = C;
			if (temp == NULL)
				return;

			cout << " " << C->Data;
			Pre_Order(temp->Left_Node);
			Pre_Order(temp->Right_Node);
		}
	}

	void Post_Order(Node *C)                                                        // Post Order traversal
	{
		if (Root == NULL)
		{
			cout << endl << "Tree is Empty !" << endl;
			return;
		}
		else
		{
			Node *temp = C;
			if (temp == NULL)
				return;

			Post_Order(temp->Left_Node);
			Post_Order(temp->Right_Node);
			cout << " " << C->Data;
		}
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
		cout << " Press 1 to Enter a Values Based on Array     !" << endl << endl;
		cout << " Press 2 to Perform In-Order Traversal        !" << endl;
		cout << " Press 3 to Perform Pre-Order Traversal       !" << endl;
		cout << " Press 4 to Perform Post-Order Traversal      !" << endl << endl;
		cout << " Press 0 To Exit From The System              !" << endl;
		cout << "=================================================" << endl;
		cout << " Enter Choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:                                                              // Array Based Implementation
		{
			int Aray[10] = { 1,3,5,7,9,2,4,6,8,10 };
			for (int i = 0; i < 10; i++)
			{
				Tree.Root = Tree.Insertion(Tree.Root, Aray[i]);
			}
			cout << endl << "Values Added from Array !" << endl;
			system("pause");
			break;
		}
		case 2:
		{
			cout << endl << "In-Order Traversal : ";
			Tree.In_Order(Tree.Root);
			cout << endl;
			system("pause");
			break;
		}
		case 3:
		{
			cout << endl << "Pre-Order Traversal : ";
			Tree.Pre_Order(Tree.Root);
			cout << endl;
			system("pause");
			break;
		}
		case 4:
		{
			cout << endl << "Post-Order Traversal : ";
			Tree.Post_Order(Tree.Root);
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
