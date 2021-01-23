#include <stdio.h>
#include "queueCircular.h"

int main(void)
{
    int a[6] = {4, 7, 1, -9, 26, 13};
    Queue queue;
    MakeNull_Queue(&queue);
    for (int i = 0; i < 6; ++i)
        EnQueue(a[i], &queue);
    puts(" DeQueue all elements in queue!");
    while (!Empty_Queue(queue))
    {
        printf("%4d\n", DeQueue(&queue));
    }
}