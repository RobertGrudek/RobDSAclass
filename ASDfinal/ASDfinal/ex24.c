#include "ex24.h"
#define MAXDIST 10000
void dijkstra(int G[MAXV][MAXV], int n, int startnode, int endnode)
{
	int cost[MAXV][MAXV], distance[MAXV], pred[MAXV], visited[MAXV];
	int count, mindistance, nextnode, i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (G[i][j] == 0) { cost[i][j] = MAXDIST; }
			else { cost[i][j] = G[i][j]; }
		}
	}
	for (i = 0; i < n; i++)
	{
		distance[i] = cost[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
	}
	distance[startnode] = 0;
	visited[startnode] = 1;
	count = 1;
	while (count < n - 1)
	{
		mindistance = MAXDIST;
		for (i = 0; i < n; i++)
		{
			if (distance[i] < mindistance && !visited[i])
			{
				mindistance = distance[i];
				nextnode = i;
			}
		}
		visited[nextnode] = 1;
		for (i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				if (mindistance + cost[nextnode][i] < distance[i])
				{
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
			}
		}
		count++;
	}

	printf("\nOdleglosc do wierzcholka [%d] z wierzcholka [%d] wynosi: %d", 
		startnode, endnode, distance[endnode]);
	printf("\nSciezka = %d", endnode);
	i = endnode;
	do
	{
		i = pred[i];
		printf("<-%d", i);
	} while (i != startnode);
	printf("\n");
}