#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAXSIZE 10000
#define ELEMET_TYPE int

void Swap(int A[], int i, int j)
{
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

void CocktailSort(int A[], int len)
{
    int left = 0;
    int right = len-1;
    while(left < right)
    {
        for(int i=left; i<right; i++)
        {
           if(A[i] > A[i+1])
           {
               Swap(A, i, i+1);
           }
        }
        right--;

        for(int j=right; j > left; j--)
        {
            if(A[j-1] > A[j])
            {
                Swap(A, j-1, j);
            }
        }
        left++;
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

    CocktailSort(A, len);

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
        CocktailSort(test_elem,test_num);
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
