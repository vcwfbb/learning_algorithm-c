#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MAXbit 10
typedef struct HFMnode {
	int wei;
	char val;
	int lchild, rchild;
	int parent;
}HFMnode;
typedef struct MINheap {
	int size;
	int capacity;
	HFMnode* nodes;
}MINheap;
typedef struct HFMcode {
	char bit[MAXbit];
	char ch;
}HFMcode;
bool operator<(HFMnode a, HFMnode b) {
	return a.wei < b.wei;
}
void InitHeap(MINheap* heap, int capacity) {
	heap->size = 0;
	heap->capacity = capacity;
	heap->nodes = (HFMnode*)malloc(capacity * sizeof(HFMnode));
}
void Insert(MINheap* heap, HFMnode node) {
	if (heap->size >= heap->capacity) {
		return;
	}
	int index = heap->size;
	int parent = (index - 1) / 2;
	heap->nodes[index] = node;
	heap->size++;
	while (index != 0 && heap->nodes[index] < heap->nodes[parent]) {
		HFMnode tmp = heap->nodes[index];
		heap->nodes[index] = heap->nodes[parent];
		heap->nodes[parent] = tmp;
		index = parent;
		parent = (index - 1) / 2;
	}
}
HFMnode Remove(MINheap* heap) {
	if (heap->size == 0) {
		return HFMnode();
	}
	HFMnode minnode = heap->nodes[0];
	heap->nodes[0] = heap->nodes[heap->size - 1];
	heap->size--;
	int index = 0;
	int n = heap->size;
	while (1) {
		int smallest = index;
		int left = smallest * 2 + 1;
		int right = smallest * 2 + 2;
		if (left < n && heap->nodes[left] < heap->nodes[smallest]) {
			smallest = left;
		}
		if (right < n && heap->nodes[right] < heap->nodes[smallest]) {
			smallest = right;
		}

		if (smallest != index) {
			HFMnode tmp = heap->nodes[index];
			heap->nodes[index] = heap->nodes[smallest];
			heap->nodes[smallest] = tmp;
			index = smallest;
		}
		else {
			return minnode;
		}
	}
	return minnode;
}

HFMnode* creat(HFMnode* leaves, int n) {
	int total_nodes = 2 * n - 1;
	HFMnode* tree = (HFMnode*)malloc(total_nodes * sizeof(HFMnode));
	for (int i = 0; i < n; i++) {
		tree[i] = leaves[i];
		tree[i].parent = -1;
		tree[i].lchild = -1;
		tree[i].rchild = -1;
	}
	MINheap heap;
	InitHeap(&heap, total_nodes);
	for (int i = 0; i < n; i++) {
		Insert(&heap, tree[i]);
	}
	int pos = n;
	while (heap.size > 1) {
		HFMnode left = Remove(&heap);
		HFMnode right = Remove(&heap);
		int leftIdx = -1, rightIdx = -1;
		tree[pos].val = '0';
		tree[pos].lchild = -1;
		tree[pos].rchild = -1;
		tree[pos].parent = -1;
		for (int i = 0; i < pos; i++) {
			if (tree[i].parent != -1) continue;
			if (tree[i].lchild == -1 && tree[i].rchild == -1) {
				if (tree[i].val == left.val && tree[i].wei == left.wei) {
					leftIdx = i;
				}
				if (tree[i].val == right.val && tree[i].wei == right.wei) {
					rightIdx = i;
				}
			}
			else {
				if (tree[i].lchild == left.lchild && tree[i].rchild == left.rchild) {
					leftIdx = i;
				}
				if (tree[i].lchild == right.lchild && tree[i].rchild == right.rchild) {
					rightIdx = i;
				}
			}
		}
		tree[pos].wei = tree[leftIdx].wei + tree[rightIdx].wei;  tree[pos].lchild = leftIdx;   tree[pos].rchild = rightIdx;
		tree[leftIdx].parent = pos;   tree[rightIdx].parent = pos;
		Insert(&heap, tree[pos]);
		pos++;
	}
	free(heap.nodes);
	return tree;
}

void printHFM(HFMnode* tree, int n) {
	int total = 2 * n - 1;
	printf("%-5s %-4s %-6s %-6s %-6s %-6s\n", "index", "char", "weight", "lchild", "rchild", "parent");
	for (int i = 0; i < total; ++i) {
		printf("%-5d %-4c %-6d %-6d %-6d %-6d\n",
			i, tree[i].val, tree[i].wei,
			tree[i].lchild, tree[i].rchild, tree[i].parent);
	}
}

void buildHuffmanCodes(HFMnode* tree, int n, HFMcode* code) {
	int total = 2 * n - 1;
	int count = 0;
	// 遍历所有节点，只处理叶节点（左右孩子均为 -1）
	for (int i = 0; i < total; i++) {
		if (tree[i].lchild == -1 && tree[i].rchild == -1) {
			code[count].ch = tree[i].val;

			int cur = i;
			int parent = tree[cur].parent;
			char temp[MAXbit];
			int idx = 0;
			// 从叶节点向上回溯到根
			while (parent != -1) {
				if (tree[parent].lchild == cur)
					temp[idx++] = '0';
				else
					temp[idx++] = '1';
				cur = parent;
				parent = tree[cur].parent;
			}
			temp[idx] = '\0';
			// 反转得到正序编码
			int k = 0;
			for (int j = idx - 1; j >= 0 && k < MAXbit - 1; --j, ++k) {
				code[count].bit[k] = temp[j];
			}
			code[count].bit[k] = '\0';
			count++;
		}
	}
}
char decode(HFMnode* tree, int n, char* ch) {
	if (!tree || !ch) return '\0';
	int total = 2 * n - 1;
	int cur = -1;
	for (int i = 0; i < total; ++i) {
		if (tree[i].parent == -1) {
			cur = i;
			break;
		}
	}
	if (cur == -1) return '\0';

	for (int i = 0; i < strlen(ch); ++i) {
		if (ch[i] == '0') {
			cur = tree[cur].lchild;
		}
		else if (ch[i] == '1') {
			cur = tree[cur].rchild;
		}
		else {
			printf("wrong key\n");
			return '\0';
		}
		if (cur == -1) {
			return '\0';
		}
	}
	if (tree[cur].lchild == -1 && tree[cur].rchild == -1) {
		return tree[cur].val;
	}
	return '\0';
}
void printTreeRec(HFMnode* tree, int node, int depth, const char* prefix, int isLast) {
	if (node == -1) return;

	// 输出缩进
	printf("%s", prefix);
	// 如果不是根节点，输出连线符号
	if (depth > 0) {
		printf(isLast ? "+-" : "|--");
	}

	// 输出节点信息：权值，如果是叶子节点则显示字符
	printf("%d", tree[node].wei);
	if (tree[node].lchild == -1 && tree[node].rchild == -1) {
		printf("(%c)", tree[node].val);
	}
	printf("\n");

	// 准备子节点的前缀
	char newPrefix[256];
	strcpy(newPrefix, prefix);
	if (depth > 0) {
		// 根据当前节点是否最后一个，添加适当的续接符号
		if (isLast) {
			strcat(newPrefix, "     ");   // 四个空格
		}
		else {
			strcat(newPrefix, "|    ");   // 竖线加三个空格
		}
	}
	else {
		// 根节点无前缀
		strcpy(newPrefix, "");
	}

	// 先递归打印左子树，再递归打印右子树
	// 注意：需要判断左右孩子是否存在，以及顺序（通常先左后右）
	int left = tree[node].lchild;
	int right = tree[node].rchild;
	if (left != -1) {
		// 判定左孩子是否是最后一个孩子（即右孩子不存在）
		printTreeRec(tree, left, depth + 1, newPrefix, (right == -1));
	}
	if (right != -1) {
		printTreeRec(tree, right, depth + 1, newPrefix, 1); // 右孩子总是最后一个
	}
}


void printtree(HFMnode* tree, int n) {
	int total = 2 * n - 1;
	int root = -1;

	for (int i = 0; i < total; i++) {
		if (tree[i].parent == -1) {
			root = i;
			break;
		}
	}
	if (root == -1) {
		return;
	}
	printTreeRec(tree, root, 0, "", 1);
}
