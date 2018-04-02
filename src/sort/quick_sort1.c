#include <stdio.h>
#include <stdlib.h>

void Swap(int A[], int i, int j)
{
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

int Partition(int A[], int left, int right)
{
    int pivot = A[right];
    int tail = left - 1;
    for(int i = left; i < right; i++)
    {
        if(A[i] <= pivot)
        {
            Swap(A, i, ++tail);
        }
    }
    Swap(A, right, ++tail);
    return tail;
}

int PartitionV2(int A[], int left, int right)
{
    int pivot = A[right];
    int tail = left;
    int i = left;
    int j = right-1;
    while(i <= j)
    {
        while(A[i] < pivot && i<j)
            i++;
        while(A[j] > pivot && i<j)
            j--;
        if(i<=j)
        {
            Swap(A, i, j);
            i++;
            j--;
        }
    }

    Swap(A, i, right);
    tail = i;
    return tail;
}

void QuickSort(int A[], int left, int right)
{
    if(left >= right)
        return;

    int pivot_index = PartitionV2(A, left, right);
    QuickSort(A, left, pivot_index-1);
    QuickSort(A, pivot_index+1, right);
}

int main(int argc, char **argv)
{
    int A[] = {6, 3, 5, 10, 1, 4, 2, 8, 9, 7};
    int len = sizeof(A)/sizeof(int);

    printf("orgi arr:\n");
    for(int i=0; i < len; i++)
        printf("%d ", A[i]);
    printf("\n");

    QuickSort(A, 0, len-1);

    printf("sort arr:\n");
    for(int i=0; i < len; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
