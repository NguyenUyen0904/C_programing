#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *str;
    str = (char *)malloc(15);
    strcpy(str, "tutirialspoint");
    printf("String : %s , Address: %u\n", str, str);
    str = (char *)realloc(str, 15);
    strcat(str, ".com");
    printf("String : %s , Address: %u\n", str, str);
    free(str);
    return 0;
}