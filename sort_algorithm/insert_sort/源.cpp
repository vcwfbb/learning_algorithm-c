#include<iostream>
using namespace std;

void insertsort(int a[], int size) {
	for (int i = 1; i < size; ++i) {
		int x = a[i];  int j = i - 1;
		while (j >= 0) {
			if (a[j] > x) {
				a[j + 1] = a[j];
				j--;
			}
			else {
				break;
			}
		}
		a[j + 1] = x;
   }
}

int main() {
	int a[] = { 8,6,3,4,5,7,9,2 };
	insertsort(a, 8);
	for (auto u : a) {
		cout << u << ' ';
	}
	return 0;
}