// viet chuong  trinh nhap chieu dai+ rong tu tham so dong lenh. Tinh chu vi 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

double tinhChuVi(double dai, double rong);

int main(int argc, char *argv[])
{
  double dai, rong;
  if (argc != 3 )
    {
      printf("Nhap sai doi so dong lenh!\n");
      printf("Nhap lai theo mau: ./Bai2 <chieu dai> <chieu rong>)\n"
	     "Vi du: ./Bai2 7 3\n");
      return 1;
    }
  
  
  if (argc == 3)
    
    {
      dai= atof(argv[1]);
      rong= atof(argv[2]);
    }
    printf("Chu Vi cua hinh chu nhat: %3f\n", (dai+rong)*2);
    printf("Dien tich hinh chu nhat: %f\n", dai*rong);
}
