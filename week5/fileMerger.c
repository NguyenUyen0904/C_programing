#include <stdio.h>
#include <stdlib.h>
#define CONSTANT 100
typedef struct
{
    char name[CONSTANT];
    char tel[CONSTANT];
    char email[CONSTANT];
} phone;
int main(int argc, char *argv[])
{
    // dong mo file
    FILE *output, *input1, *input2;
    phone *p = (phone *)malloc(1 * sizeof(phone));
    if (argc != 4)
    {
        printf("Error! The correct syntax is ./filemerge  <file1> <file2> <file3>!");
        return 1;
    }

    input1 = fopen(argv[1], "rb");
    input2 = fopen(argv[2], "rb");
    output = fopen(argv[3], "wb");
    if (input1 == NULL || input2 == NULL)
    {
        printf("No such file or directory !__");
        return 0;
    }
    // doc file1 va ghi vao file output
    while ((int *)fread(p, sizeof(phone), 1, input1) != NULL)
    {
        fwrite(p, sizeof(phone), 1, output);
    }
    fclose(input1);
    //docj file 2 vao output
    while ((int *)fread(p, sizeof(phone), 1, input2) != NULL)
    {
        fwrite(p, sizeof(phone), 1, output);
    }
    fclose(output);
    fclose(input2);
    free(p);
}
