/*
 * 计数排序用到一个额外的计数数组C，根据数组C来将原数组A中的元素排到正确的位置。
 * 通俗地理解，例如有10个年龄不同的人，假如统计出有8个人的年龄不比小明大（即小于等于小明的年龄，这里也包括了小明）,
 * 那么小明的年龄就排在第8位，通过这种思想可以确定每个人的位置，也就排好了序。
 * 当然，年龄一样时需要特殊处理（保证稳定性）：通过反向填充目标数组，填充完毕后将对应的数字统计递减，可以确保计数排序的稳定性。
 * 
 * 计数排序的步骤如下：
 * 1. 统计数组A中每个值A[i]出现的次数，存入C[A[i]]
 * 2. 从前向后，使数组C中的每个值等于其与前一项相加，这样数组C[A[i]]就变成了代表数组A中小于等于A[i]的元素个数
 * 3. 反向填充目标数组T：将数组元素A[i]放在数组T的第C[A[i]]个位置（下标为C[A[i]] - 1），每放一个元素就将C[A[i]]递减
 *
 * 计数排序的时间复杂度和空间复杂度与数组A的数据范围（A中元素的最大值与最小值的差加上1）有关，
 * 因此对于数据范围很大的数组，计数排序需要大量时间和内存。
 * 例如：对0到99之间的数字进行排序，计数排序是最好的算法，然而计数排序并不适合按字母顺序排序人名，将计数排序用在基数排序算法中，
 * 能够更有效的排序数据范围很大的数组。
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAXSIZE 10000
#define ELEMET_TYPE int

const int k = MAXSIZE;
int C[MAXSIZE] = {0};

void CountingSort(int A[], int len)
{
    memset(C, 0, k*sizeof(int));

    for(int i = 0; i < len; i++)
        C[A[i]]++;

    for(int i = 1; i < k; i++)
        C[i] += C[i - 1];

    int *T = malloc(len * sizeof(int));
    for(int i = len - 1; i >= 0; i--)
        T[--C[A[i]]] = A[i];

    for(int i = 0; i < len; i++)
        A[i] = T[i];

    free(T);
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

    CountingSort(A, len);

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
            test_elem[i]=rand()%MAXSIZE; //TODO 数字不能太大，小于C数组大小就没问题
        CountingSort(test_elem,test_num);
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
