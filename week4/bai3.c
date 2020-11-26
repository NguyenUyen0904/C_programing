// bai mystr_cat
#include <stdio.h>
#include <stdlib.h>
#define max 100
int main()
{
    char s1[max], s2[max];
    printf("Nhap vao 2 sau s1, s2\nNhap s1\n");
    gets(s1);
    printf("Nhap s2:\n");
    gets(s2);
    int len1, len2;
    len1 = strlen(s1);
    len2 = strlen(s2);
    char *str;
    str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (str == NULL)
    {
        /* code */
        printf(" Loi caoo phat bo nho\n");
        return NULL;
    }
    strcpy(str, s1);
    strcpy(str + len1, s2);
    printf("===> Sau str ghep tu s1+s2: \n");
    puts(str);
    return 0;
}