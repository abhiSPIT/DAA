#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void quicksort(int number[25],int first,int last){
    int i, j, pivot, temp;
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        while(i<j){
            while(number[i]<=number[pivot]&&i<last)
                i++;
            while(number[j]>number[pivot])
                j--;
            if(i<j){
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void getNumbers(int arr[],int x){
    for(int i=0;i<x*100;i++){
        arr[i] = rand()%1000 + 1;
    }
}

/* Driver code */
int main()
{
    int arr[100000];
    int x=1;
    clock_t start,end;
    for(x=1;x<=1000;x++){
        getNumbers(arr,x);
        start = clock();
        mergeSort(arr, 0, x*100 - 1);
        end = clock();
        printf("%f\n",((float)(end-start))/CLOCKS_PER_SEC);
    }
    return 0;
}
        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quicksort(number,first,j-1);
        quicksort(number,j+1,last);
    }
}
void getNumbers(int arr[],int x){
    for(int i=0;i<x*100;i++){
        arr[i] = rand()%1000 + 1;
    }
}
int main(){
    int i, count, arr[100000];
    int x=1;
    clock_t start,end;
    for(x=1;x<=1000;x++){
        getNumbers(arr,x);
        start = clock();
        quicksort(arr,0,x*100-1);
        end = clock();
        printf("%f\n",((float)(end-start))/CLOCKS_PER_SEC);
    }    

    return 0;
}
