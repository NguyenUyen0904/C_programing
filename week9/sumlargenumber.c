#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stackList.h"

int carry = 0;                    // khai báo biến nhớ
StackType *strtonum(char *string) // push từng kí tự trong string nhập vào thành từng number rồi gán vàotừng ô trong  ngăn xếp
{
  StackType *s = NULL; // khai báo 1 cái ngăn xếp có địa chỉ con trỏ *s
  int len = strlen(string);
  for (int i = 0; i < len; ++i)
  {
    s = push(string[i] - '0', s); // -0 để lấy được giá trị number thực của kí tự đó
  }

  return s;
}

StackType *sum(StackType *top1, StackType *top2) // hàm tính tổng
{
  StackType *top = NULL;
  int sum = 0;
  int value1, value2;
  while (!isEmpty(top1) || !isEmpty(top2)) //khi mà 1 trong 2 stack chưa rỗng
  {
    if (!isEmpty(top1) && !isEmpty(top2)) // cả 2 chưa rỗng
    {
      // pop ra giá trính đỉnh 2 stack
      top1 = pop(&value1, top1);
      top2 = pop(&value2, top2);
      sum = value1 + value2 + carry; // sum = 2 giá trị đỉnh +  biến nhớ
      if (sum < 10)                  //nếu tổng <0 thì biến nhớ  <0
      {
        top = push(sum, top);
        carry = 0;
      }
      else // sum>10 biến nhớ =1
      {
        top = push(sum - 10, top);
        carry = 1;
      }
    }
    else if (isEmpty(top1) && !isEmpty(top2)) // nếu empty  stack 1 còn stack 2 vẫn còn
    {
      top2 = pop(&value2, top2);
      sum = value2 + carry;
      if (sum < 10)
      {
        top = push(sum, top);
        carry = 0;
      }
      else
      {
        top = push(sum - 10, top);
        carry = 1;
      }
    }
    else if (isEmpty(top2) && !isEmpty(top1)) // nếu stack 1 còn , stack 2 hết
    {
      top1 = pop(&value1, top1);
      sum = value1 + carry;
      if (sum < 10)
      {
        top = push(sum, top);
        carry = 0;
      }
      else
      {
        top = push(sum - 10, top);
        carry = 1;
      }
    }
  }
  if (isEmpty(top1) && isEmpty(top2) && carry != 0) // nếu s2 stack rỗng nhưng biến nhớ khác 0
  {
    top = push(1, top);
    carry = 0;
  }
  return top;
}

StackType *subtract(StackType *top1, StackType *top2) // trừ 2 số cực lớn
{
  StackType *top = NULL;
  int subtract = 0;
  int carry = 0;
  int value1, value2;
  while (!isEmpty(top1) || !isEmpty(top2))
  {
    if (!isEmpty(top1) && !isEmpty(top2))
    {
      top1 = pop(&value1, top1);
      top2 = pop(&value2, top2);
      if (value1 > value2 + carry)
      {
        subtract = value1 - value2 - carry;
        carry = 0;
        top = push(subtract, top);
      }
      else if (value2 + carry > value1)
      {
        subtract = 10 + value1 - value2 - carry;
        carry = 1;
        top = push(subtract, top);
      }
      else
      {
        subtract = 0;
        carry = 0;
        top = push(subtract, top);
      }
    }
    else if (!isEmpty(top1) && isEmpty(top2))
    {
      top1 = pop(&value1, top1);
      top = push(value1 - carry, top);
    }
  }
  return top;
}

int main(void)
{
  char s1[100];
  char s2[100];
  int value = 0;
  int n;
  printf("Enter two large num a, b (a > b):  \n");
  scanf("%s%s", s1, s2);
  printf("\n\n2 number you entered: \n");
  printf("a: %s\nb: %s\n\n", s1, s2);
  do
  {

    printf("-----------------------\n1.Sum\n2.Subtract\n3.Exit\nYour choice? ");
    scanf("%d", &n);
    if (n == 1)
    {
      StackType *s = sum(strtonum(s1), strtonum(s2));
      puts("Sum of a and b: ");
      display(s);
      puts("");
    }
    else if (n == 2)
    {
      StackType *sub = subtract(strtonum(s1), strtonum(s2));
      puts("Subtract of a and b: ");
      display(sub);
      puts("");
    }
    else if (n == 3)
      puts("Exits");
    else
      puts("Invalid input");
  } while (n != 3);
}
