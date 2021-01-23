#include "thiCaSang.h"

int loadDataFile(int sum, node **root, node **cur, node **prev)
{
  int N;             //so luong may
  char filename[30]; // khai báo tên file
  elementType tmp;

  printf("Input file name: "); // Nhập tên file
  scanf("%s", filename);

  FILE *fptr = fopen(filename, "r"); // lệnh  mở file
  if (fptr == NULL)
  {
    printf("File khong ton tai!\n");
    return -1;
  }

  fscanf(fptr, "%d", &N); // đọc dòng đầu tiên của file

  int i;
  int count = 0;

  for (i = sum; i < N + sum; i++)
  {
    tmp.id = i + 1;
    fscanf(fptr, "%s %d\n", tmp.CPU, &tmp.RAM);
    insertAfterCurrent(tmp, &(*root), &(*cur), &(*prev));
    count++;
  }
  printf("So may vua them moi: %d\n", count);

  fclose(fptr);
  return count;
}

void updateCPU(int N, node **root, node **cur, node **prev)
{
  int ID;
  char newCPU[30];
  node *p;

  printf("Nhap ID may muon nhap: ");
  scanf("%d", &ID);
  while (ID < 1 || ID > N)
  {
    printf("ID>1 va <%d! Nhap lai ID: ", N);
    scanf("%d", &ID);
  }

  __fpurge(stdin);
  printf("Nhap ten CPU moi: ");
  scanf("%s", newCPU);

  for (p = *root; p != NULL; p = p->next)
  {
    if (p->element.id == ID)
    {
      strcpy(p->element.CPU, newCPU);
    }
  }

  while (ID < N)
  {
    ID++;
    printf("ID = %d\n", ID);
    __fpurge(stdin);
    printf("Nhap ten CPU cho may co ID %d: ", ID);
    scanf("%s", newCPU);

    if (strcmp(newCPU, "STOP") == 0)
    {
      printf("Dung chuc nang!\n");
      break;
    }
    if (strcmp(newCPU, "i3") != 0 && strcmp(newCPU, "i5") != 0 && strcmp(newCPU, "i7") != 0 && strcmp(newCPU, "I3") != 0 && strcmp(newCPU, "I5") != 0 && strcmp(newCPU, "I7") != 0)
    {
      printf("Ten CPU ko hop le! Moi ban nhap lai ten CPU :\n");
      printf("Nhap ten CPU moi: ");
      scanf("%s", newCPU);
    }
    for (p = *root; p != NULL; p = p->next)
    {
      if (p->element.id == ID)
      {
        strcpy(p->element.CPU, newCPU);
      }
    }
  }

  printf("%-10s%-10s\n", "CPU", "RAM");
  traverseList(*root);
}

void updateRAM(int N, node **root, node **cur, node **prev)
{
  int ID;
  int newRAM;
  node *p;

  printf("Nhap ID may muon nhap: ");
  scanf("%d", &ID);
  while (ID < 1 || ID > N)
  {
    printf("ID>1 va <%d! Nhap lai ID: ", N);
    scanf("%d", &ID);
  }

  __fpurge(stdin);
  printf("Nhap RAM moi: ");
  scanf("%d", &newRAM);

  for (p = *root; p != NULL; p = p->next)
  {
    if (p->element.id == ID)
    {
      p->element.RAM = newRAM;
    }
  }

  while (ID < N)
  {
    ID++;
    printf("ID = %d\n", ID);
    __fpurge(stdin);
    printf("Nhap RAM moi cho may co ID %d: ", ID);
    scanf("%d", &newRAM);

    for (p = *root; p != NULL; p = p->next)
    {
      if (p->element.id == ID)
      {
        p->element.RAM = newRAM;
      }
    }
  }

  printf("%-10s%-10s\n", "CPU", "RAM");
  traverseList(*root);
}

int main()
{
  char choice;
  node *root;
  node *cur;
  node *prev;

  int sum = 0; //tong so may

  while (1)
  {
    printf("           ---MENU---\n"
           "|1. Load data files.  |\n"
           "|2. Update CPU info.  |\n"
           "|3. Updata RAM info.  |\n"
           "|4. Search.           |\n"
           "|5. Quit.             |\n");

    __fpurge(stdin);
    printf("Input your choice: ");
    scanf("%c", &choice);

    while (choice > '5' || choice < '1')
    {
      __fpurge(stdin);
      printf("Ivalid! Input your choice: ");
      scanf("%c", &choice);
    }

    switch (choice)
    {
    case '1':
    {
      if (sum > 20)
      {
        printf("Danh sach da day, khong them duoc!\n");
        break;
      }

      sum += loadDataFile(sum, &root, &cur, &prev);

      break;
    }

    case '2':
    {
      updateCPU(sum, &root, &cur, &prev);
      break;
    }

    case '3':
    {
      updateRAM(sum, &root, &cur, &prev);
      break;
    }

    case '4':
    {

      break;
    }

    case '5':
    {
      exit(0);
      break;
    }
    }
  }
  return 0;
}
