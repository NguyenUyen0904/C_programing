#include <stdlib.h>
#include <stdio.h>

// Gộp hai mảng con arr[l...m] và arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;        //khai báo các biến
    int n1 = m - l + 1; // mảng 1= middle-left+1
    int n2 = r - m;     // mảng 2= right -middle

    /* Tạo các mảng tạm */
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    /* Copy dữ liệu sang các mảng tạm */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Gộp hai mảng tạm vừa rồi vào mảng arr*/
    i = 0;                   // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
    j = 0;                   // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
    k = l;                   // IKhởi tạo chỉ số bắt đầu của mảng lưu kết quả
    while (i < n1 && j < n2) // khi ca 2 mang van con phan tu
    {
        if (L[i] <= R[j]) // neu phan tu  mang trai < phan tu  mang phai
        {
            arr[k] = L[i]; // ta add vaof mang sap xep phan tu cua mang trai
            i++;
        }
        else
        {
            arr[k] = R[j]; // con neu ko thi add vao mang sap xep phan tu cua mang phai
            j++;
        }
        k++;
    }

    /* Copy các phần tử còn lại của mảng L vào arr nếu có */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy các phần tử còn lại của mảng R vào arr nếu có */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l là chỉ số trái và r là chỉ số phải của mảng cần được sắp xếp */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Tương tự (l+r)/2, nhưng cách này tránh tràn số khi l và r lớn
        int m = l + (r - l) / 2;

        // Gọi hàm đệ quy tiếp tục chia đôi từng nửa mảng
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/* Hàm xuất mảng */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void randomArray(int *a, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        int input = rand() % 30;
        a[i] = input;
    }
}

int main()
{
    int arr_size = 10;
    int *arr = (int *)malloc(arr_size * sizeof(int));
    randomArray(arr, arr_size);
    printf("Mang chua sap xep \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nMAng da sap xep \n");
    printArray(arr, arr_size);
    return 0;
}