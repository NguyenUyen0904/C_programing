#include <stdio.h>
#define MAX 20
typedef struct phoneaddress_t
{
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;
typedef struct Node
{
    phoneaddress key;
    struct Node *Left, Right;
} NodeType;
typedef Node *TreeType;
TreeType Search(char *email, TreeType Root)
{
    if (Root == NULL)
        return NULL; // not foundelse
    if (strcmp((Root->Key).email, email) == 0)
        return Root;
    else if (strcmp((Root->Key).email, email) < 0) //continue searching in the right sub tree
        return Search(email, Root->right);
    else
    { // continue searching in the left sub tree
        return Search(email, Root->left);
    }
}