// dung thu vien cay nhi phan tim kiem
#include "dictionary.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
void InOrderPrinttoFile(FILE *fptr, treeType root)
{
    if (root != NULL)
    {
        //printf("%s  \n", root->element.tu);
        InOrderPrinttoFile(fptr, root->left);
        fprintf(fptr, "%s\t%s\n", root->element.tu, root->element.nghia);
        InOrderPrinttoFile(fptr, root->right);
    }
}
void importdata(FILE *input, treeType *root)
{
    elementType read;
    FILE *in = fopen("dictionary.txt", "r+");
    while (fscanf(input, "%s\t %[^\n]s", read.tu, read.nghia) != EOF)
    {
        printf("%15s %15s\n", read.tu, read.nghia);
        insertNode(read, root);
    }
}
int main()
{
    int i;
    char choice;
    FILE *output;
    FILE *input = fopen("dictionary.txt", "r");
    if (input == NULL)
    {
        printf("Cannot open file ! Please try again !\n");
        return 0;
    }
    elementType read;
    char *searching = (char *)malloc(100 * sizeof(char));
    treeType root = NULL;
    int n; // so tu muon nhap
    while (choice != '6')
    {
        printf("\n|%-30s|", "-----Menu----------");
        printf("\n|%-30s|", "1. Import data");
        printf("\n|%-30s|", "2. InOrderPrint");
        printf("\n|%-30s|", "3. Them tu vung");
        printf("\n|%-30s|", "4. Dich tu anh-viet");
        printf("\n|%-30s|", "5. Xoa tu");
        printf("\n|%-30s|\n", "6. Thoat va luu file");
        __fpurge(stdin);
        scanf("%c", &choice);
        switch (choice)
        {
        case '1':
            importdata(input, &root);
            break;
        case '2':
            inOrderPrint(root);
            break;
        case '3':
            printf("Enter the numbers of words u wanna add to the dictionary :\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("Enter the word and the following meaning :\n");
                scanf("%s %s", read.tu, read.nghia);
                insertNode(read, &root);
            }
            break;
        case '4':
            printf("Enter the word u wanna find :\n");
            scanf("%s", searching);
            if (search(searching, root) != NULL)
                printf("The word u wanna find is : %s : %s\n", search(searching, root)->element.tu, search(searching, root)->element.nghia);
            else
                printf("Can't find the meaning of the word !\n");
            break;
        case '5':
            printf("Please enter a word u wanna delete:\n");
            __fpurge(stdin);
            scanf("%s", searching);
            if (search(searching, root) != NULL)
                deleteNode(search(searching, root)->element, &root);
            else
                printf("The word u want to delete is not in the dictionary !\n");
            break;
        case '6':
            output = fopen("tudien.txt", "w+");
            InOrderPrinttoFile(output, root);
            freeTree(root);
            break;
        }
    }
    fclose(input);
    fclose(output);
}