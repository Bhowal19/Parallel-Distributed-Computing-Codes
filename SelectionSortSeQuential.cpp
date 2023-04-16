#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"
#include<unistd.h>
clock_t t, end;
double time_spent=0.0;
// Structure for enabling reduction on the index of elements
struct Compare { int val; int index; };
// Custom reduction for finding hte index of the max element.
void swap(int* a, int* b);
void selectionSort(int* A, int n);
void verify(int* A, int n);

int main(){
	printf("\n**********************SELECTION SORT Sequential**********************");
	
int number, iter =0;
int* Arr;
 double time_spent=0.0;
Arr = (int *)malloc( number * sizeof(int));
printf("\nEnter the number of elements:\n");
scanf("%d", &number);
printf("\nEnter the elements:\n");
for(; iter<number; iter++){
scanf("%d", &Arr[iter]);
}
clock_t start=clock();
selectionSort(Arr, number);
clock_t end=clock();
time_spent += (double)(end - start) / CLOCKS_PER_SEC;
for(int iter=0; iter<number;iter++){
printf("%d ", Arr[iter]);
}
// Verify if the algorithm works as advised
verify(Arr, number);
printf("\ntime:%f",time_spent);
return 0;
}
void selectionSort(int* A, int n){
for(int startpos =0; startpos< n; startpos++){
// Declare the structure required for reduction
struct Compare max;
 // Initialize the variables
max.val = A[startpos];
max.index = startpos;
 // Parallel for loop with custom reduction, at the end of the loop, max will have the max element and its index.
for(int i=startpos +1; i< n; ++i){
if(A[i] >max.val){
max.val = A[i];
max.index = i;
}
}
swap(&A[startpos], &A[max.index]);
}
}
// Verification function
void verify(int* A, int n){
int failcount = 0;
for(int iter = 0; iter< n-1; iter++){
if(A[iter] < A[iter+1]){
failcount++;
}
}
printf("\nFail count: %d\n", failcount);
}
//Swap function
void swap(int* a, int* b){
int temp = *a;
*a = *b;
*b = temp;
}

