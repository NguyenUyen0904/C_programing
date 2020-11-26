#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#define MAX_LEN 80

typedef struct
{
    char name[20];
    char tel[11];
    char email[25];
} address;
typedef address elementype;
typedef struct node_t node;
typedef struct node_t
{
    elementype element;
    node *next;
};

node *root, *cur, *prev;

node *makeNewNode(elementype element)
{
    node *new = (node *)malloc(sizeof(node));
    new->element = element;
    new->next = NULL;
    return new;
}

//ham tien ich dung rieng cho tung ung dung
elementype readNode()
{
    elementype tmp;
    __fpurge(stdin);
    printf("Nhap ho ten: ");
    gets(tmp.name);
    printf("Nhap so dien thoai: ");
    gets(tmp.tel);
    printf("Nhap mail: ");
    gets(tmp.email);
    return tmp;
}

void displayNode(node *p)
{
    if (p == NULL)
    {
        printf("Loi con tro NULL\n");
        return;
    }
    elementype tmp = p->element;
    printf("%-20s%-15s%-30s %p\n", tmp.name, tmp.tel, tmp.email, p->next);
}

//them 1 ban ghi co san vao dau danh sach
void insertAtHead(elementype element)
{
    node *new = makeNewNode(element);
    new->next = root;
    root = new;
    cur = root;
}

//ham duyet danh sach
void traversingList()
{
    node *p;
    for (p = root; p != NULL; p = p->next)
        displayNode(p);
}

//them ban ghi vao sau vi tri hien tai
void insertAfter(elementype e)
{
    node *new = makeNewNode(e);

    if (root == NULL)
    {
        root = new;
        cur = root;
    }
    else if (cur == NULL && root != NULL)
        return;
    else
    {
        new->next = cur->next;
        cur->next = new;
        /*prev = cur;*/
        cur = cur->next;
    }
}
//
void insertBeforeCurrent(elementype e)
{
    node *new = makeNewNode(e);
    if (root == NULL)
    {
        root = new;
        cur = root;
        prev = NULL;
    }
    else
    {
        new->next = cur;

        /* if cur pointed to first element */
        if (cur == root)
        {
            /* nut moi them vao tro thanh dau danh sach */
            root = new;
        }
        else
            prev->next = new;
        cur = new;
    }
}
void deleteFirstElement()
{
    node *del = root;
    if (del == NULL)
        return;
    root = del->next;
    free(del);
    cur = root; /* prev = NULL; */
}

void deleteCurrentElement()
{
    if (cur == NULL)
        return;
    if (cur == root)
        deleteFirstElement();
    else
    {
        prev->next = cur->next;
        free(cur);
        cur = prev->next;
    }
}

void freeAllList()
{
    node *to_free = root;
    while (to_free != NULL)
    {
        root = root->next;
        free(to_free);
        to_free = root;
    }
}