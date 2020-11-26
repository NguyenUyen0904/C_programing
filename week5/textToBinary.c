#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#define max 200
typedef struct tudien // khai báo 1 cấu trúc từ điển
{
    char tuvung[max];
} TD;
int main()
{
    //mở file & cấp phát bộ nhớ động
    FILE *input, *output, *read;
    int a, b;
    long irc;
    TD *p = (TD *)malloc(3 * sizeof(TD));
    if (p == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    input = fopen("vnedict.txt", "r");
    if (input == NULL)
    {
        printf("No such file or directory !__");
        return 0;
    }
    output = fopen("vnedict.dat", "wb");
    while (fgets(p->tuvung, max, input) != NULL)
    {
        // printf("%s",p->tuvung);
        fwrite(p, sizeof(TD), 1, output);
    }

    read = fopen("vnedict.dat", "rb");
    printf("Enter the starting and ending point u want : ___");
    scanf("%d %d", &a, &b);
    // nếu nhập sai a, b thì nhập lại do lỗi
    while (b < a || a < 0 || b < 0)
    {
        printf("Error !Enter the starting and ending point u want again !: ___");
        scanf("%d %d", &a, &b);
    }

    if (fseek(read, (b - 1) * sizeof(TD), SEEK_SET) != 0)
    {
        printf("Fseek failed!\n");
        return 1;
    }
    irc = ftell(read);
    rewind(read);
    if (fseek(read, a * sizeof(TD), SEEK_SET) != 0)
    {
        printf("Fseek failed!\n");
        return 1;
    }
    while (ftell(read) != irc)
    {
        fread(p, sizeof(TD), 1, read);
        printf("%s \n", p->tuvung);
    }
    fclose(read);
    fclose(input);
    fclose(output);
    free(p);
}
