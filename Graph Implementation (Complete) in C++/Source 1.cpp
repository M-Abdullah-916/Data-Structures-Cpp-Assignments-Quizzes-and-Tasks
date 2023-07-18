#include <iostream>
using namespace std;

class Graph                                                                    // Class For Graph
{
public:
	int ** Matrix;                                                             //2D Array for Adjecency Matrix
	int Visited;

	Graph(int Visited)                                                         // Constructor for Making Matrix
	{
		this->Visited = Visited;
		Matrix = new int*[Visited];

		for (int i = 1; i <= Visited; i++)
		{
			Matrix[i] = new int[Visited];
			for (int j = 1; j <= Visited; j++)
				Matrix[i][j] = 0;
		}
	}

	void Add_Edge(int i, int j)                                              // Adding Edge
	{
		Matrix[i][j] = 1;
		Matrix[j][i] = 1;
	}

	void Remove_Edge(int i, int j)                                          //Removing Edge (if needed)
	{
		Matrix[i][j] = 0;
		Matrix[j][i] = 0;
	}

	void Adjencency_Matrix()                                               // Displaying Adjececy Matrix
	{
		cout << endl;
		for (int i = 1; i <= Visited; i++)
		{
			for (int j = 1; j <= Visited; j++)
				cout << "  " << Matrix[i][j] << "   ";
			cout << endl << endl;;
		}
	}

};

int main()                                                                          // Main Code
{
	int size = 0, i = 1, opt = 0;
	cout << endl << " Enter Size of the Matrix : ";
	cin >> size;
	Graph Adj_Matrix(size);

	while (i == 1)
	{ 
		system("cls");
		cout << "----------------------------------------------------" << endl;                    //Menu Driven Program
		cout << " Press 1 to Make a Graph with Adjacency Matrix !" << endl;
		cout << " Press 2 to Remoce an Edge From the Graph      !" << endl;
		cout << " Press 3 to Display the Adjecency Matrix       !" << endl;
		cout << " Press 0 to Exit from the System               !" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << endl << "   Enter Choice : ";
		cin >> opt;
		switch (opt)
		{
		case 1:                                                                                  // To Add Edge
		{
			cout << endl;
			int row = 0, col = 0;
			cout << " Enter Number of Row in which you want to add Node     : ";
			cin >> row;
			cout << " Enter Number of Coloumn in which you want to add Node : ";
			cin >> col;
			Adj_Matrix.Add_Edge(row, col);
			system("pause");
			break;
		}
		case 2:                                                                                 // To Delete Edge
		{
			cout << endl;
			int row = 0, col = 0;
			cout << " Enter Number of Row in which you want to Remove Node     : ";
			cin >> row;
			cout << " Enter Number of Coloumn in which you want to Remove Node : ";
			cin >> col;
			Adj_Matrix.Remove_Edge(row, col);
			system("pause");
			break;
		}
		case 3:                                                                               // To Show Matrix
		{
			cout << endl << " Adjeceny Matrix is : " << endl;
			Adj_Matrix.Adjencency_Matrix();
			cout << endl;
			system("pause");
			break;
		} 
		case 0:                                                                                // To Exit from System
		{
			cout << endl << " You have exited from the System !" << endl;
			i = 0;
			system("pause");
			break;
		}
		default:
		{
			cout << endl << " Invalid Option, Try Again !" << endl;
			system("pause");
			break;
		}
		}
	}

	cout << endl << endl;
	system("pause");
}
