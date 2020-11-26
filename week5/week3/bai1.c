// chèn 1 dòng trắng vào giữa 2 dòng liền nhau trong văn bản 
// đọc từ file 1 ghi sang file 2
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
                if(c!='\n') fputc(c,fptr2);
                else {
                    fputc('\n',fptr2);
                    fputc(c,fptr2);                    
                    }
                                 
                }
            fclose(fptr2);
            fclose(fptr1);
            
        }
        
        
    }
    
   printf("\n"); 
}