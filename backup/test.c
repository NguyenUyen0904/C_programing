#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libary.h"

void readFile(LIST *l);

void disNode(NODE *p);

int main()
{
    LIST l;
    list_init(&l);

    int choice = 0;
    do
    {

        printf("\nMENU\n");
        printf("1) Nap du lieu log lich su di chuyen:\n");
        printf("2) In lich su di chuyen:\n");
        printf("3) Tim kiem theo dia diem:\n");
        printf("4) Tim kiem theo thoi gian:\n");
        printf("5) Kiem tra truy vet moi nhat\n");
        printf("6) Thoat\n\n");
        printf("Nhap lua chon: ");
        scanf("%d%*c", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            readFile(&l);
            printf("\nDoc du lieu thanh cong !\n");

            break;
        case 2:
            printf("%-50s%-10s%-10s\n", "Dia diem", "Gio", "Phut");
            disNode(l.pHead);
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Ban nhap sai! Hay nhap lai:");
            break;
        }
    } while (choice != 6);

    return 0;
}

void readFile(LIST *l)
{
    char filename[30]; // khai báo tên file

    printf("Nhap ten file muon input: "); // Nhập tên file
    scanf("%s", filename);
    FILE *fin = fopen(filename, "r"); // lệnh  mở file
    if (fin == NULL)
    {
        printf("File khong ton tai!\n");
    }

    ELEMENTS tmp;

    while (!feof(fin))
    {
        fscanf(fin, "%s%*c %d%*c %d%*c\n", tmp.diaiem, &tmp.gio, &tmp.phut);

        for (int i = 0; i < strlen(tmp.diaiem); i++)
        {
            if (tmp.diaiem[i] == '_')
            {
                tmp.diaiem[i] = ' ';
            }
        }

        list_add(l, list_node(tmp));
    }
}

void disNode(NODE *p)
{
    if (p != NULL)
    {
        disNode(p->pNext);
        printf("%-50s%-10d%-10d\n", p->data.diaiem, p->data.gio, p->data.phut);
    }
}