// copyy file+ in ra noi dung file + in ra man hinh so dong cua file 
#include<stdio.h>
const max = 81;

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
            char  s[max];
            int countLine=0; 
             while( fgets (s, max, fptr1)!=NULL ) 
                {
                    /* Ghi noi dung len stdout */
                    fputs(s,fptr2);
                    countLine++;
                    puts(s);
                }
            printf("Coppy file thanh cong \n");
            printf("Số dòng của file :  %d ",countLine);

            fclose(fptr2);
            fclose(fptr1);
            
        }
        
        
    }
    
   printf("\n"); 
}