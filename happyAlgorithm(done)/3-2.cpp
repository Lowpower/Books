#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void merge(int A[], int low, int mid, int high) {
	int *B = new int[high-low+1];
	int i = low, j = mid+1, k = 0;
	while(i <= mid && j<= high) {
		if(A[i] <= A[j]) {
			B[k++] = A[i++];
		} else {
			B[k++] = A[j++];
		}
	}
	while(i <= mid) B[k++] = A[i++];
	while(j <= high) B[k++] = A[j++];
	for(i = low, k = 0; i <= high; i++) {
		A[i] = B[k++];
	}
}

void MergeSort (int A[], int low, int high) {
	if(low < high) {
		int mid = (low+high) /2;
		MergeSort(A, low, mid);
		MergeSort(A, mid+1, high);
		merge(A, low, mid, high);
	}
}

int main() {
	return 0;
}
