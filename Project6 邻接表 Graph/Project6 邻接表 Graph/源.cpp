#include<iostream>
using namespace std;
class Graph {
private:
	struct edgenode {
		int vertex;
		int weigth;
		edgenode* next;
	};
	struct vertexnode {
		int vertex;
		edgenode* firstnode;
	};
	int vertices;
	vertexnode* nodes;
public:
	Graph(int vertices);
	~Graph();
	void addedge(int, int, int);
	void print();
};
Graph::Graph(int vertices) {
	this->vertices = vertices;
	nodes = new vertexnode[vertices];
	for (int i = 0; i < vertices; ++i) {
		nodes[i].vertex = i;
		nodes[i].firstnode = NULL;
	}
}
Graph::~Graph() {
	for (int i = 0; i < vertices; ++i) {
		edgenode* curr = nodes[i].firstnode;
		while (curr) {
			edgenode* tmp = curr;
			curr = curr->next;
			delete tmp;
		}
	}
	delete[] nodes;
	nodes = NULL;
}
void Graph::addedge(int u, int v, int w) {
	edgenode* newnode = new edgenode;
	newnode->vertex = v;
	newnode->weigth = w;
	newnode->next = nodes[u].firstnode;
	nodes[u].firstnode = newnode;
}
void Graph::print() {
	for (int i = 0; i < vertices; ++i) {
		cout << nodes[i].vertex << "->";
		edgenode* curr = nodes[i].firstnode;
		while (curr) {
			cout << curr->vertex << "(" << curr->weigth << ")" << " ";
			curr = curr->next;
		}
	}
}
int main() {

}