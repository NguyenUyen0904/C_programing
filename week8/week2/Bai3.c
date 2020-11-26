// bai replicate
#include<stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int soLan;
  char *tu;
  if (argc != 3 )
    {
      printf("Nhap sai doi so dong lenh!\n");
      printf("Nhap lai theo mau: ./Bai3 <từ > <số lần nhân>)\n"
	     "Vi du: ./Bai3 go 7\n");
      return 1;
    }

      
tu = argv[1];
soLan = atof(argv[2]);
    

for(int i=0;i<soLan;i++)
        printf("%s", tu);
        
printf("\n");
    
}
