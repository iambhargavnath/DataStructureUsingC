// Copyright to Bhargav Nath @ 2023 All Rights Reserved //
// Linear Search //
#include<stdio.h>
int linearSearch(int a[], int key, int n)
{
    for(int i=0; i<n; i++)
    {
        if(a[i]==key)
        {
            return i;
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
    printf("*** LINEAR SEARCH ***");
    int a[] = {7, 8, 6, 2, 9, 1, 4, 11, 13};
    printf("\nGiven Array is...\n");
    int n = sizeof(a)/sizeof(a[0]);
    printArray(a, n);
    int key;
    printf("\nEnter the number you want to search: ");
    scanf("%d", &key);
    int result = linearSearch(a, key, n);
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