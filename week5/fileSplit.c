#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define CONSTANT 100
typedef struct
{
    char name[CONSTANT];
    char tel[CONSTANT];
    char email[CONSTANT];
} phone;
int main(int argc, char *argv[])
{ //mo file
    int a;
    long b;
    FILE *input, *output1, *output2;
    phone *p;
    if (argc != 5)
    {
        printf("Error! The correct syntax is ./filesplit <chosen file> <number> <file1> <file2>!");
        return 1;
    }
    a = atoi(argv[2]);
    while (a < 0)
    {
        printf("Error ! Enter the ending point of file %s u want : ___", argv[1]);
        scanf("%d ", &a);
    }
    p = (phone *)malloc(a * sizeof(phone));
    input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("No such file or directory !__");
        return 0;
    }
    output1 = fopen(argv[3], "wb");
    output2 = fopen(argv[4], "wb");
    // doc file input
    fread(p, sizeof(phone), a, input);
    // ghi vao file output1
    fwrite(p, sizeof(phone), a, output1);
    // ghi vao file ouput 2 neu ma file inpit chua het database
    while ((int *)fread(p, sizeof(phone), 1, input) != NULL)
    {
        fwrite(p, sizeof(phone), 1, output2);
    }
    fclose(input);
    fclose(output1);
    fclose(output2);
    free(p);
}
