//Bai replace bằng con trỏ
 
#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
#define l 50
void replace_char(char *str, char c1, char c2){
  int i;
  for (i=0;i<strlen(str);i++){
    if (*(str+i)==c1)*(str+i)=c2;
  }
  return;
}
int main(){
  char str[l] ,c1,c2;
  printf("Input a string : ");
  __fpurge(stdin);
  scanf("%[^\n]s",str);
  printf("c1 : ");
   __fpurge(stdin);
  scanf("%c",&c1);
  printf("c2 : ");
   __fpurge(stdin);
  scanf("%c",&c2);
  replace_char(str,c1,c2);
  printf("%s\n",str);
  return 0;
}
