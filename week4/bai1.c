#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, n, *p;
    printf(" bạn muốn nhập vào bao nhiêu số ?\n");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    if (p == NULL)
    {
        printf(" Tạo bộ nhớ failed\n");
        return 1;
    }
    printf("Nhap vao cac phan tu cua mang :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("In ra cac phan tu cua mang :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", p[i]);
    }
    printf("\n");
    free(p);
    return 0;
}