#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAXSIZE 10000
#define ELEMET_TYPE int

typedef struct
{
    int low;
    int high;
} Node;

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
        while(A[i] < pivot && i<=j)
            i++;
        while(A[j] > pivot && i<=j)
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
    Node nodes[1000];
    int top=-1,low,high;
    top++;
    nodes[top].low = left;
    nodes[top].high = right;

    while(top>-1)
    {
        low = nodes[top].low;
        high = nodes[top].high;
        top--;

        if(low < high)
        {
            int pivot_index = PartitionV2(A, low, high);
            top++;
            nodes[top].low = low;
            nodes[top].high = pivot_index-1;

            top++;
            nodes[top].low = pivot_index+1;
            nodes[top].high = high;
        }
    }
}

int isASCENDING(ELEMET_TYPE heap[],int n)  
{  
    int i;  
    for(i=n-1;i>0;i--)
        if(heap[i-1]>heap[i])  
            return 0;
    return 1;
}

void QUICKSORT(ELEMET_TYPE data[],int n)
{
    QuickSort(data, 0, n-1);
}

void OUTPUT(ELEMET_TYPE data[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", data[i]);
    printf("\n");
}

void runtest()
{
    ELEMET_TYPE test_elem[10000];
    srand(time(NULL));
    for(int test_Turn=0;test_Turn<100;test_Turn++)
    {
        int test_num=rand()%5000+5000;
        printf("turn %d, test_arr_size: %d, ", test_Turn+1, test_num);
        for(int i=0;i<test_num;i++)
            test_elem[i]=rand();
        QUICKSORT(test_elem,test_num);
        if(!isASCENDING(test_elem,test_num))
        {
            printf("fail\n");
            exit(0);
        }
        printf("succ\n");
    }
    printf("test ok\n");
}

int main(int argc, char **argv)
{
    runtest();
    return 0;
}
