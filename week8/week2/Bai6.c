// đọc từ file 1 ghi sang file 2. Đổi chữ hoa thành chữ thường, chữ thường thành chữ hoa 
#include<stdio.h>

void main(){
    FILE *fptr1, *fptr2;
    char filename1[]="input.txt";
    char filename2[]="output.txt";
    if((fptr1=fopen(filename1,"r"))==NULL){
        printf("Cannot open %s.\n",filename1);
        
    }else    
    {
        if((fptr2=fopen(filename2,"w"))==NULL){
            printf("Cannot open %s.\n",filename2);
        
        }else
        {
            /* code */
            int c;
            while ((c = fgetc(fptr1)) != EOF)
                {
                if (islower(c)) 
                    c= toupper(c);
                    
	
                else if (isupper(c))
                    c= tolower(c);

                fputc(c,fptr2);
                putchar(c);// in ra các kí tự ra  màn hình                  
                    
                }
            fclose(fptr2);
            fclose(fptr1);
            
        }
        
        
    }
    
   printf("\n"); 
}