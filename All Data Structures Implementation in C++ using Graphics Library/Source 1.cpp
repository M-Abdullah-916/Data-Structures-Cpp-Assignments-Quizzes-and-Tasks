#include <iostream>
#include "SFML/Graphics.hpp";                                                         // Including SFML

using namespace std;
using namespace sf;

RenderWindow window(VideoMode(1024, 768), " Singly Linked List");                    // Making Window
Font font;

int x_axis = 100;
int y_axis = 200;                                                                   // axis for later use

struct Node
{
	int data;                                                                      // Link List Structure
	Node *NextNode;
};

class Fun                                                                         // class code
{
public:
	Fun()
	{
		font.loadFromFile("comic.TTF");                                            // Load Font File
		Head = NULL;
	}

	Node *Head;

	void Add_Node_First(int val);
	void Add_Node_Last(int val);
	void Add_Node_Random(int val);

	void Delete_Node_First();
	void Delete_Node_Last();
	void Delete_Node_Random();

	void Search_Node_Data(int val);

	void Display();
	void Display_Graphics();
};

void Fun::Add_Node_First(int val)                                                              // To Add Node at first
{
	Node *temp = NULL, *current = Head;

	if (Head == NULL)
	{
		temp = new Node;
		temp->data = val;
		temp->NextNode = NULL;
		Head = temp;
	}
	else
	{
		temp = new Node;
		temp->data = val;
		temp->NextNode = current;
		Head = temp;
	}

}

void Fun::Add_Node_Last(int val)                                                           // To Add Node At Last
{
	Node  *temp = NULL, *current = Head;

	if (Head != NULL)
	{
		while (current->NextNode != NULL)
		{
			current = current->NextNode;
		}
		temp = new Node;
		temp->data = val;
		current->NextNode = temp;
		temp->NextNode = NULL;
	}
	else
		cout << endl << "!!! Create Link List First !!!" << endl;


}

void Fun::Add_Node_Random(int val)                                                           // To Add Node Randomly
{
	Node *temp = NULL, *current = Head;
	int opt = 0, counter = 0;
	cout << endl << "Enter Postion to add a Node : ";
	cin >> opt;

	if (Head == NULL)
	{
		cout << endl << "Create List First !!" << endl;
	}
	else
	{
		Node *temp1 = Head;
		while (temp1 != NULL)
		{
			counter++;
			temp1 = temp1->NextNode;
		}

		if (opt == 1)
		{
			if (Head == NULL)
			{
				temp = new Node;
				temp->data = val;
				temp->NextNode = NULL;
				Head = temp;
			}
			else
			{
				temp = new Node;
				temp->data = val;
				current = Head;
				Head = temp;
				temp->NextNode = current;
			}
		}

		else if (opt == counter)
		{
			while (current->NextNode != NULL)
			{
				current = current->NextNode;
			}
			temp = new Node;
			temp->data = val;
			current->NextNode = temp;
			temp->NextNode = NULL;
		}

		else if (opt > 1 && opt < counter)
		{
			current = Head;
			for (int i = 2; i < counter - 1; i++)
			{
				if (i == opt)
				{
					temp = new Node;
					temp->data = val;
					temp->NextNode = current->NextNode;
					current->NextNode = temp;
					break;
				}
				current = current->NextNode;
			}
		}
	}
}
 
void Fun::Delete_Node_First()                                                                   // To Delete Node from start
{
	Node *temp = NULL;
	if (Head != NULL)
	{
		temp = new Node;
		temp = Head;
		Head = Head->NextNode;
		free(temp);
		cout << endl << "First Node has been deleted !" << endl;
	}
	else
		cout << "Link List is Empty ! " << endl;
}

void Fun::Delete_Node_Last()                                                                    // To Delete Node from End
{
	Node *temp = NULL, *current = Head;
	if (Head != NULL)
	{
		while (current->NextNode->NextNode != NULL)
		{
			current = current->NextNode;
		}
		temp = new Node;
		temp = current->NextNode->NextNode;
		current->NextNode = NULL;
		free(temp);
		cout << endl << "Last Node has been deleted !" << endl;
	}
	else
		cout << "Link List is Empty ! " << endl;
}

void Fun::Delete_Node_Random()                                                                  // To delte Node Randomely
{
	Node *temp = NULL, *current = Head;
	if (Head == NULL)
	{
		cout << endl << "Link List is Empty !" << endl;
	}
	else
	{
		int opt = 0, counter = 0;
		cout << "Enter the Position of Node to Delete it : ";
		cin >> opt;
		while (current != NULL)
		{
			counter++;
			current = current->NextNode;
		}
		if (opt == 1)
		{
			temp = new Node;
			temp = Head;
			Head = Head->NextNode;
			free(temp);
			cout << endl << opt << " Node has been deleted !" << endl;
		}
		else if (opt == counter)
		{
			current = Head;
			while (current->NextNode->NextNode != NULL)
			{
				current = current->NextNode;
			}
			temp = new Node;
			temp = current->NextNode->NextNode;
			current->NextNode = NULL;
			free(temp);
			cout << endl << opt << " Node has been deleted !" << endl;
		}
		else if (opt > 1 && opt < counter)
		{
			current = Head;
			for (int i = 2; i < counter - 1; i++)
			{
				if (i == opt)
				{
					temp = new Node;
					temp = current->NextNode;
					current->NextNode = temp->NextNode;
					free(temp);
					cout << endl << opt << " Node has been deleted !" << endl;
					break;
				}
				current = current->NextNode;
			}
		}
	}
}

void Fun::Search_Node_Data(int val)                                                          // To Search a Node
{
	if (Head == NULL)
	{
		cout << endl << "Link List is Empty !" << endl;
	}
	else
	{
		RectangleShape rectangle;                                                         // Making Rectangle
		Text text;                                                                        // Using to show values
		Text found;                                                                       // Using to show searched value
		RectangleShape line;                                                              // Using to make connecting lines
		Text singly;                                                                      // Using to show SINGLY LINKED LIST
		CircleShape triangle(6, 3);                                                       //Using to make Arrows
		RectangleShape FL;                                                                //FL = Found Line (FOR searched value)

		singly.setFont(font);
		singly.setCharacterSize(50);
		singly.setPosition(300, 50);
		singly.setString("Singly Linked List");                                          // Setting singly
		singly.setFillColor(Color::Cyan);
		singly.setOutlineColor(Color::White);
		singly.setOutlineThickness(2);

		Node *temp = Head;

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
			text.setString(to_string(temp->data));

			rectangle.setSize(Vector2f(70, 40));
			rectangle.setPosition(x_axis, y_axis);                                        // setting rectangle attributes
			rectangle.setFillColor(Color::Magenta);
			rectangle.setOutlineColor(Color::White);
			rectangle.setOutlineThickness(2);

			line.setSize(Vector2f(50, 2));
			line.setFillColor(Color::White);
			line.setPosition(x_axis + 70, y_axis + 18);                                  // setting lines for connection

			triangle.setPosition(x_axis + 100, y_axis + 13);
			triangle.setFillColor(Color::White);                                        // setting arrow position to point out
			triangle.setRotation(90.f);

			found.setFont(font);
			found.setCharacterSize(25);
			found.setFillColor(Color::White);                                           // setting found for searched values
			found.setOutlineColor(Color::White);
			found.setOutlineThickness(1);
			found.setString("Value Found");
			found.setPosition(x_axis - 35 , y_axis + 75);

			FL.setSize(Vector2f(50, 2));                                                // for searched line
			FL.setFillColor(Color::White);
			FL.setRotation(90.f);
			FL.setPosition(x_axis + 35, y_axis + 20);

			if (temp->data % 2 == 0)
			{
				rectangle.setFillColor(Color::Blue);
			}
			else                                                                         // even odd difference
				rectangle.setFillColor(Color::Red);

			if (temp->data == val)
			{
				window.draw(FL);                                                         // showing data if found
				window.draw(found);
				i = 1;
			}
			
			window.draw(singly);
			window.draw(rectangle);
			window.draw(text);                                                          // drawing the required graphics
			window.draw(line);
			window.draw(triangle);

			temp = temp->NextNode;
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

void Fun::Display()
{
	Node *temp = Head;                                                               // Displaying in Console
	cout << endl << "DATA : ";

	while (temp != NULL)
	{
		cout << "  " << temp->data << "  ";
		temp = temp->NextNode;
	}
	cout << endl;

}

void Fun::Display_Graphics()                                                            // Displaying in SFML
{
	RectangleShape rectangle;
	Text text;
	RectangleShape line;
	Text singly;
	CircleShape triangle(6, 3);

	singly.setFont(font);
	singly.setCharacterSize(50);
	singly.setPosition(300, 50);
	singly.setString("Singly Linked List");
	singly.setFillColor(Color::Cyan);
	singly.setOutlineColor(Color::White);
	singly.setOutlineThickness(2);

	Node *temp = Head;

	window.clear();

	while (temp != NULL)
	{
		text.setFont(font);
		text.setCharacterSize(25);
		text.setPosition(x_axis + 25, y_axis + 4);
		text.setFillColor(Color::Black);
		text.setOutlineColor(Color::Black);
		text.setOutlineThickness(1);
		text.setString(to_string(temp->data));

		rectangle.setSize(Vector2f(70, 40));
		rectangle.setPosition(x_axis, y_axis);
		rectangle.setFillColor(Color::Magenta);
		rectangle.setOutlineColor(Color::White);
		rectangle.setOutlineThickness(2);

		line.setSize(Vector2f(50, 2));
		line.setFillColor(Color::White);
		line.setPosition(x_axis + 70, y_axis + 18);

		triangle.setPosition(x_axis + 100, y_axis + 13);
		triangle.setFillColor(Color::White);
		triangle.setRotation(90.f);

		if (temp->data % 2 == 0)
		{
			rectangle.setFillColor(Color::Blue);
		}
		else
			rectangle.setFillColor(Color::Red);

		window.draw(singly);
		window.draw(rectangle);
		window.draw(text);
		window.draw(line);
		window.draw(triangle);
		
		temp = temp->NextNode;
		x_axis = x_axis + 100;
	}
	text.setFont(font);
	text.setCharacterSize(25);
	text.setPosition(x_axis + 5 , y_axis + 4);
	text.setFillColor(Color::Black);
	text.setOutlineColor(Color::Black);
	text.setOutlineThickness(1);
	text.setString("NULL");

	rectangle.setSize(Vector2f(77, 40));
	rectangle.setPosition(x_axis, y_axis);
	rectangle.setFillColor(Color::Magenta);
	rectangle.setOutlineColor(Color::White);
	rectangle.setOutlineThickness(2);

	window.draw(rectangle);
	window.draw(text);

	x_axis = 100;
	window.display();
	system("pause");
}


int main()
{
	Fun List;
	int opt = 1, val = 0;

	while (opt != 0)
	{
		system("cls");
		cout << " -----------------------------------" << endl;
		cout << " | Press 1 to Add Node on Start    |" << endl;
		cout << " | Press 2 to Add Node on Last     |" << endl;
		cout << " | Press 3 to Add Node Randomly    |" << endl << " |\t\t\t\t   |" << endl;
		cout << " | Press 4 to Delete First Node    |" << endl;
		cout << " | Press 5 to Delete Last Node     |" << "\t\t\tSINGLY LINK LIST" << endl;
		cout << " | Press 6 to Delete Random Node   |" << endl << " |\t\t\t\t   |" << endl;
		cout << " | Press 7 to Search Data in Node  |" << endl << " |\t\t\t\t   |" << endl;
		cout << " | Press 9 to Display Link List    |" << endl << " |\t\t\t\t   |" << endl;
		cout << " | Press 10 to Display Graphics    |" << endl << " |\t\t\t\t   |" << endl;
		cout << " | Press 0 to Exit from the system |" << endl;
		cout << " -----------------------------------" << endl;
		cout << endl << "   Option Choosen : ";
		cin >> opt;
		cout << endl;

		switch (opt)
		{
		case 1:
		{
			cout << "Enter any data to Enter in List : ";
			cin >> val;
			List.Add_Node_First(val);
			break;
		}
		case 2:
		{
			cout << "Enter any data to Enter in List : ";
			cin >> val;
			List.Add_Node_Last(val);
			break;
		}
		case 3:
		{
			cout << "Enter any data to Enter in List : ";
			cin >> val;
			List.Add_Node_Random(val);
			break;
		}
		case 4:
		{
			List.Delete_Node_First();
			cout << endl;
			system("pause");
			break;
		}
		case 5:
		{
			List.Delete_Node_Last();
			cout << endl;
			system("pause");
			break;
		}
		case 6:
		{
			List.Delete_Node_Random();
			cout << endl;
			system("pause");

			break;
		}
		case 7:
		{
			cout << "Enter value to search in Link List : ";
			cin >> val;
			List.Search_Node_Data(val);
			cout << endl;
			system("pause");
			break;
		}
		case 9:
		{
			List.Display();
			cout << endl;
			system("pause");
			break;
		}
		{
		case 10:
			List.Display_Graphics();
			cout << endl;
			system("pause");
			break;
		}
		case 0:
		{
			opt = 0;
			cout << endl << "You have exited from Link List !" << endl;
			break;
		}
		default:
			cout << "Invalid Entry, Press any key to try again !!" << endl;
			system("pause");
			break;
		}
	}

	cout << endl << endl;
	system("pause");
}
