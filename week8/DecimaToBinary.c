#include <stdio.h>

long long SoNhiPhan = 0, i = 1;

void ThapSangNhi(int n)
{
    if (n > 0)
    {
        int a = n % 2;
        n /= 2;
        SoNhiPhan += a * i;
        i *= 10;
        ThapSangNhi(n);
    }
    if (n == 0)
        return SoNhiPhan;
}

int main()
{
    int n;
    printf("---->Nhap so n can chuyen tu he 10  sang 2:");
    scanf("%d", &n);
    ThapSangNhi(n);
    printf("\n---->So nhi phan la %lli\n", SoNhiPhan);
    return 0;
}
