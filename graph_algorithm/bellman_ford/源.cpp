#include<iostream>
#include<vector>
using namespace std;
#define wType int
#define inf 1000000001
struct edge {
	int u, v;
	wType w;
};
void addedge(vector<edge>& edges, int u, int v, wType w) {
	edges.push_back({ u,v,w });
}
bool bellman_ford(vector<edge>& edges,int start,int n,vector<wType>& dist) {
	for (int i = 0; i < n ; ++i) {
		dist[i] = inf;
	}
	dist[start] = 0;

	for (int j = 0; j < n - 1; ++j) {
		bool isRelax = false;
		for (int i = 0; i < edges.size(); ++i) {
			int u = edges[i].u;
			int v = edges[i].v;
			wType w = edges[i].w;
			if (dist[u] != inf && dist[u] + w < dist[v]) {
				isRelax = true;
				dist[v] = dist[u] + w;
			}
		}
		if (!isRelax) break;
	}

	for (int i = 0; i < edges.size(); ++i) {
		int u = edges[i].u;
		int v = edges[i].v;
		wType w = edges[i].w;
		if (dist[u] != inf && dist[u] + w < dist[v]) {
			return false;   // return false代表存在负环
		}
	}

	return true;
}

int main() {
	return 0;
}