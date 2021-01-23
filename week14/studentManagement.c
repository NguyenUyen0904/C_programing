#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "studentManagement.h"

int main(int argc, char *argv[])
{
    elementType k;
    elementType choice;
    FILE *input;
    treeType root = NULL;
    int i = 0, j;
    input = fopen("studentManagement.txt", "r");
    if (input == NULL)
    {
        printf("No such file or directory !__");
        return 0;
    }

    while (fscanf(input, "%d %lf %s %lf ", &k.maso, &k.mssv, k.name, &k.sdt) != EOF) // doc file den het
    {

        printf("Nhap diem sv %d :__", i + 1);
        scanf("%f", &k.diemthi);
        printf("%d\t%lf\t%s\t%lf\t%f\n", k.maso, k.mssv, k.name, k.sdt, k.diemthi);
        i++;
        insertNode(k, &root);
    }
    inOrderPrint(root);
    printf("Chon so diem thi bat ki :___");
    scanf("%f", &choice.diemthi);
    while (choice.diemthi < 0 || choice.diemthi > 10)
    {
        printf("So diem ko hop le! Chon lai so diem thi bat ki :___");
        scanf("%f", &choice.diemthi);
    }
    printf("Hoc sinh diem <%.2f:\n", choice.diemthi);
    j = lowerThanKey(choice, root, 0);
    printf("\n=> Co %d hoc sinh co diem <%.2f\n", j, choice.diemthi);
    printf("Hoc sinh diem >= %.2f:\n", choice.diemthi);
    j = higherThanKey(choice, root, 0);
    printf("\n=> Co %d hoc sinh co diem >= %.2f\n", j, choice.diemthi);

    fclose(input);
    freeTree(root);
}
