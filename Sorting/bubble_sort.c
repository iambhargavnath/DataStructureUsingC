// Copyright to Bhargav Nath @ 2023 All Rights Reserved //
// Bubble Sort //
#include<stdio.h>
void printArray(int a[], int n)
{
    for(int index=0; index<n; index++)
    {
        printf("%d ",a[index]);
    }
}  
int main()
{
    printf("*** BUBBLE SORT ***");
    int a[] = {7, 8, 6, 2, 9, 1, 11, 15, 13};
    int n = sizeof(a)/sizeof(a[0]);
    printf("\n\nArray Before Sorting...\n");
    printArray(a, n);
    printf("\n");
    for(int i=0; i<n-1; i++)
    {
        printf("\nAfter Iteration %d...\n", i+1);
        int swapped = 0;
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swapped = 1;
            }
            printArray(a, n);
            printf("\n");
        }    
        if(swapped==0)
        {
            break;
        }
    }
    printf("\nArray After Final Sorting...\n");
    printArray(a, n);
    printf("\n\n");
}