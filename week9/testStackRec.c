#include <stdio.h>
#include "stackRec.h"

int main(void)
{
    int a[6] = {4, 7, 1, -9, 26, 13};
    StackType stack;
    initialize(&stack);
    for (int i = 0; i < 6; ++i)
        push(a[i], &stack);
    puts("Pop all elements in stack!");
    while (!isEmpty(&stack))
    {
        printf("%4d\n", pop(&stack));
    }
}