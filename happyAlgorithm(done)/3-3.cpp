#include <iostream>

using namespace std;

int Partition(int r[], int low, int high) {
	int i = low, j = high, privot = r[low];
	while(i < j) {
		while(i < j && r[j] > privot) j--;
		if(i<j) {
			swap(r[i++], r[j]);
		}
		while(i<j && r[i] <= privot) i++;
		if(i < j) {
			swap(r[i], r[j--]);
		}
	}
	return i;
}

void QuickSort(int R[], int low, int high) {
	int mid;
	if(low < high) {
		mid = Partition(R, low, high);
		QuickSort(R, low, mid-1);
		QuickSort(R, mid+1, high);
	}
}

int main() {
	return 0;
}
