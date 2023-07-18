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

	void Delete_Node(Node *root, int Key)
	{
		Node *temp = root;
		if (temp == NULL)
		{
			cout << endl << "Tree is Empty !" << endl;
			return;
		}
		else if (temp->Left_Node->Data == Key && temp->Left_Node != NULL)
		{
			Node *temp1 = temp->Left_Node;
			cout << endl << "Required Node is Deleted !" << endl;
			temp->Left_Node = NULL;
			free(temp1);
			return;
		}
		else if (temp->Right_Node->Data == Key && temp->Right_Node != NULL)
		{
			Node *temp1 = temp->Right_Node;
			cout << endl << "Required Node is Deleted !" << endl;
			temp->Right_Node = NULL;
			free(temp1);
			return;
		}
		else if (temp->Left_Node == NULL && temp->Right_Node == NULL)
		{
			if (Key == temp->Data)
			{
				Node *temp1 = Root;
				cout << endl << "Required Node is Deleted !" << endl;
				Root = NULL;
				free(temp1);
				return;
			}
			else
				cout << endl << "There is NO Such Node in the Tree !" << endl;
		}
		else
		{
			Delete_Node(temp->Left_Node, Key);
			if (Key == temp->Data)
			{
				Node *temp1 = temp;
				cout << endl << "Required Node is Deleted !" << endl;
				Root = NULL;
				free(temp1);
				return;
			}
			Delete_Node(temp->Right_Node, Key);

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
		cout << " Press 1 to Enter a Node                      !" << endl;
		cout << " Press 2 to Delete Any Node From Tree         !" << endl;
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
			cout << endl << "Enter Value to Delete Respective Node :";
			cin >> value;
			Tree.Delete_Node(Tree.Root, value);
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