#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAXSIZE 10000
#define ELEMET_TYPE int

void Merge(int A[], int left, int mid, int right)
{
    int len = right - left + 1;
    int *temp = malloc(len * sizeof(int));
    int index = 0;
    int i = left;
    int j = mid + 1;
    while(i<=mid && j <= right)
        temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];
    while(i <= mid)
        temp[index++] = A[i++];
    while(j <= right)
        temp[index++] = A[j++];
    
    for(int k = 0; k < len; k++)
        A[left++] = temp[k];
}

void MergeSortRecursion(int A[], int left, int right)
{
    if(left == right)
        return;

    int mid = (left + right)/2;
    MergeSortRecursion(A, left, mid);
    MergeSortRecursion(A, mid+1, right);
    Merge(A, left, mid, right);
}

void MergeSortIteration(int A[], int len)
{
    int left,mid,right;
    for(int i=1; i < len; i *= 2)
    {
        left = 0;
        while(left + i < len)
        {
            mid = left + i - 1;
            right = (mid + i) < len ? (mid + i) : (len - 1);
            Merge(A, left, mid, right);
            left = right + 1;
        }
    }
}

#if 0
int main(int argc, char **argv)
{
    int A[] = {6, 3, 5, 10, 1, 4, 2, 8, 9};
    int len = sizeof(A)/sizeof(int);

    printf("orgi arr:\n");
    for(int i=0; i < len; i++)
        printf("%d ", A[i]);
    printf("\n");

    //MergeSortRecursion(A, 0, len-1);
    MergeSortIteration(A, len);

    printf("sort arr:\n");
    for(int i=0; i < len; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
#endif

#if 1
int isASCENDING(ELEMET_TYPE heap[],int n)  
{  
    int i;  
    for(i=n-1;i>0;i--)
        if(heap[i-1]>heap[i])  
            return 0;
    return 1;
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
        //MergeSortRecursion(test_elem, 0, test_num-1);
        MergeSortIteration(test_elem, test_num);
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
#endif
