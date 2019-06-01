#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int iterations = 0;

int minDistance(int dist[], bool sptSet[], int n)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
	    if (sptSet[v] == false && dist[v] <= min)
		    min = dist[v], min_index = v;

    return min_index;
}

int printSolution(int dist[], int n)
{
    cout<<"Distance from Source\n";
    for (int i = 0; i < n; i++)
    	cout<<"Destination: "<<i+1<<" Distance: "<<dist[i]<<"\n";
}

void dijkstra(int **graph, int src, int n)
{
	int dist[n];
	bool sptSet[n];

	for (int i = 0; i < n; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;

	for (int count = 0; count < n-1; count++)
	{
		int u = minDistance(dist, sptSet, n);
		sptSet[u] = true;

		for (int v = 0; v < n; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
			{
				iterations++;
				dist[v] = dist[u] + graph[u][v];
			}
	}
	printSolution(dist, n);
}

int main()
{
	int size, **graph, source;

	cout<<"Enter number of nodes: ";
	cin>>size;

	graph = new int*[size];
	for(int k = 0; k < size; k++)
    {
        *(graph+k) = new int[size];
	}

	for(int i=0; i<size; i++)
		for(int j = 0; j<size; j++)
		{
			cout<<"Enter distance from "<<i+1<<" to "<<j+1 << ": ";
			cin >> graph[i][j];
		}
	cout<<"Enter source: ";
	cin>>source;
	dijkstra(graph, source-1, size);

	cout << "Expected number of iterations: " << size*size*log2(size) << endl;
    cout << "Actual number of iterations: " << iterations << endl;

	return 0;
}

