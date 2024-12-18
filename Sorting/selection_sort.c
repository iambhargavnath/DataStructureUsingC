// Copyright to Bhargav Nath @ 2023 All Rights Reserved //
// Selection Sort //
#include<stdio.h>
void selectionSort(int a[], int n)
{
    int min;
    for(int i = 0; i<n-1; i++)
    {
        min = i;
        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
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
    printf("*** SELECTION SORT ***");
    int a[] = {7, 8, 6, 2, 9, 1, 4, 11, 13};
    int n = sizeof(a)/sizeof(a[0]);
    printf("\nArray Before Sorting...\n");
    printArray(a, n);
    selectionSort(a, n);
    printf("\nArray After Sorting...\n");
    printArray(a, n);
    return 0;
}