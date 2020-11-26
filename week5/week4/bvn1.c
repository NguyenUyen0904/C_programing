#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
int dodaichuoi;

void subStr(char *str, int offset, int number);

int main()
{
    char chuoi[MAX_LEN + 1];
    char *str;
    int number, offset;
    printf("Nhap xau: ");
    gets(chuoi);
    ///  fgets(chuoi, MAX_LEN, stdin);
    dodaichuoi = strlen(chuoi);
    printf("Xau co %d ki tu\n", dodaichuoi);

    printf("Nhap vi tri ki tu muon lay: ");
    scanf("%d", &offset);
    // truong hop vi tri ki tu muon lay ko nam trong chuoi
    if (offset > dodaichuoi || offset < 0)
    {
        printf("Vi tri bat dau nam ngoai chuoi! Ket thuc!\n");
        return 2;
    }
    //neu nam trong chuoi thi nhap vi tri
    printf("Nhap so ki tu muon lay: ");
    scanf("%d", &number);
    //truong hop do dai subString <0 ==> bao loi
    if (number <= 0)
    {
        printf("So ki tu muon lay phai > 0! Ket thuc!\n");
        return 2;
    }
    // cap phat bo nho cho str( xau nhapp vao)

    str = (char *)malloc((dodaichuoi + 1) * sizeof(char));
    strcpy(str, chuoi);
    subStr(str, offset, number);
    free(str);

    return 0;
}

void subStr(char *str, int offset, int number)
{
    printf("Xau ki tu con la: ");
    for (int i = offset; i < offset + number; i++)
    {
        printf("%c", *(str + i));
        if (*(str + i + 1) == '\0')
            break;
    }
    printf("\n");
}
