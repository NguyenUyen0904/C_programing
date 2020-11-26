//tim trung vi( tim gia tri gan nhat voi gia tri trung binh cua 1 mang)
#include<stdio.h>
#include<math.h>
const int SIZE = 100;
void nhapMang(int a[],int n ){
    printf("Nhap vao so phan tu cua mang \n");
    scanf("%d",&n);
    for(int i = 0;i < n; ++i){
        printf("\nNhap phan tu a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
void XuatMang(int a[], int n){
    for(int i = 0;i < n; ++i){
        printf("\nPhan tu a[%d] = %d", i, a[i]);
    }
}
float giaTriTrungBinh(int a[],int n){
    int sum=0;
    for(int i = 0;i < n; ++i){
       sum=sum+a[i];
    }
    float GTTB = (float)sum /n;
    return GTTB;
}
int searchMedian(int a[],int n){
    int hieu;
    int medianindex;
    int minHieu=100000;
    int GTTB;
    for(int i = 0;i < n; ++i){
       hieu=fabs(a[i]-GTTB);
       if(hieu< minHieu){
           minHieu=hieu;
           medianindex=i;
       }
    }
    return a[medianindex];
}
void main(){
    int a[SIZE];
    int n; 
    nhapMang(a,n);
    XuatMang(a,n);
    giaTriTrungBinh(a,n);
    printf("Gia tri trung vi cua mang la: "+ searchMedian(a,n) );
}