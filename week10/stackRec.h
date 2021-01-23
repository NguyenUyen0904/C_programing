#include <stdio.h>
#define MAX 50
typedef int Eltype;
typedef struct StackRec
{
    Eltype storage[MAX];
    int top;
};

typedef struct StackRec StackType;

void initialize(StackType *stack)
{
    (*stack).top = 0;
}

int isEmpty(StackType *stack)
{
    return (*stack).top == 0;
}

int isFull(StackType *stack)
{
    return (*stack).top == MAX;
}

void push(Eltype el, StackType *stack)
{
    if (isFull(stack))
    {
        puts("Stack overflow");
    }
    else
        (*stack).storage[(*stack).top++] = el;
}

Eltype pop(StackType *stack)
{
    if (isEmpty(stack))
        puts("stack underflow");
    else
        return (*stack).storage[--(*stack).top];
}

Eltype peek(StackType *stack)
{
    if (isEmpty(stack))
    {
        puts("overflow");
    }
    else
        return (*stack).storage[(*stack).top - 1];
}