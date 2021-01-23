//#include "bongDa.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
int main()
{
    int i;
    char choice;
    FILE *input = fopen("bongDa.txt", "r");
    if (input == NULL)
    {
        printf("Cannot open file ! Please try again !\n");
        return 0;
    }
    while (choice != '6')
    {
        printf("-----------Menu---------------");
        printf("\n1. Tạo cây");
        printf("\n2. Kết quả");
        printf("\n3. Tìm kiếm");
        printf("\n4. Xuống hạng");
        printf("\n5. Xuất file");
        printf("\n6. Thoat\n");
        __fpurge(stdin);
        printf("Lựa chọn của bạn la:__ ");
        scanf("%c", &choice);
        printf("\n");
        switch (choice)
        {
        case '1':

            break;
        case '2':

            break;
        case '3':

            break;
        case '4':

            break;
        case '5':

            break;
        case '6':
            break;
        }
    }
    fclose(input);
}