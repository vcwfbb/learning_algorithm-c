#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define inf 1000000001
#define wType int
struct edge {
	int v;
	wType w;
};
void addedge(vector<vector<edge>>& adj, int u, int v, wType w) {
	adj[u].push_back({ v,w });
}
bool SPFA(vector<vector<edge>>& adj, int start, int n,vector<wType>& dist) {
	
	vector<bool> inQueue(n, false);
	vector<int> cntVisit(n, 0);
	dist.assign(n, inf);
	dist[start] = 0;
	queue<int> q;

	q.push(start);
	inQueue[start] = true;
	cntVisit[start]++;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inQueue[u] = false;
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].v;
			wType w = adj[u][i].w;
			if (dist[u] != inf && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				if (!inQueue[v]) {
					q.push(v);
					cntVisit[v]++;
					if (cntVisit[v] >= n) return false;
				}
			}
		}
	}
	return true;
}
int main() {
	return 0;
}