#include<iostream>
using namespace std;

int const V = 5;                                                           //As total Vertices are 5 hence initillized here

void Dijkstra(int Graph[V][V], int Source);                                 // Working Algorithm of Dijkstra

int Minimun_Distance(int Distance[], int Set[]);                            // Funtion to get Minimum Distance

void Print(int Distance[]);                                                 // To Print Algorithm

int main()                                                                  // Main Code
{
	cout << endl << "    ! DIJKSTRA'S ALGORITHM !" << endl;

	int graph[V][V] =                                                     // Hardcode (according to given in question)
	{
		{ 0, 1, 3, 0, 0 },
		{ 0, 0, 0, 0, 6 },
		{ 0, 0, 0, 4, 2 },
		{ 0, 5, 0, 0, 1 },
		{ 0, 0, 0, 0, 0}
	};

	Dijkstra(graph, 0);                                                  // Calling Function

	cout << endl << endl;
	system("pause");
}

void Dijkstra(int Graph[V][V], int Source)                                          // Working Algorithm of Dijkstra
{
	int Distance[V];
	int Set[V];

	for (int i = 0; i < V; i++)
	{
		Distance[i] = INT_MAX, Set[i] = 0;
	}

	Distance[Source] = 0;

	for (int i = 0; i < V - 1; i++)
	{

		int temp = Minimun_Distance(Distance, Set);

		Set[temp] = 1;

		for (int i = 0; i < V; i++)

			if (Set[i] == 0 && Graph[temp][i] && Distance[temp] != INT_MAX && Distance[temp] + Graph[temp][i] < Distance[i])
			{
				Distance[i] = Distance[temp] + Graph[temp][i];
			}
	}

	Print(Distance);
}

int Minimun_Distance(int Distance[], int Set[])                            // Funtion to get Minimum Distance
{
	int Min = INT_MAX, Minimum_Value;

	for (int i = 0; i < V; i++)
	{
		if (Set[i] == 0 && Distance[i] <= Min)
		{
			Min = Distance[i];                                                   // Exchanging Values
			Minimum_Value = i;
		}
	}

	return Minimum_Value;                                                       // Returning Minimum Value
}

void Print(int Distance[])                                                     // To Print Algorithm
{
	char abc[5] = { 'a','b','c','d','e' };
	cout << endl << ("  Vertex \t Distance from Vertex(Source) ") << endl;
	for (int i = 0; i < V; i++)
	{
		cout << "  " << abc[i] << "\t->\t " << Distance[i] << endl;                 //Indentation
	}
}

