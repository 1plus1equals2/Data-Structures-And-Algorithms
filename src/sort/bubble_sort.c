#include <stdio.h>
#include <stdlib.h>

void Swap(int A[], int i, int j)
{
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

void BubbleSort(int A[], int len)
{
    for(int i=0; i<len-1; i++)
    {
        for(int j=0; j<len-1-i; j++)
        {
            if(A[j] > A[j+1])
            {
                Swap(A, j, j+1);
            }
        }
    }
}

int main(int argc, char **argv)
{
    int A[] = {6, 3, 5, 10, 1, 4, 2, 8, 9};
    int len = sizeof(A)/sizeof(int);

    printf("orgi arr:\n");
    for(int i=0; i < len; i++)
        printf("%d ", A[i]);
    printf("\n");

    BubbleSort(A, len);

    printf("sort arr:\n");
    for(int i=0; i < len; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
