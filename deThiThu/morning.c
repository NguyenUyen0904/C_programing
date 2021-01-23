#include <stdio.h>
#include <string.h>
#include "20201.h"
#include <stdio_ext.h>
#define max 100
int readfile(char *filename, int num)
{
    int n;
    elementtype may;
    FILE *read = fopen(filename, "r");
    if (read == NULL)
    {
        printf("File ko ton tai\n");
        return 0;
    }
    fscanf(read, "%d\n", &n);
    if ((num + n) > 20)
    {
        printf("Do so may da hon 20 nen se co %d may ko duoc them vao", num + n - 20);
        for (int i = num; i < (num + (num + n) - 20); i++)
        {
            fscanf(read, "%s %d\n", may.CPU, &may.ram);
            may.ID = i;
            AddtoTail(may);
        }
        return (20 - num);
    }
    for (int i = num + 1; i <= (num + n); i++)
    {
        fscanf(read, "%s %d\n", may.CPU, &may.ram);
        may.ID = i;
        AddtoTail(may);
    }
    Traversing();
    return n;
}
void updateCPU(int num)
{
    node *tmp = root;
    int choose;
    printf("Nhap ID may ban muon cap nhat :\n");
    scanf("%d", &choose);
    while (choose < 0 || choose > num)
    {
        printf("ID ko hop le ! Moi nhap lai ID may ban muon cap nhat :\n");
        scanf("%d", &choose);
    }
    while (tmp != NULL)
    {
        if (tmp->element.ID >= choose)
        {
            printf("Moi ban nhap ten CPU :\n");
            scanf("%s", tmp->element.CPU);
            if (strcmp(tmp->element.CPU, "STOP") == 0)
                break;
            while (strlen(tmp->element.CPU) > 2 || tmp->element.CPU[0] < 'A' || tmp->element.CPU[0] > 'z' || tmp->element.CPU[1] > '9')
            {
                printf("Ten CPU ko hop le! Moi ban nhap lai ten CPU :\n");
                scanf("%s", tmp->element.CPU);
            }
            tmp = tmp->next;
        }
        else
            tmp = tmp->next;
    }
    Traversing();
}

void updateRAM(int num)
{
    node *tmp = root;
    int choose;
    printf("Nhap ID may ban muon cap nhat :\n");
    scanf("%d", &choose);
    while (choose < 0 || choose > num)
    {
        printf("ID ko hop le ! Moi nhap lai ID may ban muon cap nhat :\n");
        scanf("%d", &choose);
    }
    while (tmp != NULL)
    {
        if (tmp->element.ID >= choose)
        {
            printf("Moi ban nhap dung luong RAM :\n");
            scanf("%d", &tmp->element.ram);
            if (tmp->element.ram == 83)
            {
                break;
            }
            while (tmp->element.ram != 1 && tmp->element.ram != 2 && tmp->element.ram != 4 && tmp->element.ram != 8 && tmp->element.ram != 16 && tmp->element.ram != 32)
            {
                printf("Moi ban nhap LAI dung luong RAM :\n");
                scanf("%d", &tmp->element.ram);
            }

            tmp = tmp->next;
        }
        else
            tmp = tmp->next;
    }
    Traversing();
}
void search()
{
    node *tmp = root;
    char searching[3];
    printf("Nhap CPU hoac ram may can tim\n");
    scanf("%s", searching);
    if (strlen(searching) == 1)
    {
        while (tmp != NULL)
        {
            if (tmp->element.ram == searching[0] - '0')
            {
                displayNode(tmp);
                tmp = tmp->next;
            }
            else
                tmp = tmp->next;
        }
    }
    if (strcmp(searching, "32") == 0 || strcmp(searching, "16") == 0)
    {
        if (strcmp(searching, "32") == 0)
        {
            while (tmp != NULL)
            {
                if (tmp->element.ram == 32)
                {
                    displayNode(tmp);
                    tmp = tmp->next;
                }
                else
                    tmp = tmp->next;
            }
        }
        else
            while (tmp != NULL)
            {
                if (tmp->element.ram == 16)
                {
                    displayNode(tmp);
                    tmp = tmp->next;
                }
                else
                    tmp = tmp->next;
            }
    }
    if (strlen(searching) == 2 && strcmp(searching, "32") != 0 && strcmp(searching, "16") != 0)
    {
        while (tmp != NULL)
        {
            if (strcmp(tmp->element.CPU, searching) == 0)
            {
                displayNode(tmp);
                tmp = tmp->next;
            }
            else
                tmp = tmp->next;
        }
    }
    if (strlen(searching) > 2)
        printf("Ko tim thay may tinh ban can\n");
}
int main()
{
    char choice;
    int n;
    int i = 0;
    char filename[max];
    int num = 0;

    while (choice != '5')
    {
        printf("|%-30s|\n", "Menu");
        printf("|%-30s|\n", "1. Load data files");
        printf("|%-30s|\n", "2. Update CPU infor");
        printf("|%-30s|\n", "3. Update Ram Infor");
        printf("|%-30s|\n", "4. Search");
        printf("|%-30s|\n", "5. Quit");

        __fpurge(stdin);
        scanf("%c", &choice);
        switch (choice)
        {
        case '1':
            if (num < 20)
            {
                printf("Nhap ten file :\n");
                scanf("%s", filename);
                num += readfile(filename, num);
                printf("So may co trong danh sach la %d\n", num);
            }
            else
                printf("Danh sach da day, ko them duoc\n");
            break;
        case '2':
            updateCPU(num);
            break;
        case '3':
            updateRAM(num);
            break;
        case '4':
            search();
            break;
        }
    }
}