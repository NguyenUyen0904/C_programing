// đọc từ file 1 ghi sang file 2 bằng tham số dòng lệnh 
#include<stdio.h>

void main (int argc, char *argv[]){
    
  if (argc != 3 )
    {
      printf("Nhap sai doi so dong lenh!\n");
      printf("Nhap lai theo mau: ./mycp <file input> <file output>)\n"
	     "Vi du: ./mycp input.txt output.txt\n");
    
    }
    else
    {
        char *filename1 = argv[1];
        char *filename2 = argv[2];
        
        FILE *fptr1, *fptr2;
        
        if((fptr1=fopen(filename1,"r"))==NULL){
            printf("Cannot open %s.\n",filename1);
            
        }else    
        {
            if((fptr2=fopen(filename2,"w"))==NULL){
                printf("Cannot open %s.\n",filename2);
            
            }else
            {
                int c;
                while ((c = fgetc(fptr1)) != EOF)
                    {
                    fputc(c,fptr2);
                    //putchar(c);// in ra các kí tự ra  màn hình                  
                    }
                fclose(fptr2);
                fclose(fptr1);
                
            }
            
            
        }
        
    
    }
  
   printf("\n"); 
}