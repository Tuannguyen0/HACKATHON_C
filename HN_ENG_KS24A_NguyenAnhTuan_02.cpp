#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Nhap so phan tu cho mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac gia tri cho mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\n1. In gia tri cac phan tu trong mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("\n2. Dem so phan tu chan le trong mang:\n");
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) evenCount++;
        else oddCount++;
    }
    printf("So phan tu chan: %d\n", evenCount);
    printf("So phan tu le: %d\n", oddCount);

    printf("\n3. Tim gia tri lon thu hai trong mang:\n");
    int max1 = arr[0], max2 = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }
    if (max2 != -1) {
        printf("Gia tri lon thu hai: %d\n", max2);
    } else {
        printf("Khong co gia tri lon thu hai.\n");
    }

    printf("\n4. Them mot phan tu vao dau mang:\n");
    int newValue;
    printf("Nhap gia tri can them: ");
    scanf("%d", &newValue);
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = newValue;
    n++;
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("\n5. Xoa mot phan tu tai vi tri cu the:\n");
    int deletePos;
    printf("Nhap vi tri can xoa (1 - %d): ", n);
    scanf("%d", &deletePos);
    if (deletePos >= 1 && deletePos <= n) {
        for (int i = deletePos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        printf("Mang sau khi xoa:\n");
        for (int i = 0; i < n; i++) {
            printf("arr[%d] = %d\n", i, arr[i]);
        }
    } else {
        printf("Vi tri khong hop le.\n");
    }

    printf("\n6. Sap xep mang theo thu tu giam dan (Insertion Sort):\n");
    for (int i = 1; i < n; i++) {  
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("\n7. Tim kiem phan tu bang Binary Search:\n");
    int searchValue;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &searchValue);
    int left = 0, right = n - 1, found = -1;
    while (left <= right) {  
        int mid = (left + right) / 2;
        if (arr[mid] == searchValue) {
            found = mid;
            break;
        } else if (arr[mid] < searchValue) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (found != -1) {
        printf("Tim thay gia tri %d o vi tri %d (sau khi sap xep).\n", searchValue, found + 1);
    } else {
        printf("Khong tim thay gia tri %d trong mang.\n", searchValue);
    }

    printf("\n8. In tat ca so nguyen to trong mang:\n");
    int primeFound = 0;
    for (int i = 0; i < n; i++) {
        int isPrime = 1;
        if (arr[i] <= 1) isPrime = 0;
        for (int j = 2; j <= sqrt(arr[i]); j++) {
            if (arr[i] % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("%d ", arr[i]);
            primeFound = 1;
        }
    }
    if (!primeFound) {
        printf("Khong co so nguyen to nao trong mang.\n");
    }

    printf("\n\n9. Sap xep mang theo thu tu giam dan (Bubble Sort):\n");
    for (int i = 0; i < n - 1; i++) {  
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}
 
