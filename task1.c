//Michael Küchler, 16-924-318

#include <stdio.h>

void maxHeapify(int A[], int i, int n){
	int largest;
	int l = 2*i;
	int r = 2*i + 1;
	if(l <= n && A[l] > A[i]){
		largest = l;
	}
	else{
		largest = i;
	}
	if(r <= n && A[r]>A[largest]){
		largest = r;
	}
	if(largest != i){
		int temp = A[i];
		A[i]= A[largest];
		A[largest] = temp;
		maxHeapify(A,largest,n);	
	}
}

void buildMaxHeap(int A[], int n){
	for(int i = n/2;i>=0;i--){
		maxHeapify(A,i,n);
	}
}
void printHeap(int A[], int n){
	
}
void heapSort(int A[], int n){
	
}
void printArray(int A[], int n){
	
}
int main(){
	
	return 0;
}
