//Michael Küchler, 16-924-318

#include <stdio.h>
//beim unvollständigen heap : out of array!

void maxHeapify(int A[], int i, int n){
	int largest;
	int l = 2*i+1;
	int r = 2*i+2;
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
	for(int i = n/2 - 1;i>=0;i--){
		maxHeapify(A,i,n);
	}
	//printHeap(A,n);
}
void printHeap(int A[], int n){
	printf("graph g {\n");
	for(int i = 0;i<n/2;i++){	
		printf("%d -- %d\n%d -- %d\n",A[i],A[i*2+1],A[i],A[i*2+2]);
	}
	printf("}\n");
	
}
void heapSort(int A[], int n){
	//create a Heap
	buildMaxHeap(A,n);
	
	for(int i = n-1;i>=0;i--){
		//swap first and last element
		int temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		//create Heap again	
		maxHeapify(A,0,i);
	}
	
}
void printArray(int A[], int n){
	//not working
	printf("[");
	for(int i = 0;i<n-1;++i){
		printf("%d, ",A[i]);
	}
	printf("%d]",A[n-1]);
	
}
int main(){
	int A[]={3,8,9,1,7};
	heapSort(A,5);
	printHeap(A,5);
	printArray(A,5); //gibt immer den heap zurück, nicht ein sortiertes array!
	return 0;
}
