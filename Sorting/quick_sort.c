// Copyright to Bhargav Nath @ 2023 All Rights Reserved //
// Quick Sort //
#include<stdio.h>
int partition(int a[], int start, int end)
{
    int pivot = a[start];
    int i = start;
    int j = end;
    while (i<j)
    {
        while (!(a[i]>pivot))
        {
            i++;
        }
        while (!(a[j]<=pivot))
        {
            j--;
        }
        if(i<j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }   
    }
    a[start] = a[j];
    a[j] = pivot;
    return j;
}
void quickSort(int a[], int start, int end)
{
    if(start<end)
    {
        int p = partition(a, start, end);
        quickSort(a, start, p-1);
        quickSort(a, p+1, end);
    }
}
void printArray(int a[], int n)
{
    for(int index=0; index<n; index++)
    {
        printf("%d ",a[index]);
    }
} 
int main()
{
    printf("*** QUICK SORT ***");
    int a[] = {7, 8, 6, 2, 9, 1, 4, 11, 13};
    int n = sizeof(a)/sizeof(a[0]);
    printf("\nArray Before Sorting...\n");
    printArray(a, n);
    quickSort(a, 0, n-1);
    printf("\nArray After Sorting...\n");
    printArray(a, n);
    return 0;
}