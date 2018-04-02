#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int value;
    void* next;
} T;

void init(T *h, int size)
{
    T *t = h;
    for(int i=0; i<size; i++)
    {
        T *tmp = malloc(sizeof(T));
        memset(tmp, 0, sizeof(T));
        tmp->value = i;
        t->next = tmp;
        t = t->next;
    }
}

void output(T *h)
{
    T *t = h->next;
    while(t)
    {
        printf("%d ", t->value);
        t = t->next;
    }
    printf("\n");
}

T* reverse(T *h)
{
    if(NULL == h)
        return NULL;

    T *t = h->next;
    T *rev = malloc(sizeof(T));
    while(t)
    {
        T *t_next = t->next; 

        t->next = rev->next; 
        rev->next = t;

        t = t_next;
    }
    return rev;
}


int main(int argc, char **argv)
{
    T *h = malloc(sizeof(T));
    init(h, 10);
    printf("init\n"); 
    output(h);
    printf("reverse\n"); 
    output(reverse(h));
    return 0;
}
