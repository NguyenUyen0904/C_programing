#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//THU VIEN DANH CHO CAY NHI PHAN

//typedef ... elementtype;
//Whatever type of element

typedef int elementType; // khai báo kiểu chung element type

typedef struct node_type
{
    elementType element;
    struct node_type *left, *right;
} nodeType; // khai báo cấu trúc node

typedef nodeType *treeType; //treetype la 1 con tro tro den kieu Node.
//==> treeType = Node*

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

//6. Kiem tra co phai La hay k
int isLeaf(treeType n)
{
    //Neu khong co con trai + con phai -> la Leaf
    if (n != NULL)
    {
        return (leftChild(n) == NULL) && (rightChild(n) == NULL);
    }
    else
        return -1;
}

//7. Dem so node trong cay
int countNode(treeType T)
{
    if (isEmptyTree(T))
        return 0;
    else
        return 1 + countNode(leftChild(T)) + countNode(rightChild(T));
}

//8. Tim kiem nhi phan
treeType search(elementType x, treeType root)
{
    if (root == NULL)
    {                //Neu tree rong || de quy den node leaf ma van ko thay -> return NULL
        return NULL; //Not found
    }
    else if (root->element == x)
    { //Neu tim thay
        return root;
    }
    else if (root->element < x)
    { //Neu < khoa can tim -> tiep tuc tim ben phai
        return search(x, root->right);
    }
    else
    { //Neu > khoa can tim -> tiep tuc tim ben trai
        return search(x, root->left);
    }
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
    else if (x < (*root)->element) //Neu khoa them vao < khoa nut goc
        insertNode(x, &(*root)->left);

    else if (x > (*root)->element)
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
//12. Tinh so nut la (leaf node)
int leafNode(treeType root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (isLeaf(root))
    {
        return 1;
    }
    else
    {
        return leafNode(root->left) + leafNode(root->right);
    }
}
//13. Tinh so nut trong
int innerNode(treeType root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (!isLeaf(root))
    {
        return 1 + innerNode(root->left) + innerNode(root->right);
    }
    else //Neu la leaf
        return 0;
}

//14. So con phai
int numRight(treeType root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->right != NULL)
    {
        return 1 + numRight(root->left) + numRight(root->right);
    }
    else /*neu root->right == NULL*/
        return numRight(root->left);
}

elementType DeleteMin(treeType *root)
{
    elementType k;
    if ((*root)->left == NULL)
    {
        k = (*root)->element;
        (*root) = (*root)->right;
        return k;
    }
    else
        return DeleteMin(&(*root)->left);
}

void DeleteNode(elementType x, treeType *root)
{
    if (*root != NULL)
        if (x < (*root)->element)
            DeleteNode(x, &(*root)->left);
        else if (x > (*root)->element)
            DeleteNode(x, &(*root)->right);
        else if (((*root)->left == NULL) && ((*root)->right == NULL))
            *root = NULL;
        else if ((*root)->left == NULL)
            *root = (*root)->right;
        else if ((*root)->right == NULL)
            *root = (*root)->left;
        else
            (*root)->element = DeleteMin(&(*root)->right);
}
void inorderprint(treeType tree)
{
    if (tree != NULL)
    {
        inorderprint(tree->left);
        printf("%4d\n", tree->element);
        inorderprint(tree->right);
    }
}