#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include"head.h"

int main() {
	int n;
	printf("please input the num of char:");
	scanf("%d", &n);
	HFMnode* leaves = (HFMnode*)malloc(sizeof(HFMnode) * n);
	printf("please input %d pairs of char and their weight:\n", n);
	for (int i = 0; i < n; ++i) {
		scanf(" %c %d", &leaves[i].val, &leaves[i].wei);

		leaves[i].lchild = -1;
		leaves[i].rchild = -1;
		leaves[i].parent = -1;
	}
	HFMnode* HFM1 = creat(leaves, n);
	printf("\n");
	printHFM(HFM1, n);
	HFMcode* code = (HFMcode*)malloc(sizeof(HFMcode) * n);
	buildHuffmanCodes(HFM1, n, code);
	for (int i = 0; i < n; ++i) {
		printf("%c:", code[i].ch);
		puts(code[i].bit);
		printf("\n");
	}
	char* key = (char*)malloc(sizeof(char) * MAXbit);
	while (1) {
		printf("please input the key:");
		scanf(" %s", key);
		getchar();
		if (decode(HFM1, n, key) != '\0') {
			printf(" %c\n", decode(HFM1, n, key));
		}
		int x;
		printf("1:continue   2:end and print the tree\n");
		scanf("%d", &x);
		if (x != 1) {
			break;
		}
	}
	printtree(HFM1, n);
	return 0;
}

