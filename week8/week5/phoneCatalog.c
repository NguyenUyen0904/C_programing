#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#define CONSTANT 100

typedef struct Phone // khai báo cấu trúc catalog
{
    char model[CONSTANT];
    char memory[CONSTANT];
    double size;
    double price;
} data;
int so1(FILE *input, data *p)
{
    int i = 0;
    FILE *output = fopen("PhoneDB.dat", "wb");
    while (fscanf(input, "%s %s %lf %lf", p->model, p->memory, &(p->size), &(p->price)) != EOF)
    {
        fwrite(p, sizeof(data), 1, output);
        i++;
    }
    fclose(output);
    return i;
}
void so2(int n)
{
    data *k = (data *)malloc(n * sizeof(data));
    int m;
    int i;
    FILE *read = fopen("PhoneDB.dat", "rb");

    while (m != 3)
    {
        int start, amount;
        printf("\nChoose the function u want :\n1.Printf all file.\n2.Print a part.\n3.Exit\n");
        scanf("%d", &m);
        switch (m)

        {
        case 1:
            printf("%-25s %-7s %-15s  %-15s \n", "Model", "Memory", "Size(inches)", "Price(USD)");
            while ((int *)fread(k, sizeof(data), 1, read) != NULL)
            {
                printf("%-25s %-7s %-14.1lf %-16.1lf \n", k->model, k->memory, k->size, k->price);
            }
            break;
        case 2:
            printf("Enter your starting point and numbers of phones u wanna know:__");
            scanf("%d %d", &start, &amount);
            while (start < 0 || amount < 0 || start + amount > n)
            {
                printf("Error !Enter your starting point and numbers of phones u wanna know again !:__");
                scanf("%d %d", &start, &amount);
            }
            if (fseek(read, (start - 1) * sizeof(data), SEEK_SET) != 0)
            {
                printf("Fseek failed!\n");
                return;
            }
            fread(k, sizeof(data), amount, read);
            for (i = 0; i < amount; i++)
            {
                printf("%-25s%-7s%-14.1lf%-16.1lf \n", k[i].model, k[i].memory, k[i].size, k[i].price);
            }
            break;
        }
    }
    fclose(read);
}
void so3(data *p, int n)
{
    FILE *read = fopen("PhoneDB.dat", "rb");
    int i = 1;
    int c;
    printf("%-25s %-7s %-15s  %-15s \n", "Model", "Memory", "Size(inches)", "Price(USD)");
    while ((int *)fread(p, sizeof(data), 1, read) != NULL)
    {
        printf("%-25s %-7s %-14.1lf %-16.1lf \n", p->model, p->memory, p->size, p->price);
        i++;
        if (i % 10 == 0)
        {
            printf("Press Enter to continue viewing !_");
            while ((c = getchar()) != '\n')
            {
                c = getchar();
            }
            system("clear");
        }
    }
    fclose(read);
}
void search(int n)
{
    FILE *read = fopen("PhoneDB.dat", "rb");
    data *x = (data *)calloc(n, sizeof(data));
    int i, j;
    char *m = (char *)calloc(CONSTANT, sizeof(char));
    printf("Enter the phone model :");
    __fpurge(stdin);
    scanf("%s", m);
    printf("%s", m);
    printf("%-25s %-7s %-15s  %-15s \n", "Model", "Memory", "Size(inches)", "Price(USD)");
    fread(x, sizeof(data), n, read);
    for (i = 0; i < n; i++)
    {
        if (strstr((x + i)->model, m) != NULL)
            printf("%-25s %-7s %-14.1lf %-16.1lf \n", (x + i)->model, (x + i)->memory, (x + i)->size, (x + i)->price);
    }
    free(m);
    free(x);
    fclose(read);
}
int main()
{
    FILE *input;

    input = fopen("PhoneDB.txt", "r");
    if (input == NULL)
    {
        printf("No such file or directory !");
        return 0;
    }
    int i;
    int m, n;
    data *p;
    p = (data *)malloc(100 * sizeof(data));
    while (m != 5)
    {
        printf("\nMenu\n1.Import Database from text file.\n2.Import from Database.\n3.Print all Database.\n4.Search for Phone Model.\n5.Exit.\n");
        scanf("%d", &m);
        switch (m)
        {
        case 1:
            n = so1(input, p); // n la so dong cua file
            rewind(input);
            break;
        case 2:
            so2(n);
            break;
        case 3:
            so3(p, n);
            break;
        case 4:
            search(n);
            break;
        case 5:
            printf("\nGoodbye !");
            break;
        }
    }
    free(p);
    fclose(input);
}
