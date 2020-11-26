#include "stackArr.h"
int main()
{
    int a[6] = {4, 7, 1, -9, 26, 13};
    int i;
    StackType s;
    initialize(s);
    for (int i = 0; i < 6; i++)
        push(a[i], s);
    printf("pop all elements in stack!\n");
    while (!empty(s))
    {
        printf("%4d\n", pop(s));
    }
    return 0;
}