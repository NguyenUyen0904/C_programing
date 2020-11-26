//làm quen với file . In ra vi tri con tro file khi mo file 
#include<stdio.h>
enum{success,fail};
main(void){
    FILE *fptr;
    char filename[]="haiku.txt";
    int reval= success;
    if((fptr=fopen(filename,"r"))==NULL){
        printf("Cannot open %s.\n",filename);
        reval=fail;
    }else
    {
        printf("The value of fprt: 0x%p\n",fptr);
        printf("Ready to close the file.\n");
        fclose(fptr);
    }
    return reval;
    
}