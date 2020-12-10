#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
int main()
{

    int a[10] = {4, 9, 5, 100, 26, -18, 13, 77, 1, 34};
    int i;
    treeType root = (nodeType *)malloc(sizeof(nodeType));
    for (i = 0; i < 10; i++)
        insertNode(a[i], &root);
    inorderprint(root);
    printf("Nhập vào số cần xóa: ");
    int x;
    scanf("%d", &x);
    DeleteNode(x, &root);
    inorderprint(root);
}