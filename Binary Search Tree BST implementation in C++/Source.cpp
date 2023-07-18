#include<iostream>
#include <string>                                              //Management Using BST Formation
using namespace std;

struct Node
{
	string Name;
	int Roll_no;                                                 // Student Data
	float CGPA;
	string Department;
	Node *Left_Node;
	Node *Right_Node;
};

class Management
{
public:
	Management()
	{
		Head = NULL, current = NULL;
	}
	Node *Head, *current;

	void insertion(string name, int roll, float cgpa, string department)
	{
		Node *temp = new Node;                      //Insertion on CGPA
		current = Head;

		temp->CGPA = cgpa;
		temp->Department = department;
		temp->Name = name;
		temp->Roll_no = roll;
		if (Head == NULL)
		{
			Head = temp;                                             // If there is no tree
			temp->Left_Node = NULL;
			temp->Right_Node = NULL;
			current = Head;
		}
		else
		{
			int i;
			while (i = 1)
			{
				if (current->Left_Node != NULL && current->Right_Node != NULL)
				{
					if (cgpa >= current->CGPA)
					{
						current = current->Right_Node;
					}                                                    // If tree exist then go to leaf node (Multiple nodes)
					else if (cgpa < current->CGPA)
					{
						current = current->Left_Node;
					}
					if (current->Right_Node == NULL && current->CGPA <= cgpa)
					{
						i = 0;
						break;
					}
					if (current->Left_Node == NULL&&current->CGPA >= cgpa)
					{
						i = 2;
						break;
					}
				}
				else
				{
					if (cgpa >= current->CGPA)
					{
						current->Right_Node = temp;
						temp->Right_Node = NULL;
						temp->Left_Node = NULL;
						break;
					}
					if (cgpa < current->CGPA)                                    // if there is only one node
					{
						current->Left_Node = temp;
						temp->Right_Node = NULL;
						temp->Left_Node = NULL;
						break;
					}
				}

			}
			if (i == 0)
			{
				current->Right_Node = temp;
				temp->Left_Node = NULL;
				temp->Right_Node = NULL;
			}
			if (i == 2)
			{
				current->Left_Node = temp;
				temp->Right_Node = NULL;
				temp->Left_Node = NULL;
			}
			current = Head;
		}
	}

	void In_Order(Node *C)                                                          // In order traversal
	{
		if (Head == NULL)
		{
			cout << endl << "Tree is Empty !" << endl;
			return;
		}
		else
		{
			if (C == NULL)
				return;

			In_Order(C->Left_Node);
			cout << " Name = " << C->Name << "____ CGPA = " << C->CGPA << "____ ROLL NO. = " << C->Roll_no << "____ Department = " << C->Department << endl;
			In_Order(C->Right_Node);
		}

	}

	void Pre_Order(Node *C)                                                          // Pre Order traversal
	{
		if (Head == NULL)
		{
			cout << endl << "Tree is Empty !" << endl;
			return;
		}
		else
		{
			Node *temp = C;
			if (temp == NULL)
				return;

			cout << " Name = " << C->Name << "____ CGPA = " << C->CGPA << "____ ROLL NO. = " << C->Roll_no << "____ Department = " << C->Department << endl;
			Pre_Order(temp->Left_Node);
			Pre_Order(temp->Right_Node);
		}
	}

	void Post_Order(Node *C)                                                        // Post Order traversal
	{
		if (Head == NULL)
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
			cout << " Name = " << C->Name << "____ CGPA = " << C->CGPA << "____ ROLL NO. = " << C->Roll_no << "____ Department = " << C->Department << endl;
		}
	}

	void Max_CGPA()                                                                // Showing Maximum CGPA
	{
		if (Head != NULL)
		{
			current = Head;
			while (current->Right_Node != NULL)
			{
				current = current->Right_Node;
			}
			cout << endl << "Student with Maximum CGPA is : " << " Name = " << current->Name << "____ CGPA = " << current->CGPA << "____ ROLL NO. = " << current->Roll_no << "____ Department = " << current->Department << endl;
			current = Head;
		}
		else
			cout << "Tree is Empty !!" << endl;

	}

	void Min_CGPA()                                                               //Showing Minimum CGPA
	{
		if (Head != NULL)
		{
			current = Head;
			while (current->Left_Node != NULL)
			{
				current = current->Left_Node;
			}
			cout << endl << "Student with Manimum CGPA is : " << " Name = " << current->Name << ".... CGPA = " << current->CGPA << ".... ROLL NO. = " << current->Roll_no << ".... Department = " << current->Department << endl;
			current = Head;
		}
		else
			cout << "Tree is Empty !!" << endl;
	}

	int Height_Tree(Node* C)                                                       // Showing Height of Tree
	{
		if (Head == NULL)
		{
			cout << endl << "Tree is Empty !" << endl;
			return 0;
		}
		else
		{
			Node *temp = C;
			if (temp == NULL)
				return 0;

			int Left_Height = Height_Tree(temp->Left_Node);
			int Right_Height = Height_Tree(temp->Right_Node);

			if (Left_Height >= Right_Height)
				return(Left_Height + 1);
			else return(Right_Height + 1);
		}

	}

	void Edges_From_Root()                                                        // Showing Edges of Tress from Main Root Node
	{
		if (Head != NULL)
		{
			current = Head;
			int x = Height_Tree(current);
			cout << "Edges of Tree to Maximum Height Are : " << x - 1 << endl;
			current = Head;
		}
		else
			cout << endl << "Tree is Empty !!" << endl;
	}

	void Search_Roll_No(int roll, Node *C)                                        // Searching with Roll Number
	{
		if (Head == NULL)
		{
			cout << endl << "Tree is Empty !" << endl;
			return;
		}
		else
		{
			Node *temp = C;
			if (temp == NULL)
				return;

			Search_Roll_No(roll, temp->Left_Node);
			if (temp->Roll_no == roll)
			{
				cout << endl << "Rquired Student is : " << " Name = " << temp->Name << ".... CGPA = " << temp->CGPA << ".... ROLL NO. = " << temp->Roll_no << ".... Department = " << temp->Department << endl;
				return;
			}
			Search_Roll_No(roll, temp->Right_Node);
		}
	}

	void Tree_Mirror(Node* C)                                             //Making Mirror of BST
	{
		if (Head == NULL)
		{
			cout << endl << "Tree is Empty !" << endl;
			return;
		}
		else
		{
			Node *temp = NULL, *temp1 = C;
			if (C == NULL)
				return;

			Tree_Mirror(temp1->Left_Node);
			Tree_Mirror(temp1->Right_Node);

			temp = temp1->Left_Node;
			temp1->Left_Node = temp1->Right_Node;
			temp1->Right_Node = temp;
		}
	}

};

int main()                                                                // Main Code with Menu Driven Approach
{
	Management BST;
	int choice = 0, Roll = 0, i = 1;
	float CGPA = 0.0;
	string name = "0", department = "0";

	while (i == 1)
	{
		system("cls");
		cout << "================Student Managment with BST=================" << endl;
		cout << endl << "  Press 1 to Enter a Student                          !" << endl << endl;
		cout << "  Press 2 to Traverse in Tree by In-Order Traversal   !" << endl;
		cout << "  Press 3 to Traverse in Tree by Pre-Order Traversal  !" << endl;
		cout << "  Press 4 to Traverse in Tree by Post-Order Traversal !" << endl << endl;
		cout << "  Press 5 to Check Student with Maximum CGPA          !" << endl;
		cout << "  Press 6 to Check Student with Minimum CGPA          !" << endl << endl;
		cout << "  Press 7 to Check Height of Tree from Root Node      !" << endl;
		cout << "  Press 8 to Check Edges of Tree from Root Node       !" << endl << endl;
		cout << "  Press 9 to Search a Student with Roll Number        !" << endl << endl;
		cout << "  Press 10 to Convert Tree into its Mirror Tree       !" << endl << endl;
		cout << "  Press 0 to Exit from System                         !" << endl;
		cout << "===========================================================" << endl;
		cout << endl << "  Enter Choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << endl << "Enter the Name of Student : ";
			cin >> name;
			cout << "Enter the Roll Number of Student : ";                                               //Insertion
			cin >> Roll;
			cout << "Enter the CGPA of Student : ";
			cin >> CGPA;
			cout << "Enter the Department of Student : ";
			cin >> department;

			BST.insertion(name, Roll, CGPA, department);
			cout << endl;
			system("pause");
			break;
		}
		case 2:
		{
			cout << endl;
			BST.In_Order(BST.current);                                                                  //InOrder
			cout << endl;
			system("pause");
			break;
		}
		case 3:
		{
			cout << endl;
			BST.Pre_Order(BST.current);                                                                //PreOrder
			cout << endl;
			system("pause");
			break;
		}
		case 4:
		{
			cout << endl;
			BST.Post_Order(BST.current);                                                             //PostOrder
			cout << endl;
			system("pause");
			break;
		}
		case 5:
		{
			cout << endl;
			BST.Max_CGPA();                                                                          //Max Cgpa
			cout << endl;
			system("pause");
			break;
		}
		case 6:
		{
			cout << endl;
			BST.Min_CGPA();                                                                          //Min Cgpa
			cout << endl;
			system("pause");
			break;
		}
		case 7:
		{
			cout << endl;
			cout << " Height of Tree is : " << BST.Height_Tree(BST.current);                        //Max Height
			cout << endl;
			system("pause");
			break;
		}
		case 8:
		{
			cout << endl;
			BST.Edges_From_Root();                                                                  //Max Roots from root to leave
			cout << endl;
			system("pause");
			break;
		}
		case 9:
		{
			int RN = 0;
			cout << endl << "Enter Roll Number to Find Student : ";                                 //Finding using Roll No.
			cin >> RN;
			BST.Search_Roll_No(RN, BST.current);
			cout << endl;
			system("pause");
			break;
		}
		case 10:                                                                                  // Mirror Of Tree
		{
			BST.Tree_Mirror(BST.current);
			cout << endl;
			system("pause");
			break;
		}
		case 0:
		{
			i = 0;
			cout << "You Have Exited, Thank You !" << endl << endl;                                   // Exited
			system("pause");
			break;
		}
		default:
			cout << "Invalid Entry !!" << endl;
			system("pause");
			break;
		}
	}

	cout << endl << endl;
	system("pause");
}