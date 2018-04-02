#include <stdio.h>
#include <stdlib.h>

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- 如果能在内部循环第一次运行时,使用一个旗标来表示有无需要交换的可能,可以把最优时间复杂度降低到O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定

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
