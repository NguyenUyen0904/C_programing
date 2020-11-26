// read+ write file .dat  so dien thoai
#include <stdio.h>

enum
{
    MAX_ELEMENT = 20
};

// the phone book structure

typedef struct phoneaddress_t
{

    char name[20];

    char tel[11];

    char email[25];

} phoneaddress;
void nhap(phoneaddress phonearr[], int n)
{
    printf("How many contacts do you want to enter(<20)?");

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("name:");
        scanf("%s", phonearr[i].name);

        printf("tel:");
        scanf("%s", phonearr[i].tel);

        printf("email:");
        scanf("%s", phonearr[i].email);
    }
}
void inputFileFromArray(FILE *fp, phoneaddress phonearr[], int n)
{
    int irc = fwrite(phonearr, sizeof(phoneaddress), n, fp);

    fclose(fp);
}
void readFileToArray(FILE *fp, phoneaddress phonearr[], int n)
{
    int irc = fread(phonearr, sizeof(phoneaddress), n, fp);
}
void hienThi(phoneaddress phonearr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s--", phonearr[i].name);

        printf("%s--", phonearr[i].tel);

        printf("%s\n", phonearr[i].email);
    }
}
void main(void)

{

    FILE *fp;

    phoneaddress phonearr[MAX_ELEMENT];

    int i, n, irc;
    int giatri = 0;
    do
    {
        printf("\nFile .dat!\n"
               "1. Tao file .dat\n"
               "2. Doc file phone.dat\n"
               "0. Thoat !\n"
               "Chon: ");
        scanf("%d", &giatri);
        // mo file 2
        if (giatri != 0)
        {
            if ((file2 = fopen(filename2, "w")) == NULL)
            {
                printf("Khong the mo %s\n", filename2);
                return 1;
            }
        }
        switch (giatri)
        {
        case 1:
            copytheokitu(file1, file2);
            break;
        case 2:
            copytheodong(file1, file2);
            break;
        case 3:
            copytheoblock(file1, file2);
            break;
        case 0:
            printf("\nChuong trinh ket thuc!\n\n");
            break;
        default:
            printf("Gia tri khong hop le!\n"
                   "Chon lai gia tri!\n");
        }
        fseek(file1, 0, SEEK_SET);

    } while (giatri != 0);

    fclose(file1);
    fclose(file2);
    return 0;
}
nhap(phonearr, n);

// mo file de viet
if ((fp = fopen("phone.dat", "w+b")) == NULL)
{
    printf("Can not open %s.\n", "phone.dat");
}
inputFileFromArray(fp, phonearr, n);
//mo file de doc

if ((fp = fopen("phone.dat", "rb")) == NULL)
{
    printf("Can not open %s.\n", "phone.dat");
}
readFileToArray(fp, phonearr, n);
hienThi(phonearr, n);
fclose(fp);
}