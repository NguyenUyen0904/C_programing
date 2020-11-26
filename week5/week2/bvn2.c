//bvn2. coppy file 1 vào cuối của file 2
#include<stdio.h>
  void cat(FILE *file1, FILE *file2)
{
  char c;
    fseek(file2, SEEK_END, 0);
  while ((c = fgetc(file1)) != EOF){
      fputc(c, file2);
  }
  printf("Nối file hành công !!!\n");
}
void main() {
   FILE *fp1, *fp2;
   char a;
  
   // mo file input.txt trong che do doc
   fp1 = fopen("input.txt", "r");
   if (fp1 == NULL) {
      puts("Khong the mo file sinhvien.txt");
      exit(1);
   }
  
   // mo file output.txt trong che do ghi
   else{
      fp2 = fopen("output.txt", "a++");
      if (fp2 == NULL) {
      puts("Khong the mo file output.txt");
      fclose(fp1);
      exit(1);
      }
   
      else
      {
         cat(fp1, fp2);
         fclose(fp2);
         fclose(fp1);
      } 
   }
   
    
   return(0);
}