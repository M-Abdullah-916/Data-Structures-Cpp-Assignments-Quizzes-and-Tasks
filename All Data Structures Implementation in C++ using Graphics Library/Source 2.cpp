#include <iostream>
#include "SFML/Graphics.hpp";                                                         // Including SFML

using namespace std;
using namespace sf;

RenderWindow window(VideoMode(1024, 768), " QUEUES");                               // Making Window
Font font;

int x_axis = 100;
int y_axis = 200;                                                                   // axis for later use

struct Node
{
	int Value;
	Node *NextNode;                                                                 // Initillizing Elements
};


class Queue
{
public:
	Node *front, *rear;
	Queue()
	{
		font.loadFromFile("comic.TTF");
		front = NULL, rear = NULL;
	}

	void enqueue(int value);                                                             //ENQUEUE FUNCTION
	void dequeue();                                                                     //DEQUEUE FUNCTION

	void Search_Node_Data(int val);

	void display();                                                                   // Display Function for ease
	void Display_Graphics();                                                          // Display with graphics
};

void Queue::enqueue(int value)
{
	Node *temp = new Node;                                                            // Enqueue Function
	if (front == NULL && rear == NULL)
	{
		temp->Value = value;
		temp->NextNode = NULL;
		front = temp;
		rear = temp;
	}
	else
	{
		temp->Value = value;
		temp->NextNode = NULL;
		rear->NextNode = temp;
		rear = temp;
	}
}

void Queue::dequeue()                                                                   // Dequeue Function
{
	Node *temp = new Node;
	if (front != -NULL && front != rear)
	{
		cout << endl << "Following Value is Dequeued : " << front->Value;
		temp = front;
		front = front->NextNode;
		free(temp);
	}
	else if (front == NULL && rear == NULL)
	{
		cout << "Queue is Empty" << endl;
	}
	else if (front == rear)
	{
		cout << endl << "Following Value is Dequeued : " << front->Value;
		temp = front;
		free(temp);
		front = NULL;
		rear = NULL;
	}

}

void Queue::display()                                                                   // Displaying Queue
{
	Node *temp = front;
	if (temp == NULL)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		while (temp != NULL)
		{
			cout << temp->Value << " ";
			temp = temp->NextNode;
		}
	}
}

void Queue::Search_Node_Data(int val)                                                          // To Search a Node
{
	if (front == NULL)
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
		singly.setPosition(250, 50);
		singly.setString("! QUEUES Implementation !");                                        // Setting singly
		singly.setFillColor(Color::Cyan);
		singly.setOutlineColor(Color::White);
		singly.setOutlineThickness(2);

		Node *temp = front;

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
			text.setString(to_string(temp->Value));

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

			if (temp->Value % 2 == 0)
			{
				rectangle.setFillColor(Color::Blue);
			}
			else                                                                         // even odd difference
				rectangle.setFillColor(Color::Red);

			if (temp->Value == val)
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


void Queue::Display_Graphics()                                                            // Displaying in SFML
{
	RectangleShape rectangle;
	Text text;
	RectangleShape line;
	Text queue;
	CircleShape triangle(6, 3);
	Text Prime;
	RectangleShape PL;

	queue.setFont(font);
	queue.setCharacterSize(50);
	queue.setPosition(250, 50);
	queue.setString("! Queue Implementation !");
	queue.setFillColor(Color::Cyan);
	queue.setOutlineColor(Color::White);
	queue.setOutlineThickness(2);

	Node *temp = front;

	window.clear();

	while (temp != NULL)
	{
		text.setFont(font);
		text.setCharacterSize(25);
		text.setPosition(x_axis + 25, y_axis + 4);
		text.setFillColor(Color::Black);
		text.setOutlineColor(Color::Black);
		text.setOutlineThickness(1);
		text.setString(to_string(temp->Value));

		rectangle.setSize(Vector2f(70, 40));
		rectangle.setPosition(x_axis, y_axis);
		rectangle.setFillColor(Color::Magenta);
		rectangle.setOutlineColor(Color::White);
		rectangle.setOutlineThickness(2);

		line.setSize(Vector2f(50, 2));
		line.setFillColor(Color::White);
		line.setPosition(x_axis + 70, y_axis + 18);

		triangle.setPosition(x_axis + 70, y_axis + 24);
		triangle.setFillColor(Color::White);
		triangle.setRotation(270.f);

		Prime.setFont(font);
		Prime.setCharacterSize(25);
		Prime.setFillColor(Color::White);                                           // setting Prime for searched values
		Prime.setOutlineColor(Color::White);
		Prime.setOutlineThickness(1);
		Prime.setString("Prime");
		Prime.setPosition(x_axis , y_axis + 65);

		PL.setSize(Vector2f(50, 2));                                                // for searched line
		PL.setFillColor(Color::White);
		PL.setRotation(90.f);
		PL.setPosition(x_axis + 35, y_axis + 20);

		if (temp->Value % 2 == 0)
		{
			rectangle.setFillColor(Color::Blue);
		}
		else
			rectangle.setFillColor(Color::Red);


		bool isPrime = true;
		if (temp->Value == 0 || temp->Value == 1)
		{
			isPrime = false;
		}
		else 
		{
			for (int i = 2; i <= temp->Value / 2; ++i) 
			{
				if (temp->Value % i == 0)
				{
					isPrime = false;
					break;
				}
			}
		}
		if (isPrime)
		{
			window.draw(Prime);
			window.draw(PL);
		}

		window.draw(queue);
		window.draw(rectangle);
		window.draw(text);
		window.draw(line);
		window.draw(triangle);

		temp = temp->NextNode;
		x_axis = x_axis + 100;
	}
	text.setFont(font);
	text.setCharacterSize(25);
	text.setPosition(x_axis + 5, y_axis + 4);
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
	Queue queue;
	int value;

	int choice = 1;
	int Opt;
	while (choice != 0)
	{
		system("cls");
		cout << "--------------------------------" << endl;
		cout << "| Press 1 To Enqueue           |" << endl;
		cout << "| Press 2 To Dequeue           |" << endl << "|\t\t\t       |" << endl;
		cout << "| Press 3 To Search a Node     |" << endl << "|\t\t\t       |\t\t\tQueues Implementation" << endl;    //Menu Driven Program
		cout << "| Press 4 To Display           |" << endl;
		cout << "| Press 5 To Display Graphics  |" << endl << "|\t\t\t       |" << endl;
		cout << "| Press 0 To Exit              |" << endl;
		cout << "--------------------------------" << endl;
		cout << "Enter Your Option : ";
		cin >> Opt;
		switch (Opt)
		{
		case 1:
		{
			cout << endl << "Enter Value to Enqueue : ";
			cin >> value;
			queue.enqueue(value);
			cout << endl;
			system("pause");
			break;
		}
		case 2:
		{
			cout << endl;
			queue.dequeue();
			cout << endl << endl;
			system("pause");
			break;
		}
		case 3:
		{
			cout << endl << "Enter the Value to Search : ";
			cin >> value;
			queue.Search_Node_Data(value);
			cout << endl;
			system("pause");
			break;
		}
		case 4:
		{
			cout << endl << "Displaying : ";
			queue.display();
			cout << endl << endl;
			system("pause");
			break;
		}
		case 5:
		{
			queue.Display_Graphics();
			cout << endl;
			system("pause");
			break;
		}
		case 0:
		{
			choice = 0;
			break;

		}
		default:
		{
			cout << "Invalid Entry" << endl;
			break;
		}
		}
	}
	cout << endl << endl;
	system("pause");
}
