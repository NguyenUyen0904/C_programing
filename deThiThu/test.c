#include "test.h"

int read(FILE *input)
{
    int i = 0;
    elementtype p;
    while (fscanf(input, "%d %s %d %d", &(p.id), p.diaDiem, &(p.gio), &(p.phut)) != EOF)
    {
        AddtoTail(p);
    }
    return 1;
}
int main()
{
    char choice;
    node *root;
    node *cur;
    node *prev;

    while (1)
    {
        printf("           ---MENU---\n"
               "1. Nạp dữ liệu log lịch sử di chuyển .  \n"
               "2. In ra lịch sử di chuyển .  \n"
               "3. Tìm kiếm lịch sử di chuyển theo địa điểm .  \n"
               "4. Tìm kiếm thông tin di chuyển theo thời gian            \n"
               "5. Kiểm tra truy vết mới nhất           \n"
               "6. Thoát.             \n");

        __fpurge(stdin);
        printf("\n Nhập vào lựa chọn của bạn : ");
        scanf("%c", &choice);

        while (choice > '6' || choice < '1')
        {
            __fpurge(stdin);
            printf("\nLựa chọn không khả dụng!Mời chọn lại");
            scanf("%c", &choice);
        }

        switch (choice)
        {
        case '1':
        {
            char filename[30]; // khai báo tên file
            elementtype tmp;

            printf("Input file name: "); // Nhập tên file
            scanf("%s", filename);

            FILE *fptr = fopen(filename, "r"); // lệnh  mở file
            if (fptr == NULL)
            {
                printf("File khong ton tai!\n");
                return -1;
            }
            read(fptr);
            printf("Du lieu nap thanh cong !");

            break;
        }

        case '2':
        {

            break;
        }

        case '3':
        {

            break;
        }

        case '4':
        {

            break;
        }

        case '5':
        {

            break;
        }

        case '6':
        {
            exit(0);
            break;
        }
        }
    }
    return 0;
}
