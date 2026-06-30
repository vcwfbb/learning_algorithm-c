#include<iostream>
#include<cstring>
using namespace std;
#define eletype int
#define ll long long
const int maxn = 5001;
const eletype inf = 100000001;
eletype graph[maxn][maxn];
eletype dist[maxn];
bool visit[maxn];
void init(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			graph[i][j] = (i == j ? 0 : inf);
		}
	}
}
void addedge(int u, int v, eletype w) {
	graph[u][v] = min(graph[u][v], w);
	graph[v][u] = min(graph[v][u], w);
}
eletype prim(int n) {
	memset(visit, false, sizeof(bool) * maxn);
	eletype ret = 0;
	for (int i = 0; i < n; ++i) {
		dist[i] = graph[0][i];
	}
	visit[0] = true;

	for (int i = 1; i < n; ++i) {
		int min_index = -1;
		for (int j = 0; j < n; ++j) {
			if (visit[j]) continue;
			if (min_index == -1 || dist[j] < dist[min_index]) {
				min_index = j;
			}
		}

		if (min_index == -1 || dist[min_index] == inf) {
			return -1;
		}

		ret += dist[min_index];
		visit[min_index] = true;

		for (int j = 0; j < n; ++j) {
			if (visit[j]) continue;
			dist[j] = min(dist[j], graph[min_index][j]);
		}

	}

	return ret;
}
int main() {
	return 0;
}