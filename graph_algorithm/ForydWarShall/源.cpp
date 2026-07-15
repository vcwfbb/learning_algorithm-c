#include<iostream>
#include<vector>
using namespace std;
#define wType int
#define inf 1000000001
#define maxn 100
void init(vector<vector<wType>>& edges, int n) {
	edges.assign(n, vector<wType>(n,inf));
	for (int i = 0; i < n; ++i) edges[i][i] = 0;

}
void addedge(vector<vector<wType>>& edges, int u, int v, wType w) {
	edges[u][v] = min(edges[u][v], w);
}
void ForydWarShall(vector<vector<wType>>& edges, int n) {
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (edges[i][k] == inf || edges[k][j] == inf) continue;
				if (edges[i][k] + edges[k][j] < edges[i][j]) {
					edges[i][j] = edges[i][k] + edges[k][j];
				}
			}
		}
	}
}
int main() {
	return 0;
}