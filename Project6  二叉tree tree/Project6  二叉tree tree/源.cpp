#include<iostream>
using namespace std;
template <class T>
class treenode {
	T data;
	treenode<T>* left;
	treenode<T>* right;
	treenode(T x) :data(x), left(NULL), right(NULL) {};
	treenode() :data(0), left(NULL), right(NULL) {};
};
template <class T>
class tree {
private:
	treenode<T>* nodes;
	treenode<T>* root;
	int size;
	void preorder(treenode<T>* node);
	void inorder(treenode<T>* node);
	void pastorder(treenode<T>* node);
	void leveorder(treenode<T>* node);
public:
	tree();
	tree(int);
	~tree();
	void preorder();
	void inorder();
	void pastorder();
	void levelorder();
	treenode<T>* getindex(int index) { return &nodes[index]; };
	treenode<T>* visit(treenode<T>* node) { cout << node->data << " "; };

};
template <class T>
void tree<T>::preorder(treenode<T>* node) {
	if (node == NULL) return;
	visit(node);
	preorder(node->left);
	preorder(node->right);
}
template<class T>
void tree<T>::preorder() {
	if (root == NULL) return;
	visit(node);
	preorder(root->left);
	preorder(root->right);
}
template <class T>
tree<T>::tree() {
	size = 413226;
	nodes = new treenode<T>[413226];
}
template<class T>
tree<T>::tree(int x) {
	size = x;
	nodes = new treenode<T>[x];
}
template<class T>
tree<T>::~tree() {
	delete[] nodes;
}

int main() {
	tree<chat> t;
	t.levelorder();
	return 0;
}