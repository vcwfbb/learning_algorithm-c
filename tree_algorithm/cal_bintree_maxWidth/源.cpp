#include<iostream>
#include<queue>
using namespace std;
#define Eletype int
struct treenode {
	Eletype data;
	treenode* left;
	treenode* right;
};

int cal_maxwidth(treenode* root){
	if (!root) return 0;
	int maxWidth = 0;
	queue<treenode*> q;
	q.push(root);

	while (!q.empty()) {
		int levelSize = q.size();
		maxWidth = max(maxWidth, levelSize);

		for (int i = 0; i < levelSize; ++i) {
			treenode* curr = q.front();
			q.pop();
			if (curr->left) q.push(curr->left);
			if (curr->right) q.push(curr->right);
		}

	}

	return maxWidth;
}
int main() {
	return 0;
}