#include<iostream>
#include<vector>
using namespace std;
#define inf 1000000000
void init(vector<vector<pair<int,int>>>& adj,int n) {
	adj.assign(n, {});
}
void addEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int w) {
	adj[u].push_back({ v,w });
}
void dijkstra(vector<vector<pair<int, int>>>& adj, int n,int start,vector<int>& dist) {
	vector<bool> visited(n, false);
	for (int i = 0; i < n; ++i) dist[i] = inf;
	for (int i = 0; i < adj[start].size(); ++i) {
		int v = adj[start][i].first;
		int w = adj[start][i].second;
		dist[v] = w;
	}
	dist[start] = 0; visited[start] = true;

	for (int i = 0; i < n - 1; ++i) {

		int min_index = -1;
		for (int j = 0; j < n; ++j) {
			if (visited[j]) continue;
			if (min_index == -1 || dist[j] < dist[min_index]) min_index = j;
		}
		if (min_index == -1 || dist[min_index] == inf) return;

		visited[min_index] = true;

		for (int j = 0; j < adj[min_index].size(); ++j) {
			int v = adj[min_index][j].first;
			int w = adj[min_index][j].second;
			dist[v] = min(dist[v], dist[min_index] + w);
		}
	}
}
int main() {
	return 0;
}