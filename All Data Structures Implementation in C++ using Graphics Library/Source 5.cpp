#include <iostream>
#include "SFML/Graphics.hpp";                                                            // Including SFML

using namespace std;
using namespace sf;

RenderWindow window(VideoMode(1000, 600), " BST Implementation");                                    // Making Window
Font font;

int x_axis = 250;
int y_axis = 0;                                                                          // axis for later use

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
		font.loadFromFile("comicbd.TTF");
		Root = NULL;
	}
	Node *Root;
	Text text;
	RectangleShape line_right;
	RectangleShape line_left;
	Text BST;
	CircleShape circle;

	Node *Insertion(Node *Current, int data);                                           // Insertion of Nodes

	void Delete_Node(Node *root, int Key);                                            // Deletion of Nodes

	void Bst_Tree::Search_Node_Data(int val);                                         // Searching of Nodes

	void Bst_Tree::Mirror_BST(Node* Curr);
	
	void Bst_Tree::Display_Graphics(Node *temp, int L );                                               // Graphical Representation
};

Node *Bst_Tree::Insertion(Node *Current, int data)
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

void Bst_Tree::Delete_Node(Node *root, int Key)                                              //Deleting Nodes
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


void Bst_Tree::Search_Node_Data(int val)                                                          // To Search a Node
{
	if (Root == NULL)
	{
		cout << endl << "Link List is Empty !" << endl;
	}
	else
	{
		RectangleShape rectangle;                                                         // Making Rectangle
		Text text;                                                                        // Using to show values
		Text found;                                                                       // Using to show searched value
		RectangleShape line;                                                              // Using to make connecting lines
		Text BST;                                                                         // Using to show BST TREE
		CircleShape triangle(6, 3);                                                       //Using to make Arrows
		RectangleShape FL;                                                                //FL = Found Line (FOR searched value)

		BST.setFont(font);
		BST.setCharacterSize(50);
		BST.setPosition(250, 50);
		BST.setString("! BST Implementation !");                                        // Setting BST
		BST.setFillColor(Color::Cyan);
		BST.setOutlineColor(Color::White);
		BST.setOutlineThickness(2);

		Node *temp = Root;

		window.clear();
		int i = 0;
		while (temp != NULL)
		{
			text.setFont(font);
			text.setCharacterSize(25);
			text.setPosition(x_axis + 25, y_axis + 4);                                     // setting text for values
			text.setFillColor(Color::Black);
			text.setOutlineColor(Color::Black);
			text.setOutlineThickness(1);
			text.setString(to_string(temp->Data));

			rectangle.setSize(Vector2f(70, 40));
			rectangle.setPosition(x_axis, y_axis);                                        // setting rectangle attributes
			rectangle.setFillColor(Color::Magenta);
			rectangle.setOutlineColor(Color::White);
			rectangle.setOutlineThickness(2);

			line.setSize(Vector2f(50, 2));
			line.setFillColor(Color::White);
			line.setPosition(x_axis + 70, y_axis + 18);                                  // setting lines for connection

			triangle.setPosition(x_axis + 70, y_axis + 24);
			triangle.setFillColor(Color::White);
			triangle.setRotation(270.f);

			found.setFont(font);
			found.setCharacterSize(25);
			found.setFillColor(Color::White);                                           // setting found for searched values
			found.setOutlineColor(Color::White);
			found.setOutlineThickness(1);
			found.setString("Value Found");
			found.setPosition(x_axis - 35, y_axis + 75);

			FL.setSize(Vector2f(50, 2));                                                // for searched line
			FL.setFillColor(Color::White);
			FL.setRotation(90.f);
			FL.setPosition(x_axis + 35, y_axis + 20);

			if (temp->Data % 2 == 0)
			{
				rectangle.setFillColor(Color::Blue);
			}
			else                                                                         // even odd difference
				rectangle.setFillColor(Color::Red);

			if (temp->Data == val)
			{
				window.draw(FL);                                                         // showing data if found
				window.draw(found);
				i = 1;
			}

			window.draw(BST);
			window.draw(rectangle);
			window.draw(text);                                                          // drawing the required graphics
			window.draw(line);
			window.draw(triangle);

			//temp = temp->NextNode;
			x_axis = x_axis + 100;
		}
		text.setFont(font);
		text.setCharacterSize(25);
		text.setPosition(x_axis + 5, y_axis + 4);
		text.setFillColor(Color::Black);
		text.setOutlineColor(Color::Black);                                             // setting for NULL text
		text.setOutlineThickness(1);
		text.setString("NULL");

		rectangle.setSize(Vector2f(77, 40));
		rectangle.setPosition(x_axis, y_axis);
		rectangle.setFillColor(Color::Magenta);
		rectangle.setOutlineColor(Color::White);                                        // setting to store NULL Text
		rectangle.setOutlineThickness(2);

		window.draw(rectangle);
		window.draw(text);

		x_axis = 100;                                                                    // setting default value of x
		window.display();
		system("pause");

	}
}


void Bst_Tree::Display_Graphics(Node *temp, int L = 1)                                                            // Displaying in SFML
{

	y_axis = 200;

	BST.setFont(font);
	BST.setCharacterSize(50);
	BST.setPosition(250, 50);
	BST.setString("! BST Implementation !");                                        // Setting BST
	BST.setFillColor(Color::Cyan);
	BST.setOutlineColor(Color::White);
	BST.setOutlineThickness(2);


	if (temp != NULL)
	{
		Display_Graphics(temp->Left_Node, L + 1);

		for (int i = 0; i < L && temp != Root; i++)
		{
			y_axis = y_axis + 50;
		}

		circle.setRadius(20);
		circle.setPosition(Vector2f(x_axis - 5, y_axis - 5));

		text.setFont(font);
		text.setCharacterSize(20);
		text.setFillColor(Color::White);
		text.setOutlineColor(Color::White);
		text.setOutlineThickness(1);
	

		if (temp->Data % 2 == 0)
		{
			circle.setFillColor(Color::Blue);
		}
		else
			circle.setFillColor(Color::Red);


		text.setPosition(Vector2f(x_axis + 8, y_axis + 4));
		text.setString(to_string(temp->Data));

		line_right.setSize(Vector2f(30, 2));
		line_right.setFillColor(Color::White);
		line_right.setPosition(circle.getPosition().x + circle.getRadius() * 2, circle.getPosition().y + circle.getRadius() + 10);
		line_right.setRotation(45.f);

		line_left.setSize(Vector2f(30, 2));
		line_left.setFillColor(Color::White);
		line_left.setPosition(circle.getPosition().x - (circle.getRadius() / 2) + 15, circle.getPosition().y + circle.getRadius() + 10);
		line_left.setRotation(135.f);

		if (temp == Root)
		{
			line_right.setSize(Vector2f(100, 2));
			line_left.setSize(Vector2f(100, 2));
		}

		window.draw(BST);
		window.draw(circle);
		window.draw(text);
		window.draw(line_right);
		window.draw(line_left);

		x_axis = x_axis + 50;

		Display_Graphics(temp->Right_Node, L + 1);
		
	}

}

void Bst_Tree:: Mirror_BST(Node* Curr)
{
	if (Curr == NULL)
		return;

	struct Node* temp;

	Mirror_BST(Curr->Left_Node);
	Mirror_BST(Curr->Right_Node);

	temp = Curr->Left_Node;
	Curr->Left_Node = Curr->Right_Node;
	Curr->Right_Node = temp;

}




int main()                                                                                        // Main Code
{
	Bst_Tree Tree;
	int choice = 0, value = 0, i = 1;

	while (i != 0)
	{
		system("cls");
		cout << "=================================================" << endl;
		cout << " Press 1 to Enter a Node                      !" << endl;
		cout << " Press 2 to Delete Any Node From Tree         !" << endl;
		cout << " Press 3 to Search Any Node From Tree         !" << endl;
		cout << " Press 4 to Make Mirror of the Tree           !" << endl;
		cout << " Press 5 to Display Tree Graphically          !" << endl;
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
		case 3:
		{
			cout << endl << "Enter Value to Search Respective Node :";
			cin >> value;
			Tree.Delete_Node(Tree.Root, value);
			system("pause");
			break;
		}
		case 4:
		{
			cout << endl;
			Tree.Mirror_BST(Tree.Root);
			cout << "Tree has been Mirrored !" << endl;
			system("pause");
			break;
		}
		case 5:
		{
			window.clear();
			cout << endl;
			Tree.Display_Graphics(Tree.Root);
			window.display();
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

