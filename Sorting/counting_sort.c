// Copyright to Bhargav Nath @ 2023 All Rights Reserved //
// Counting Sort //

#include<stdio.h>

void countingSort(int a[], int n)
{
    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(a[i]>max)
            max = a[i];
    }

    int count[max+1];
    for(int i=0; i<=max; i++)
    {
        count[i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        count[a[i]]++;
    }

    for(int i=1; i<=max; i++)
    {
        count[i]+=count[i-1];
    }

    int output[n];
    for(int i=0; i<=n; i++)
    {
        output[count[a[i]]-1]=a[i];
        count[a[i]]--;
    }

    for (int i=0; i<n; i++) {
        a[i] = output[i];
    }
}

void printArr(int arr[], int n)  
{  
    for (int i = 0; i < n; ++i)  
    {  
        printf("%d", arr[i]);  
        printf(" ");  
    }          
}

int main()  
{  
    int a[] = {48, 10, 23, 43, 28, 26, 1};  
    int n = sizeof(a) / sizeof(a[0]);  
    printf("Before sorting array elements are - \n");  
    printArr(a, n);  
    countingSort(a, n);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a, n);  
    return 0;  
}  