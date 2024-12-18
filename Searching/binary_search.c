// Copyright to Bhargav Nath @ 2023 All Rights Reserved //
// Binary Search //
#include<stdio.h>
int binarySearch(int a[], int key, int low, int high)
{
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        else if(a[mid]<key)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    } 
    return -1;
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
    printf("*** BINARY SEARCH ***");
    int a[] = {1, 3, 4, 5, 6, 7, 9, 11, 13};
    printf("\nGiven Array is...\n");
    int n = sizeof(a)/sizeof(a[0]);
    printArray(a, n);
    int key;
    printf("\nEnter the number you want to search: ");
    scanf("%d", &key);
    int result = binarySearch(a, key, 0, n-1);
    if(result==-1)
    {
        printf("Not Found");
    }
    else
    {
        printf("Element is at index %d", result);
    }
    return 0;
}