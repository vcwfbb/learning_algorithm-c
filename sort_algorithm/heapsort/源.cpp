#include<iostream>
using namespace std;
void heapify(int a[], int size, int curr) {
	int optid = curr;
	int lson = curr * 2 + 1;
	int rson = curr * 2 + 2;
	if (lson<size && a[lson]>a[optid]) optid = lson;
	if (rson<size && a[rson]>a[optid]) optid = rson;
	if (optid != curr) {
		swap(a[optid], a[curr]);
		heapify(a, size, optid);
	}
}
void heapsort(int a[], int size) {
	for (int i = size / 2 - 1; i >= 0; --i) {
		heapify(a, size, i);
	}
	for (int i = size - 1; i >= 0; --i) {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}
int main() {
	int a[] = { 2,7,3,1,4,5,9,0,7 };
	heapsort(a, 9);
	for (int i = 0; i < 9; ++i) {
		cout << a[i] << ' ';
	}
	return 0;
}