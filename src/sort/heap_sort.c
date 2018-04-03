#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAXSIZE 10000
#define ELEMET_TYPE int

void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void max_heapify(int arr[], int start, int end) {
    //建立父节点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { //若子节点指标在范围内才做比较
        if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
            son++;
        if (arr[dad] > arr[son]) //如果父节点大于子节点代表调整完毕，直接跳出函数
            return;
        else { //否则交换父子内容再继续子节点和孙节点比较
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len) {
    int i;
    //初始化，i从最后一个父节点开始调整
    for (i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    //现将第一个元素和已排好元素前一位做交换，再重新调整，直到排序完毕
    for (i = len - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

#if 0
int main() {
    int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    int len = (int) sizeof(arr) / sizeof(*arr);

    int i;
    printf("orig arr:\n");
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    heap_sort(arr, len);

    printf("sort arr:\n");
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
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
        heap_sort(test_elem,test_num);
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
