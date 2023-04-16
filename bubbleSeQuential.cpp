#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
int BubbleSort(int arr[],int n)
{
 int nr=0,changes=1,tmp;
 while(changes){
 {
 nr++;
 changes=0;
for(int i=0;i<n-1;i+=2){
 if(arr[i] >arr[i+1]){
tmp=arr[i];
arr[i]=arr[i+1];
arr[i+1]=tmp;
 ++changes;
 }
 }
for(int i=1;i<n-1;i+=2){
 if(arr[i]>arr[i+1]){
tmp=arr[i];
arr[i]=arr[i+1];
arr[i+1]=tmp;
 ++changes;
 }
 }
 }
 }
}
int main(){
 int n,arr[10],i;
 double time_spent=0.0;
printf("\nEnter the number of elements: ");
scanf("%d",&n);
 for(i=0;i<n;i++){
scanf("%d",&arr[i]);
 }
printf("\nOriginal Array: ");
for(int i=0;i<n;i++){
printf("%d\t",arr[i]);
 }
clock_t begin=clock();
BubbleSort(arr,n);
sleep(1);
clock_t end = clock();
time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
printf("\nSorted Array: ");
for(int i=0;i<n;i++){
printf("%d\t",arr[i]);
 }
printf("\n");
printf("\ntime is %f ", time_spent);
 return 0;
}
