#include "bongDa.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <stdio_ext.h>
void InOrderPrinttoFile(FILE *fptr, treeType root)
{
    if (root != NULL)
    {

        InOrderPrinttoFile(fptr, root->left);
        fprintf(fptr, "%-10s-10%s-10%d-10%d\n", root->element.doi1, root->element.doi2, root->element.tiso1, root->element.tiso2);
        InOrderPrinttoFile(fptr, root->right);
        //fprintf(fptr, "%-10s-10%s-10%d-10%d\n", root->element.doi1, root->element.doi2, root->element.tiso1, root->element.tiso2);
    }
}
void importdata(FILE *input, treeType *root)
{
    elementType read;

    while (fscanf(input, "%s\t %[^\n]s\t %[^\n]d\t %[^\n]d", read.doi1, read.doi2, read.tiso1, read.tiso2) != EOF)
    {
        printf("%-15s %-15s %-10d %-10d\n", read.doi1, read.doi2, read.tiso1, read.tiso2);
        insertNode(read, root);
    }
}
int main()
{
    int i;
    char choice;
    FILE *input = fopen("bongDa.txt", "r+");
    if (input == NULL)
    {
        printf("Cannot open file ! Please try again !\n");
        return 0;
    }
    elementType read;
    treeType root = NULL;
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
            importdata(input, &root);
            break;
        case '2':
            inOrderPrint(root);
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