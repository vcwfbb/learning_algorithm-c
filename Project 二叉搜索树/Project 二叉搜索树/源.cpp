#include<iostream>
using namespace std;
template <class T>
struct treenode {
	T data;
	treenode<T>* leftchild;
	treenode<T>* rightchild;
	treenode() :data(0), leftchild(NULL), rightchild(NULL) {};
	treenode(T data):data(data), leftchild(NULL), rightchild(NULL) {};
};
template <class T>
class BSTree {
private:
	treenode<T>* root;
	treenode<T>* insert(treenode<T>* node, T data);
	treenode<T>* remove(treenode<T>* node, T data);
	void destroy(treenode<T>* node);
	void inorder(treenode<T>* node);
	bool search(treenode<T>* node, T data);
public:
	BSTree() :root(NULL) {};
	~BSTree();
	void insert(T data);
	void remove(T data);
	bool search(T data);
	void inorder();
};
template <class T>
void BSTree<T>::remove(T data) {
	root=remove(root, data);
}
template <class T>
treenode<T>* BSTree<T>::remove(treenode<T>* node, T data) {
	if (node == NULL) return NULL;
	if (data > node->data) {
		node->rightchild = remove(node->rightchild, data);
	}
	else if (data < node->data) {
		node->leftchild = remove(node->leftchild, data);
	}
	else {
		if (!node->leftchild && !node->rightchild) {
			delete node;
			return NULL;
		}
		else if (!node->rightchild) {
			treenode<T>* left = node->leftchild;
			delete node;
			return left;
		}
		else if (!node->leftchild) {
			treenode<T>* right = node->rightchild;
			delete node;
			return right;
		}
		else {
			treenode<T>* tmp = node->rightchild;
			while (tmp->leftchild) {
				tmp = tmp->leftchild;
			}
			node->data = tmp->data;
			node->rightchild=remove(node->rightchild,tmp->data);
		}
	}
	return node;
}

template <class T>
bool BSTree<T>::search(treenode<T>* node, T data) {
	if (node == NULL) return false;
	if (data > node->data) {
		return search(node->rightchild,data);
	}
	if (data < node->data) {
		return search(node->leftchild,data);
	}
	return true;
}
template <class T>
bool BSTree<T>::search(T data) {
	return search(root, data);
}

template <class T>
void BSTree<T>::insert(T data) {
	root=insert(root, data);
}
template <class T>
treenode<T>* BSTree<T>::insert(treenode<T>* node, T data) {
	if (node == NULL) {
		return new treenode<T>(data);
	}
	if (data>node->data) {
		node->rightchild=insert(node->rightchild,data);
	}
	else if (data < node->data) {
		node->leftchild=insert(node->leftchild,data);
	}
	return node;
}
template <class T>
void BSTree<T>::inorder(treenode<T>* node) {
	if (node == NULL) return;
	inorder(node->leftchild);
	cout << node->data << " ";
	inorder(node->rightchild);
}
template <class T>
void BSTree<T>::inorder() {
	inorder(root);
}
template <class T>
BSTree<T>::~BSTree(){
	destroy(root);
	root = NULL;
}
template <class T>
void BSTree<T>::destroy(treenode<T>* node) {
	if (node == NULL)return;
	destroy(node->left);
	destroy(node->right);
	delete node;
}
int main() {
	
	return 0;
}