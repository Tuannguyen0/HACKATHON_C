#include <stdio.h>

int main() {
    int arr[100], n = 0, select, value, index;
    int even = 0, odd = 0;

    while (true) {
        printf("\n=====================MENU=====================\n");
        printf("1. Nhap mang va so phan tu			            \n");
        printf("2. In mang          \n");
        printf("3. Dem so chan le \n");
        printf("4. Tim lon thu hai \n");
        printf("5. Them dau mang\n");
        printf("6. Xoa phan tu  \n");
        printf("7. Sap xep giam dan  \n");
        printf("8. Tim kiem     \n");
        printf("9. In binh phuong so nguyen to  \n");
        printf("10. Sap xep Bubble \n");
        printf("11. Thoat  \n");
        printf("\nMoi nhap lua chon muon thuc hien: ");
        scanf("%d", &select);

		switch (select) {
        case 1: {
            printf("Nhap so phan tu: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("nhap phan tu arr[%d] = ", i);
                scanf("%d", &arr[i]);
            }
        break;
		} case 2: {
            for (int i = 0; i < n; i++) {
                printf("arr[%d] = %d, ", i, arr[i]);
            }
        break;
		} case 3: {
            even = 0;
            odd = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 == 0) {
                    even++;
                } else {
                    odd++;
                }
            }
            printf("So luong phan tu chan: %d\n", even);
            printf("So luong phan tu le: %d\n", odd);
        break;
		} case 4: {
             if (n > 1) {
                int max = arr[0], secondmax = -1;
                for (int i = 1; i < n; i++) {
                    if (arr[i] > max) {
                        secondmax = max;
                        max = arr[i];
                    } else if (arr[i] > secondmax && arr[i] != max) {
                        secondmax = arr[i];
                    }
                }
                printf("Phan tu lon thu hai: %d\n", secondmax);
            } else {
                printf("Mang co it hon 2 phan tu.\n");
            }
        break;
		} case 5: {
            printf("Nhap gia tri: ");
            scanf("%d", &value);
            for (int i = n; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = value;
            n++;
        break;
		} case 6: {
            printf("Nhap vi tri: ");
            scanf("%d", &index);
            if (index >= 0 && index < n) {
                for (int i = index; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
            } else {
                printf("Vi tri khong hop le.\n");
            }
        break;
		} case 7: {
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (arr[i] < arr[j]) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            printf("Da sap xep giam dan(insertion sort).\n");
        break;
		} //case 8: 
		case 9: {
            int tonTaiSoNguyenTo = 0;
            for (int i = 0; i < n; i++) {
                int laSoNguyenTo = 1;
                if (arr[i] < 2) {
                    laSoNguyenTo = 0;
                } else {
                    for (int j = 2; j * j <= arr[i]; j++) {
                        if (arr[i] % j == 0) {
                            laSoNguyenTo = 0;
                            break;
                        }
                    }
                }
                if (laSoNguyenTo) {
                    printf("%d ", arr[i] * arr[i]);
                    tonTaiSoNguyenTo = 1;
                }
            }
            if (!tonTaiSoNguyenTo) {
                printf("Khong ton tai so nguyen to.\n");
            } else {
                printf("\n");
            }
        break;
		} case 10: {
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (arr[j] < arr[j + 1]) {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            printf("Da sap xep giam dan (Bubble).\n");
        break;
		} case 11: {
            printf("Thoat chuong trinh.\n");
            return 0;
        break;
        } default: {
            printf("Lua chon khong hop le.\n");
            printf("vui long chon lai (0-11))");
        break;
        }
    }
	}
}
 
