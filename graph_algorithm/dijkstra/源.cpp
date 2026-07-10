#include<iostream>
#include<cstring>
using namespace std;
#define maxn 100
#define inf 100000000
bool visited[maxn];
int dist[maxn];

void init(int graph[][maxn], int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			graph[i][j] = (i == j ? 0 : inf);
		}
	}
}
void addedge(int graph[][maxn], int u,int v,int w) {
	graph[u][v] = min(graph[u][v], w);
}
void dijkstra(int graph[][maxn], int n, int start) {
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; ++i) {
		dist[i] = graph[start][i];
	}
	dist[start] = 0;
	visited[start] = true;

	for (int i = 0; i < n - 1; ++i) {
		int min_index = -1;

		for (int j = 0; j < n; ++j) {
			if (visited[j]) continue;

			if (min_index == -1 || dist[j] < dist[min_index]) min_index = j;
		}

		if (min_index == -1 || dist[min_index] == inf) return;
		visited[min_index] = true;

		for (int j = 0; j < n; ++j) {
			if (visited[j]) continue;
			dist[j] = min(dist[j], dist[min_index] + graph[min_index][j]);
		}

	}
}
int main() {
	return 0;
}