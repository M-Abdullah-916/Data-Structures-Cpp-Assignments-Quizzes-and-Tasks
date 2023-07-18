#include<iostream>
using namespace std;

struct Edge                                                             // Structure for creating Edge
{
	int Source;
	int Destination;
	int Weight;
};

struct Graph                                                           // Strucure for creating Graph
{
	int Vertex;
	int Edge;
	struct Edge* edge;
};

Graph* Create_Graph(int V, int E);                                           // Creating Graph

void Bellman_Ford(Graph* graph, int Source);                                 // Implementing Bellman Fords Algo

void Print(int Distance[], int Vertex);                                      // Printing the result

int main()                                                                    // Main Code
{
	int Vertex = 5;
	int Edge = 7;

	cout << endl << "  ! BELLMEN FORD'S ALGORITHM !" << endl << endl;

	Graph* graph = Create_Graph(Vertex, Edge);                               // Creating Graph according to Vertex and Edges

	graph->edge[0].Source = 0;
	graph->edge[0].Destination = 1;
	graph->edge[0].Weight = -1;

	graph->edge[1].Source = 0;
	graph->edge[1].Destination = 2;
	graph->edge[1].Weight = 3;

	graph->edge[2].Source = 1;
	graph->edge[2].Destination = 4;
	graph->edge[2].Weight = 6;

	graph->edge[3].Source = 2;
	graph->edge[3].Destination = 3;
	graph->edge[3].Weight = 4;

	graph->edge[4].Source = 2;
	graph->edge[4].Destination = 4;
	graph->edge[4].Weight = 2;

	graph->edge[5].Source = 3;
	graph->edge[5].Destination = 1;
	graph->edge[5].Weight = 5;

	graph->edge[6].Source = 3;
	graph->edge[6].Destination = 4;
	graph->edge[6].Weight = 1;

	Bellman_Ford(graph, 0);

	cout << endl << endl;
	system("pause");
}

Graph* Create_Graph(int V, int E)                                                           // Creating Graph
{
	struct Graph* graph = new Graph;
	graph->Vertex = V;
	graph->Edge = E;
	graph->edge = new Edge[E];
	return graph;
}

void Bellman_Ford(Graph* graph, int Source)                                                 // Implementing Bellman Fords Algo
{
	int V = graph->Vertex;
	int E = graph->Edge;
	int *distance = new int[V];

	for (int i = 0; i < V; i++)
	{
		distance[i] = INT_MAX;
	}

	distance[Source] = 0;

	for (int i = 1; i <= V - 1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int u = graph->edge[j].Source;
			int v = graph->edge[j].Destination;

			int Weight = graph->edge[j].Weight;

			if (distance[u] != INT_MAX && distance[u] + Weight < distance[v])
			{
				distance[v] = distance[u] + Weight;
			}
		}
	}

	for (int i = 0; i < E; i++)
	{
		int u = graph->edge[i].Source;
		int v = graph->edge[i].Destination;

		int Weight = graph->edge[i].Weight;

		if (distance[u] != INT_MAX && distance[u] + Weight < distance[v])
		{
			cout << endl << ("Graph contains negative Weight cycle") << endl;
			return;
		}
	}

	Print(distance, V);
}

void Print(int Distance[], int Vertex)                                                      // Printing the result
{
	char abc[5] = { 'a','b','c','d','e' };
	cout << ("  Vertex    Distance from Source") << endl;

	for (int i = 0; i < Vertex; i++)
	{
		cout << "  " << abc[i] << "\t->\t" << Distance[i] << endl;
	}

}
