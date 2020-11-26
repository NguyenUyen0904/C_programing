//merge file , dọc 1 dòng cuả  file 1 ghi và file 3, xong đọc 1 dòng cuả  file 2 ghi và file 3 
// cứ thế cho đến khi hết sạch 2 file 
// bai nay error , thay sua sau =))
#include<stdio.h>
const max = 81;
void merger( FILE *fptr1, FILE *fptr2,FILE *fptr3)
    {
        char  s[max],s1[max];
        while (( fgets (s, max, fptr1)!=NULL ) &&( fgets (s1, max, fptr2)!=NULL )){
                fputs(s,fptr3);                                        
                puts(s);
                fputs(s1,fptr3);                                        
                puts(s1);
             }
        /*while (( fgets (s, max, fptr1)==NULL ) && ( fgets (s1, max, fptr2)!=NULL )){
                 
                fputs(s1,fptr3);
                                        
                puts(s1);
            }
        while (( fgets (s, max, fptr1)!=NULL ) && ( fgets (s1, max, fptr2)==NULL )){
                fputs(s,fptr3);
                                        
                puts(s);
            }
            */
        
        fclose(fptr2);
        fclose(fptr1);
            
             
    }

void main(){
    FILE *fptr1, *fptr2, *fptr3;
    char filename1[]="input.txt";
    char filename2[]="input1.txt";
    char filename3[]="output.txt";

    if((fptr1=fopen(filename1,"r"))==NULL)
        printf("Cannot open %s.\n",filename1);
        
    if((fptr2=fopen(filename2,"r"))==NULL)
        printf("Cannot open %s.\n",filename2);
        
       
    if((fptr3=fopen(filename3,"w"))==NULL)
        printf("Cannot open %s.\n",filename3);
    
    merger(fptr1,fptr2,fptr3);

     
    printf("\n"); 
}