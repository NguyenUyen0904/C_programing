// bvn 3 : viet 1 chuong trinh tim ra ky tu in hoa dau tien cua chuoi dung de quy

#include <stdio.h>
#include <string.h>
#define MAX 100
void ChuInHoa(char *str, int i)
{
    if (i < strlen(str))
    {
        if (!(str[i] >= 65 && str[i] <= 90))
            ChuInHoa(str, i + 1);
        else
        {
            printf("Ki tu in hoa dau tien nam o vi tri %d\n", i + 1);
                }
    }
    else
        printf("Khong co ki tu in hoa\n");
}
int main()
{
    char str[MAX];
    gets(str);
    ChuInHoa(str, 0);
    return 0;
}