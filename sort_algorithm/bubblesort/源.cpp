#include<iostream>
using namespace std;
void bubblesort(int a[], int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main() {
	int a[] = { 6,4,7,3,8,2,9,1 };
	bubblesort(a, 8);
	for (auto u : a) {
		cout << u << " ";
	}
	cout << endl;
	return 0;
}