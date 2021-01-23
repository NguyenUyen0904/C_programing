#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxlength 100

//THU VIEN DANH CHO CAY NHI PHAN TIM KIEM (BST)

//typedef ... elementtype;
//Whatever type of element

typedef struct sinhvien
{
    int maso;
    double mssv;
    char name[maxlength];
    double sdt;
    float diemthi;
} SV;
typedef SV elementType;

typedef struct node_type
{
    elementType element;
    struct node_type *left, *right;
} nodeType;

typedef nodeType *treeType; //treetype la 1 con tro tro den kieu Node. treeType = Node*

//1. Khoi tao cay rong
void makeNullTree(treeType *T)
{
    (*T) = NULL;
}

//2. Xem lieu co phai cay rong ko
int isEmptyTree(treeType T)
{
    return T == NULL;
}

//3. Lay con trai
treeType leftChild(treeType n)
{
    if (n != NULL)
        return n->left;
    else
        return NULL;
}

//4. Lay con phai
treeType rightChild(treeType n)
{
    if (n != NULL)
        return n->right;
    else
        return NULL;
}

//5. Tao ra 1 node moi
nodeType *createNode(elementType newData)
{
    nodeType *N;
    N = (nodeType *)malloc(sizeof(nodeType));
    if (N != NULL)
    {
        N->left = NULL;
        N->right = NULL;
        N->element = newData;
    }
    return N;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

//9. Tao cay tim kiem nhi phan
void insertNode(elementType x, treeType *root)
{ //Neu truyen vao con tro -> thay doi ca tree. Neu chi truyen vao root bthg -> phai return de lay gia tri
    if (*root == NULL)
    { //Truong hop co so: nut rong
        /*Create a new node for key x*/
        *root = (nodeType *)malloc(sizeof(nodeType));

        (*root)->element = x;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (x.diemthi <= (*root)->element.diemthi) //Neu khoa them vao < khoa nut goc
        insertNode(x, &(*root)->left);
    else if (x.diemthi > (*root)->element.diemthi)
        insertNode(x, &(*root)->right);
}

//11. Tinh chieu cao cay
int treeHeight(treeType root)
{
    if (root == NULL)
        return -1;
    else
        return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

//15. Ham duyet cay theo thu tu giua
void inOrderPrint(treeType root)
{
    if (root != NULL)
    {
        inOrderPrint(root->left);
        printf("%-5d%-10.0lf%-30s%-15.0lf%-10.2f\n", root->element.maso, root->element.mssv, root->element.name, root->element.sdt, root->element.diemthi);
        inOrderPrint(root->right);
    }
}

//20. Ham giai phong toan bo cay
void freeTree(treeType root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free((void *)root);
    }
}
int lowerThanKey(elementType x, treeType root, int i)
{
    if (root != NULL)
    {
        i = lowerThanKey(x, root->left, i);
        if (root->element.diemthi < x.diemthi)
        {
            printf("%-5d%-10.0lf%-30s%-15.0lf%-10.2f\n", root->element.maso, root->element.mssv, root->element.name, root->element.sdt, root->element.diemthi);
            i++;
        }
        i = lowerThanKey(x, root->right, i);
    }
    return i;
}
int higherThanKey(elementType x, treeType root, int i)
{
    if (root != NULL)
    {
        i = higherThanKey(x, root->left, i);
        if (root->element.diemthi >= x.diemthi)
        {
            printf("%-5d%-10.0lf%-30s%-15.0lf%-10.2f\n", root->element.maso, root->element.mssv, root->element.name, root->element.sdt, root->element.diemthi);
            i++;
        }
        i = higherThanKey(x, root->right, i);
    }
    return i;
}

//higher than key va lower than key la 2 ham de bai yeu cau !!!
