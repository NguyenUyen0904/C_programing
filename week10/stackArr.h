#define Max 50
#include <stdio.h>
typedef int Eltype;

typedef Eltype StackType[Max];

int top;

void initialize(StackType stack) //Khởi tạo stack

{
    top = 0;
}

int empty(StackType stack) // Kiểm tra xem stack có rỗng hay ko ?

{
    return top == 0;
}

int full(StackType stack) // kiểm tra xem stack có full hay ko ?

{
    return top == Max;
}

void push(Eltype el, StackType stack) // thêm vào đỉnh stack
{
    if (full(stack))

        printf("stack overflow");

    else
        stack[top++] = el; // gán top = el , sau đó tăng top lên top+1
}

Eltype pop(StackType stack)
{ // lấy ra đỉnh ngăn xếp
    if (empty(stack))

        printf("stack underflow");

    else
        return stack[--top]; // bỏ gía trị top , lùi top xuống top -1
}
Eltype peek(StackType stack) // trả về vị trí đỉnh ngăn xếp
{
    if (empty(stack))
    {

        printf("stack underflow");
    }

    else
        return stack[top - 1];
}
