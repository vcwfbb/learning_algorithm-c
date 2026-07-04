#include<iostream>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
void heapify(int a[],int size,int curr) {
	int optid = curr;
	int lson = curr * 2 + 1;
	int rson = curr * 2 + 2;
	if (lson < size && cmp(a[lson], a[optid]))  optid = lson;
	if (rson < size && cmp(a[rson], a[optid]))  optid = rson;
	if (optid != curr) {
		swap(a[optid], a[curr]);
		heapify(a, size, optid);
	}
}  //---------数组堆化调整(元素下沉)
void heapsort(int a[], int size) {
	for (int i = size / 2 - 1; i >= 0; --i) {
		heapify(a, size, i);
	}//--------数组堆化
	for (int i = size - 1; i >= 0; --i) {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}//-------每次把堆顶元素与最后一个元素交换位置并把最后一个元素从堆中删去 调整堆
}  //--------堆排序
int main() {
	int a[] = {7,6,5,4,3,101,178,56,332,69,40,41,28};
	for (int i = 13/2; i >= 0; --i) {
		heapify(a, 13, i);
	}
	for (int i = 0; i < 13; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	heapsort(a, 13);
	for (int i = 0; i < 13; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}