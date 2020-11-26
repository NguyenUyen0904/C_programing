//so sánh 2 mảng. giống nhau bằng 1.  khác nhau bằng 0. đối nhau bằng -1


#include <stdio.h>
const int max=100;

void nhapMang(int a[],int n ){
    
   
    for(int i = 0;i < n; ++i){
        printf("\nNhap phan tu a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
int sosanh(int arr1[], int arr2[],int n1, int n2)
{
  
  if(n1==n2){
    int n=n1;
    int dem1 = 0, dem2 = 0;
    for (int i = 0; i < n; i++)
      {
        if (arr1[i] == arr2[i])
    dem1++;
        if (arr1[i] == arr2[n-i-1])
    dem2++;
      }
      printf ("%d",dem1);
    if (dem1 == n)
      return 1;
    else
        if (dem2 == n)
    return -1;
    return 0;
  }
  else
  {
    return 0;
  }
  
    
}
int main()
{
  int n1,n2;
  int arr1[max],arr2[max];
  printf("Nhap vao so phan tu cua mang 1: \n");
   scanf("%d",&n1);
  nhapMang(arr1,n1);
  
  printf("Nhap vao so phan tu cua mang 2: \n");
  scanf("%d",&n2);
  nhapMang(arr2,n2);

  int gttv = sosanh(arr1, arr2,n1,n2);

  if (gttv == 1)
    printf("Hai mang bang nhau !\n");
  else if (gttv == -1)
     printf("Hai mang doi nhau !\n");
  else
    printf("Hai mang khac nhau !\n");
    

  return 0;
}

