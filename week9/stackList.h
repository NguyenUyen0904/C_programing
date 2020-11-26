#include <stdio.h>
#include <stdlib.h>

typedef int elementType;
typedef struct StackList
{
    elementType element;
    struct StrackList *next;
};

typedef struct StackList StackType;
//StackType* top;
StackType *push(elementType value, StackType *top)
{
    StackType *new = (StackType *)malloc(sizeof(StackType));
    new->element = value;
    new->next = top;
    top = new;
    return top;
}

int isEmpty(StackType *top)
{
    return top == NULL;
}

StackType *pop(elementType *value, StackType *top)
{
    if (isEmpty(top))
    {
        puts("Stack underflow");
        return NULL;
    }
    *value = top->element;
    return top->next;
}

elementType top(StackType *top)
{
    return top->element;
}

void display(StackType *top)
{
    StackType *tmp = top;
    while (tmp != NULL)
    {
        printf("%d ", tmp->element);
        tmp = tmp->next;
    }
}
