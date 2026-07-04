#include<iostream>
using namespace std;

void merge(int a[], int l, int r) {
	if (l > r) return;
	int mid = (l + r) / 2;
	int len_left = mid - l + 1, len_right = r - mid;
	int* temp = new int[len_left + len_right];
	for (int i = 0; i < len_left + len_right; ++i) {
		temp[i] = a[l + i];
	}

	int i = 0, j = len_left, curr = l;
	while (i < len_left && j < len_left + len_right) {
		if (temp[i] < temp[j]) a[curr++] = temp[i++];
		else a[curr++] = temp[j++];
	}
	while (i < len_left) a[curr++] = temp[i++];
	while (j < len_left + len_right)    a[curr++] = temp[j++];
}
void mergesort(int a[], int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		mergesort(a, l, mid);
		mergesort(a, mid + 1, r);
		merge(a, l, r);
	}
}
int main() {
	int a[] = { 8,5,7,3,6,9,3,0 };
	mergesort(a, 0, 7);
	for (auto u : a) {
		cout << u << " ";
	}
	cout << endl;
	return 0;
}