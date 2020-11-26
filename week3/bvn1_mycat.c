#include <stdio.h>
#define max 81
void cat(FILE *fptr1)
{
    char s[max];
    int countLine = 0;
    while (fgets(s, max, fptr1) != NULL)
    {
        /* Ghi noi dung len màn hình */
        countLine++;
        puts(s);
    }
}
void cat_p(FILE *fptr1)
{
}

void main(int argc, char *argv[])
{
    FILE *fptr1;
    char *filename;
    char *lenh;
    char *option;
    if (argc != 3 && argc != 4)
    {
        printf("Nhap sai doi so dong lenh!\n");
        printf("Nhap lai theo mau: ./bvn1 <cat hoặc cat-p> <tên file>)\n"
               "Vi du: ./bvn1 cat input.txt\n"
               "Vi du: ./bvn1 cat -p input.txt\n");
    }

    if (argc == 3)

    {
        lenh = argv[1];
        filename = argv[2];

        if ((fptr1 = fopen(filename, "r")) == NULL)
        {
            printf("Cannot open %s.\n", filename);
        }
        else
        {
            cat(fptr1);
        }
    }
    if (argc == 4)

    {
        lenh = argv[1];
        option = argv[2];
        filename = argv[3];

        if ((fptr1 = fopen(filename, "r")) == NULL)
        {
            printf("Cannot open %s.\n", filename);
        }
        else
        {
            cat_p(fptr1);
        }
    }

    printf("\n");
}