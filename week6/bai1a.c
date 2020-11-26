#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[20];
    char tel[11];
    char email[25];
} address;

typedef struct node
{
    address addr;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

node *makeNode(address addr)
{
    node *p = (node *)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("Can't creat node!\n");
        return NULL;
    }
    p->addr = addr;
    p->next = NULL;
    return p;
}

void insertAfterNode(address addr)
{
    node *p = makeNode(addr);
    if (head == NULL)
        head = tail = p;
    else
    {
        tail->next = p;
        tail = p;
    }
}

void insertAtHead(address addr)
{
    node *p = makeNode(addr);
    if (head == NULL)
        head = tail = p;
    else
    {
        p->next = head;
        head = p;
    }
}

address *nhapDuLieuTuBanPhim(address *addr)
{
    printf("nhap ten: ");
    scanf("%s", addr->name);
    printf("nhap sdt: ");
    scanf("%s", addr->tel);
    printf("nhap email: ");
    scanf("%s", addr->email);
    return addr;
}

void addNewAddress()
{
    int dieukien;
    do
    {
        printf("******************\n"
               "1. Them vao dau\n"
               "2. Them vao cuoi\n"
               "0. Thoat!\n"
               "-> Chon: ");
        scanf("%d", &dieukien);

        if (dieukien == 0)
            return;
        if (dieukien <= 0 || dieukien >= 3)
            printf("Nhap lai!\n");

    } while (dieukien <= 0 || dieukien >= 3);

    address *addr = (address *)malloc(sizeof(address));
    nhapDuLieuTuBanPhim(addr);

    if (dieukien == 1)
        insertAtHead(*addr);
    else
        insertAfterNode(*addr);

    free(addr);
}

int length(node *p)
{
    if (p == NULL)
        return 0;
    else
        return length(p->next) + 1;
}

void insertPosition()
{
    if (length(head) <= 0)
    {
        printf("Danh sach trong!\n");
        return;
    }

    int dieukien;

    do
    {
        printf("******************\n"
               "Danh sach co do dai tu 0 -> %d !\n"
               "-> Chon vi tri: ",
               length(head) - 1);
        scanf("%d", &dieukien);
        if (dieukien < 0 || dieukien > length(head) - 1)
            printf("Nhap lai!\n");

    } while (dieukien < 0 || dieukien > length(head) - 1);

    address *addr = (address *)malloc(sizeof(address));
    nhapDuLieuTuBanPhim(addr);

    int i = 0;
    node *prev = NULL;
    for (node *p = head; p != NULL; p = p->next)
    {
        if (dieukien == 0)
        {
            insertAtHead(*addr);
            break;
        }
        else if (dieukien == i)
        {
            node *new = makeNode(*addr);
            prev->next = new;
            new->next = p;
            break;
        }
        i++;
        prev = p;
    }

    free(addr);
}

void inputDataFromDat()
{
    FILE *fin;
    char filename[] = "phone.dat";
    if ((fin = fopen(filename, "rb")) == NULL)
    {
        printf("Can't open %s\n", filename);
        exit(0);
    }

    address *addr = (address *)malloc(sizeof(address));

    while (1)
    {
        fread(addr, sizeof(address), 1, fin);
        if (feof(fin))
            break;
        insertAfterNode(*addr);
    }

    free(addr);
    fclose(fin);
}

void printList()
{
    printf("%-4s %-20s %-15s %-25s\n", "STT", "Ten", "tel",
           "email\n");

    int i = 0;
    for (node *p = head; p != NULL; p = p->next)
    {
        i++;
        printf("%-4s %-20s %-15s %-25s\n", i, p->addr.name, p->addr.tel,
               p->addr.email);
    }
}

void removeNode()
{
    node *p = NULL;
    while (head != NULL)
    {
        p = head;
        head = head->next;
        free(p);
    }
}

void removeNodeHead()
{
    if (head == NULL)
        return;
    node *p = head;
    head = head->next;
    free(p);
    printf("\n-----Thanh Cong-----\n");
}

void removeNodeTail()
{
    if (head == NULL)
        return;
    else if (head == tail)
        removeNodeHead();
    else
        for (node *p = head; p != NULL; p = p->next)
            if (p->next == tail)
            {
                free(tail);
                p->next = NULL;
                tail = p;
            }
    printf("\n-----Thanh Cong-----\n");
}

void removeNodePosition()
{
    if (length(head) <= 0)
    {
        printf("Danh sach trong!\n");
        return;
    }

    int dieukien;
    do
    {
        printf("******************\n"
               "Danh sach co do dai tu 0 -> %d !\n"
               "-> Chon vi tri: ",
               length(head) - 1);
        scanf("%d", &dieukien);
        if (dieukien < 0 || dieukien > length(head) - 1)
            printf("Nhap lai!\n");

    } while (dieukien < 0 || dieukien > length(head) - 1);

    int i = 0;
    node *prev = NULL;
    for (node *p = head; p != NULL; p = p->next)
    {
        if (dieukien == 0)
        {
            removeNodeHead();
            return;
        }
        else if (dieukien == length(head) - 1)
        {
            removeNodeTail();
            return;
        }
        else if (dieukien == i)
        {
            prev->next = p->next;
            free(p);
            return;
        }
        prev = p;
        i++;
    }
}

void saveDat(FILE *f1, FILE *f2, int vitri)
{
    int i = 0;
    for (node *p = head; p != NULL; p = p->next)
    {
        if (i <= vitri)
            fwrite(p, sizeof(address), 1, f1);
        else if (i > vitri)
            fwrite(p, sizeof(address), 1, f2);
        i++;
    }
}

void printDat(FILE *f)
{
    fseek(f, 0, SEEK_END);
    int skt = ftell(f) / sizeof(address);
    rewind(f);

    address *dt = (address *)malloc(sizeof(address) * skt);
    fread(dt, sizeof(address), skt, f);
    for (int j = 0; j < skt; j++)
    {
        printf("%-4d %-20s %-15s %-25s\n", j + 1, dt[j].name,
               dt[j].tel, dt[j].email);
    }
}

void saveAndPrint(int vitri, int dieukien)
{
    FILE *f1, *f2;
    char filename1[] = "phone1.dat";
    char filename2[] = "phone2.dat";

    if ((f1 = fopen(filename1, "w+b")) == NULL)
    {
        printf("Khong the mo %s\n", filename1);
        return;
    }

    if ((f2 = fopen(filename2, "w+b")) == NULL)
    {
        printf("Khong the mo %s\n", filename2);
        return;
    }

    saveDat(f1, f2, vitri);

    if (dieukien == 1)
        printDat(f1);
    else
        printDat(f2);

    fclose(f1);
    fclose(f2);
}

void slipFile()
{
    int len = length(head);
    printf("Nhap vi tri tach trong khoang 0 -> %d\n"
           "---> Nhap: ",
           len - 1);
    int vitri;
    scanf("%d", &vitri);
    while (vitri < 0 || vitri >= len)
    {
        printf("Nhap lai gia tri!\n"
               "---> Nhap: ");
        scanf("%d", &vitri);
    }

    int dieukien;
    do
    {
        printf("\n1. Luu va In file 1\n"
               "2. Luu va In file 2\n"
               "0. Thoat!\n"
               "---> Chon: ");
        scanf("%d", &dieukien);

        switch (dieukien)
        {
        case 1:
            saveAndPrint(vitri, dieukien);
            break;
        case 2:
            saveAndPrint(vitri, dieukien);
            break;
        case 0:
            break;
        default:
            printf("Nhap lai!\n");
        }
    } while (dieukien != 0);
}

void findAndUpdate()
{
    if (length(head) <= 0)
    {
        printf("Danh sach trong!\n");
        return;
    }

    char fModel[20];
    printf("Nhap Model tim kiem: ");
    scanf("%s", fModel);

    int check = 0, i = 0, checksua = 0;
    for (node *p = head; p != NULL; p = p->next)
    {
        if (strcmp(p->addr.name, fModel) == 0)
        {
            i++;
            check = 1;
            checksua = 1;
            printf("%-4d %-20s %-15s %-25s %s\n", i,
                   p->addr.name, p->addr.tel,
                   p->addr.email);
        }
        if (checksua == 1)
        {
            printf("\n Ban co muon chinh sua khong!\n"
                   "1 - Chinh sua; 0 - Bo qua\n"
                   "---> Chon: ");
            int chinhsua;
            checksua = 0;
            scanf("%d", &chinhsua);
            if (chinhsua == 0)
                continue;

            address *addr = (address *)malloc(sizeof(address));
            nhapDuLieuTuBanPhim(addr);
            p->addr = *addr;
            free(addr);
        }
    }
    if (check == 0)
        printf("\nKhong tim thay!\n");
}

void daoNguocDS()
{
    node *p = NULL;
    node *newHead = NULL, *newTail = NULL;

    while (head != NULL)
    {
        p = head;
        head = head->next;

        if (newHead == NULL)
        {
            p->next = NULL;
            newHead = newTail = p;
        }
        else
        {
            p->next = newHead;
            newHead = p;
        }
    }

    head = newHead;
    tail = newTail;
}

void saveFileDat()
{
    FILE *f;
    char filename[] = "phone.dat";
    if ((f = fopen(filename, "w +b ")) == NULL)
    {
        printf("Khong the mo %s\n", filename);
        return;
    }

    for (node *p = head; p != NULL; p = p->next)
    {
        fwrite(p, sizeof(address), 1, f);
    }

    fclose(f);
}

int main()
{

    int dieukien;
    do
    {
        printf("\n--------------------------\n"
               "1. Nhap tu file phone.dat\n"
               "2. Hien thi\n"
               "3. Them vao dau - cuoi\n"
               "4. Them vao vi tri bat ki\n"
               "5. Xoa vi tri bat ki\n"
               "6. Xoa dau\n"
               "7. Xoa cuoi\n"
               "8. Tim kiem va Cap nhat\n"
               "9. Tach va luu file\n"
               "10. Dao nguoc danh sach\n"
               "11. Luu danh sach\n"
               "0. Thoat!\n"
               "-> Chon: ");
        scanf("%d", &dieukien);

        switch (dieukien)
        {
        case 1:
            removeNode();
            inputDataFromDat();
            printf("\n Nhap du lieu thanh cong!\n");
            break;
        case 2:
            printList();
            break;
        case 3:
            addNewAddress();
            break;
        case 4:
            insertPosition();
            break;
        case 5:
            removeNodePosition();
            break;
        case 6:
            removeNodeHead();
            break;
        case 7:
            removeNodeTail();
            break;
        case 8:
            findAndUpdate();
            break;
        case 9:
            slipFile();
            break;
        case 10:
            daoNguocDS();
            printf("\nDao nguoc thanh cong!\n");
            break;
        case 11:
            saveFileDat();
            printf("Luu thanh cong!\n");
        case 0:
            break;
        default:
            printf("Nhap lai gia tri!\n");
        }

    } while (dieukien != 0);

    removeNode();
    return 0;
}