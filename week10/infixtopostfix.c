//Bài tập biểu thức trung tố sang hậu tố
#include "stackArr.h"
#include <stdlib.h>
#include <ctype.h>

int Prec(char ch) // phân chia cấp độ
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
    case '%':
        return 2;
    }
    return -1;
}

char *infixToPostfix(char *s)
{
    StackType stack;
    initialize(stack);
    int i, k;
    for (i = 0, k = -1; s[i]; ++i)
    {

        if (isdigit(s[i])) // kiểm tra xem kí tự truyền vào có phải chữ số thập phân không ?

            s[++k] = s[i]; // nếu đúng thì

        else if (s[i] == '(')
            push(s[i], stack);

        else if (s[i] == ')')
        {
            while (!empty(stack) && peek(stack) != '(')
                s[++k] = pop(stack);
            if (!empty(stack) && peek(stack) != '(')
                return NULL;
            else
                pop(stack);
        }
        else
        {
            while (!empty(stack) &&
                   Prec(s[i]) <= Prec(peek(stack)))
                s[++k] = pop(stack);
            push(s[i], stack);
        }
    }

    while (!empty(stack))
        s[++k] = pop(stack);

    s[++k] = '\0';
    return s;
}

int calculationPostfix(char *s)
{
    StackType stack;
    initialize(stack);
    int i;
    for (i = 0; s[i]; ++i)
    {
        if (isdigit(s[i]))
            push(s[i] - '0', stack);
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (s[i])
            {
            case '+':
                push(val2 + val1, stack);
                break;
            case '-':
                push(val2 - val1, stack);
                break;
            case '*':
                push(val2 * val1, stack);
                break;
            case '/':
                push(val2 / val1, stack);
                break;
            }
        }
    }
    return pop(stack);
}

int main()
{
    int n;
    char s[100];
    char *confix;
    do
    {
        printf("1.Enter arithmetic expression in infix.\n2.Change to postfix form\n3.Calculating value\n4.Exit.\nYour choice? ");
        scanf("%d", &n);
        if (n == 1)
        {
            puts("Arithmetic expression: ");
            scanf("%s", s);
            puts("Done");
        }
        else if (n == 2)
        {
            puts("\nResult: ");
            confix = infixToPostfix(s);
            printf("%s", confix);
            puts("");
        }
        else if (n == 3)
        {
            printf("postfix calculation result: %d\n", calculationPostfix(confix));
        }
        else
            puts("Exit");
    } while (n != 4);
}
