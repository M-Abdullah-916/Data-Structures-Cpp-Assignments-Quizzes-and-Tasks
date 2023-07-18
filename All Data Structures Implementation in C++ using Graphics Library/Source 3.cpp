#include <iostream>
#include "SFML/Graphics.hpp";                                                         // Including SFML

using namespace std;
using namespace sf;

RenderWindow window(VideoMode(1024, 768), " QUEUES");                               // Making Window
Font font;

int x_axis = 100;
int y_axis = 200;                                                                   // axis for later use


struct Node                                                                      //Link List based Implementation of Stack
{
	int value;
	Node *Next_Node = NULL;
};


class Stack                                                                      // Creating Class
{
public:
	Stack()
	{
		font.loadFromFile("comic.TTF");
		Head = NULL;
	}
	Node *Head;

	void push(int Value);                                                            //push function 
	int pop();                                                                       //pop function 

	void Delete_Node_Random();
	void Search_Node_Data(int val);

	void Display();                                             // This is just to confirm output
	void Display_Graphics();

};

void Stack::push(int Value)                                                                  //Push Function
{
	if (Head == NULL)
	{
		Node *temp = new Node;
		temp->value = Value;
		temp->Next_Node = NULL;
		Head = temp;
	}
	else
	{
		Node *temp = new Node;
		temp->value = Value;
		temp->Next_Node = Head;
		Head = temp;
	}
}

int Stack::pop()                                                                             //Pop Function
{
	if (Head != NULL)
	{
		Node *temp = new Node;
		int tem;
		temp = Head;
		Head = Head->Next_Node;
		cout << endl << temp->value << " is Poped !" << endl;
		tem = temp->value;
		free(temp);
		return tem;
	}
	else
		cout << endl << "Stack is Empty !!";
}

void Stack::Display()                                                            //Displaying for Checking
{
	Node *temp = Head;
	if (temp != NULL)
	{
		cout << "Values = ";
		while (temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->Next_Node;
		}
	}
	else
		cout << endl << "Stack is Empty !!" << endl;
}

void Stack::Delete_Node_Random()                                                                  // To delete Node Randomely
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
			current = current->Next_Node;
		}
		if (opt == 1)
		{
			temp = new Node;
			temp = Head;
			Head = Head->Next_Node;
			free(temp);
			cout << endl << opt << " Node has been deleted !" << endl;
		}
		else if (opt == counter)
		{
			current = Head;
			while (current->Next_Node->Next_Node != NULL)
			{
				current = current->Next_Node;
			}
			temp = new Node;
			temp = current->Next_Node->Next_Node;
			current->Next_Node = NULL;
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
					temp = current->Next_Node;
					current->Next_Node = temp->Next_Node;
					free(temp);
					cout << endl << opt << " Node has been deleted !" << endl;
					break;
				}
				current = current->Next_Node;
			}
		}
	}
}


void Stack::Search_Node_Data(int val)                                                          // To Search a Node
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
		Text queue;                                                                      // Using to show Stack with LINKED LIST
		CircleShape triangle(6, 3);                                                       //Using to make Arrows
		RectangleShape FL;                                                                //FL = Found Line (FOR searched value)

		queue.setFont(font);
		queue.setCharacterSize(50);
		queue.setPosition(250, 50);
		queue.setString("! Stack Implementation !");
		queue.setFillColor(Color::Cyan);
		queue.setOutlineColor(Color::White);
		queue.setOutlineThickness(2);

		Node *temp = Head;

		window.clear();
		int i = 0;
		while (temp != NULL)
		{
			text.setFont(font);
			text.setCharacterSize(25);
			text.setPosition(x_axis + 380, y_axis + 35);
			text.setFillColor(Color::Black);
			text.setOutlineColor(Color::Black);
			text.setOutlineThickness(1);
			text.setString(to_string(temp->value));

			rectangle.setSize(Vector2f(80, 40));
			rectangle.setPosition(x_axis + 350, y_axis + 30);
			rectangle.setFillColor(Color::Magenta);
			rectangle.setOutlineColor(Color::White);
			rectangle.setOutlineThickness(2);

			line.setSize(Vector2f(55, 2));
			line.setFillColor(Color::White);
			line.setPosition(x_axis + 387, y_axis - 27);
			line.setRotation(90.f);

			triangle.setPosition(x_axis + 380, y_axis - 27);
			triangle.setFillColor(Color::White);

			found.setFont(font);
			found.setCharacterSize(25);
			found.setFillColor(Color::White);                                           // setting found for searched values
			found.setOutlineColor(Color::White);
			found.setOutlineThickness(1);
			found.setString("Value Found");
			found.setPosition(x_axis + 150, y_axis + 35);

			FL.setSize(Vector2f(50, 2));                                                // for searched line
			FL.setFillColor(Color::White);
			FL.setPosition(x_axis + 298, y_axis + 50);

			if (temp->value % 2 == 0)
			{
				rectangle.setFillColor(Color::Blue);
			}
			else                                                                         // even odd difference
				rectangle.setFillColor(Color::Red);

			if (temp->value == val)
			{
				window.draw(FL);                                                         // showing data if found
				window.draw(found);
				i = 1;
			}

			window.draw(queue);
			window.draw(rectangle);
			window.draw(text);                                                          // drawing the required graphics
			window.draw(line);
			window.draw(triangle);

			temp = temp->Next_Node;
			y_axis = y_axis + 100;
		}

		y_axis = 100;                                                                    // setting default value of x
		window.display();
		system("pause");

	}
}


void Stack::Display_Graphics()                                                            // Displaying in SFML
{
	RectangleShape rectangle;
	Text text;
	RectangleShape line;
	Text queue;
	CircleShape triangle(6, 3);

	queue.setFont(font);
	queue.setCharacterSize(50);
	queue.setPosition(250, 50);
	queue.setString("! Stack Implementation !");
	queue.setFillColor(Color::Cyan);
	queue.setOutlineColor(Color::White);
	queue.setOutlineThickness(2);

	Node *temp = Head;

	window.clear();

	while (temp != NULL)
	{
		text.setFont(font);
		text.setCharacterSize(25);
		text.setPosition(x_axis + 380, y_axis + 35);
		text.setFillColor(Color::Black);
		text.setOutlineColor(Color::Black);
		text.setOutlineThickness(1);
		text.setString(to_string(temp->value));

		rectangle.setSize(Vector2f(80, 40));
		rectangle.setPosition(x_axis + 350, y_axis + 30);
		rectangle.setFillColor(Color::Magenta);
		rectangle.setOutlineColor(Color::White);
		rectangle.setOutlineThickness(2);

		line.setSize(Vector2f(55, 2));
		line.setFillColor(Color::White);
		line.setPosition(x_axis + 387, y_axis - 27);
		line.setRotation(90.f);

		triangle.setPosition(x_axis + 380, y_axis - 27);
		triangle.setFillColor(Color::White);

		if (temp->value % 2 == 0)
		{
			rectangle.setFillColor(Color::Blue);
		}
		else
			rectangle.setFillColor(Color::Red);

		window.draw(queue);
		window.draw(rectangle);
		window.draw(text);
		window.draw(line);
		window.draw(triangle);

		temp = temp->Next_Node;
		y_axis = y_axis + 100;
	}

	y_axis = 100;
	window.display();
	system("pause");
}


int main()
{
	int Opt = 0, Choice = 0, Value = 0;

	Stack Object;

	while (Choice != -1)
	{
		system("cls");
		cout << "-----------------------------------------" << endl;
		cout << "| Press 1 to Push Value in Stack        |" << endl;
		cout << "| Press 2 to Pop Value from Stack       |" << endl << "|\t\t\t\t\t|" << endl;
		cout << "| Press 3 to Delete Value from Stack    |" << endl << "|\t\t\t\t\t|" << endl;
		cout << "| Press 4 to Search Values in Stack     |" << endl << "|\t\t\t\t\t|\t\t\tStack Implementation" << endl;
		cout << "| Press 5 to Display Stack              |" << endl;
		cout << "| Press 6 to Display Stack Graphically  |" << endl << "|\t\t\t\t\t|" << endl;
		cout << "| Press 0 to Exit from the Program      |" << endl;
		cout << "-----------------------------------------" << endl;
		cout << endl << "Enter Choice : ";
		cin >> Opt;

		switch (Opt)
		{
		case 1:
		{
			cout << endl << "Enter Value in Stack : ";
			cin >> Value;
			Object.push(Value);
			cout << endl;
			system("pause");
			break;

		}
		case 2:
		{
			Object.pop();
			cout << endl;
			system("pause");
			break;
		}
		case 3:
		{
			cout << endl;
			Object.Delete_Node_Random();
			system("pause");
			break;
		}
		case 4:
		{
			cout << endl << "Enter Value to Search : ";
			cin >> Value;
			Object.Search_Node_Data(Value);
			system("pause");
			break;
		}
		case 5:
		{
			cout << endl;
			Object.Display();
			system("pause");
			break;
		}
		case 6:
		{
			Object.Display_Graphics();
			cout << endl;
			system("pause");
			break;
		}
		case 0:
		{
			Choice = -1;
			break;
		}
		default:
			cout << endl << "Invalid Entry " << endl;
			system("pause");
		}
	}

	cout << endl << endl;
	system("pause");
}


