#include <iostream>
using namespace std;                                                                      // AVL Tree Formation

struct Node                                                                              // Node Construction
{
	int Data;
	Node *Left_Node;
	Node *Right_Node;
};

class AVL_Tree                                                                          // Class for Tree Formation
{
public:
	AVL_Tree()
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
			Current = Balance_Tree(Current);
		}
		else if (data >= Current->Data)                                               // If Data is greater than Root
		{
			Current->Right_Node = Insertion(Current->Right_Node, data);
			Current = Balance_Tree(Current);
		}
		return Current;
	}

	int Height_of_Tree(Node *Current)                                                // Checking Height of the Tree
	{
		int Height = 0;
		if (Current != NULL)
		{
			int Left_SubTree = Height_of_Tree(Current->Left_Node);
			int Right_SubTree = Height_of_Tree(Current->Right_Node);

			if (Left_SubTree >= Right_SubTree)
				return (Left_SubTree + 1);                                          // Returning Left Sub Tree if Greater
			else
				return (Right_SubTree + 1);                                         // Returning Right Sub Tree if Greater
		}
		else
			return 0;
		
	}

	int Difference(Node *Current)                                                   // Checking Difference of Left and Right Sub Tree
	{
		if (Root != NULL)
		{
			int Left_SubTree = Height_of_Tree(Current->Left_Node);
			int Right_SubTree = Height_of_Tree(Current->Right_Node);

			int Balance_Factor = Left_SubTree - Right_SubTree;

			return Balance_Factor;                                                 // Returing BF
		}
		else
			cout << endl << "Tree is Empty !" << endl;
		
	}

	Node *Balance_Tree(Node *Current)                                             // Checking Balance of the Tre
	{
		if (Root != NULL)
		{
			int Balance_Factor = Difference(Current);

			if (Balance_Factor > 1)
			{
				if (Difference(Current->Left_Node) > 0)
					Current = LL_Rotation(Current);                              // Criteria for Left Left Rotation
				else
					Current = LR_Rotation(Current);                              // Criteria for Left Right Rotation
			}
			else if (Balance_Factor < -1)
			{
				if (Difference(Current->Right_Node) < 0)
					Current = RR_Rotation(Current);                              // Criteria for Right Right Rotation
				else
					Current = RL_Rotation(Current);                              // Criteria for Right Left Rotation
			}
		}
		else
			cout << endl << "Tree is Empty !" << endl;
		
		return Current;
	}

	void Pre_Order(Node *Current)                                               // Pre-Order Traversal of the AVL Tree
	{
		if (Root != NULL)
		{
			if (Current == NULL)
				return;

			cout << Current->Data << " ";
			Pre_Order(Current->Left_Node);
			Pre_Order(Current->Right_Node);
		}
		else
			cout << endl << "Tree is Empty !" << endl;
	}

	void In_Order(Node *Current)                                                // In-Order Traversal of the AVL Tree
	{
		if (Root != NULL)
		{
			if (Current == NULL)
				return;

			In_Order(Current->Left_Node);
			cout << Current->Data << " ";
			In_Order(Current->Right_Node);
		}
		else
			cout << endl << "Tree is Empty !" << endl;
	}

	void Post_Order(Node *Current)                                              // Post-Order Traversal of the AVL Tree
	{
		if (Root != NULL)
		{
			if (Current == NULL)
				return;

			Post_Order(Current->Left_Node);
			Post_Order(Current->Right_Node);
			cout << Current->Data << " ";
		}
		else
			cout << endl << "Tree is Empty !" << endl;
	}

	Node *LL_Rotation(Node *Current)                                           // Left Left Imbalance Rotation
	{
		Node *Temp = NULL;

		Temp = Current->Left_Node;
		Current->Left_Node = Current->Right_Node;
		Current->Right_Node = Current;

		return Temp;
	}

	Node *LR_Rotation(Node *Current)                                           // Left Right Imbalance Rotation
	{
		Node *Temp = NULL;

		Temp = Current->Left_Node;
		Current->Left_Node = RR_Rotation(Current);

		return LL_Rotation(Current);
	}

	Node *RR_Rotation(Node *Current)                                           // Right Right Imbalance Rotation
	{
		Node *Temp = NULL;

		Temp = Current->Right_Node;
		Current->Right_Node = Current->Left_Node;
		Current->Left_Node = Current;

		return Temp;
	}

	Node *RL_Rotation(Node *Current)                                           // Right Left Imbalance Rotation
	{
		Node *Temp = NULL;

		Temp = Current->Right_Node;
		Current->Right_Node = LL_Rotation(Current);

		return RR_Rotation(Current);
	}

};

int main()                                                                                          // Main Code
{
	AVL_Tree AVL;
	int Choice = 0, Data = 0, Check = 1;

	while (Check == 1)                                                                              // Menu Driven Code
	{
		system("cls");
		cout << endl << " ================= AVL Tree Formation ==================" << endl;         
		cout << endl << "  Press 1 to Make a Node  in AVL Tree                 !" << endl << endl;
		cout << "  Press 2 to Traverse in Tree by In-Order Traversal   !" << endl;
		cout << "  Press 3 to Traverse in Tree by Pre-Order Traversal  !" << endl;
		cout << "  Press 4 to Traverse in Tree by Post-Order Traversal !" << endl << endl;
		cout << "  Press 0 to Exit from System                         !" << endl;
		cout << " ========================================================" << endl;
		cout << endl << "  Enter Choice : ";
		cin >> Choice;
		
		switch (Choice)
		{
		case 1:                                                                                     // For Insertion
		{
			cout << endl<<"Enter Data to Push it in AVL Tree :";
			cin >> Data;
			AVL.Root = AVL.Insertion(AVL.Root, Data);
			cout << endl << endl;
			system("pause");
			break;
		}
		case 2:                                                                                     // For In-Order Traversal
		{
			cout << endl << " In-Order Traversal = ";
			AVL.In_Order(AVL.Root);
			cout << endl << endl;
			system("pause");
			break;
		}
		case 3:                                                                                    // For Pre-Order Traversal
		{
			cout << endl << " Pre-Order Traversal = ";
			AVL.Pre_Order(AVL.Root);
			cout << endl << endl;
			system("pause");
			break;
		}
		case 4:                                                                                    // For Post-Order Traversal
		{
			cout << endl << " Post-Order Traversal = ";
			AVL.Post_Order(AVL.Root);
			cout << endl << endl;
			system("pause");
			break;
		}
		case 0:                                                                                    // Exiting from Loop
		{
			cout << endl << "You Have Exited From The System !" << endl;
			Check = 0;
			break;
		}
		default:
		{
			cout << endl << "Invalid Entry !" << endl;
			break;
		}
		}
	}


	cout << endl << endl;
	system("pause");
}