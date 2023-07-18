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

	int BST_OR_NOT(Node* root, Node* Left = NULL, Node* Right = NULL)
	{

		if (root == NULL)
			return 1;

		if (Left != NULL && root->Data <= Left->Data)                                                       // Checking Left Data
			return 0;

		if (Right != NULL && root->Data >= Right->Data)                                                    // Checking Right Data
			return 0;

		return BST_OR_NOT(root->Left_Node, Left, root) && BST_OR_NOT(root->Right_Node, root, Right);       // Traversing in Tree
			
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
		cout << " Press 1 to Enter a Value in Tree             !" << endl << endl;
		cout << " Press 2 to Perform In-Order Traversal        !" << endl;
		cout << " Press 3 to Perform Pre-Order Traversal       !" << endl;
		cout << " Press 4 to Perform Post-Order Traversal      !" << endl << endl;
		cout << " Press 5 to Check That Tree is BST or NOT     !" << endl;
		cout << " Press 0 To Exit From The System              !" << endl;
		cout << "=================================================" << endl;
		cout << " Enter Choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:                                                              
		{
			cout << endl << "Enter Value to Enter it in Tree : ";
			cin >> value;
			Tree.Root = Tree.Insertion(Tree.Root, value);
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
			cout << endl<<"Pre-Order Traversal : ";
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
		case 5:
		{
			cout << endl;
			value = Tree.BST_OR_NOT(Tree.Root);
			if (value == 1)
				cout << endl << "Tree is Binary Search Tree !" << endl;
			else
				cout << endl << "Tree is Not Binary Search Tree !" << endl;
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