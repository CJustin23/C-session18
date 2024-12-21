#include <stdio.h>
#include <string.h>

struct Dish {
    int id;
    char name[50];
    float price;
};

struct Dish menu[100] = {
    {1, "Pho", 30000},
    {2, "Banh Mi", 15000},
    {3, "Bun Cha", 40000},
    {4, "Nem Ran", 25000},
    {5, "Cha Gio", 35000}
};
int soLuongMonAn = 5;

void inMenu() {
    for (int i = 0; i < soLuongMonAn; i++) {
        printf("%d. id: %d, name: %s, price: %.2f\n", i+1, menu[i].id, menu[i].name, menu[i].price);
    }
}

void themMonAn(int viTri, struct Dish monAn) {
    if (viTri < 0 || viTri > soLuongMonAn || soLuongMonAn >= 100) {
        printf("Vi tri khong hop le hoac menu da day.\n");
        return;
    }
    for (int i = soLuongMonAn; i > viTri; i--) {
        menu[i] = menu[i-1];
    }
    menu[viTri] = monAn;
    soLuongMonAn++;
    printf("Them mon an thanh cong!\n");
}

void suaMonAn(int viTri, struct Dish monAn) {
    if (viTri < 0 || viTri >= soLuongMonAn) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    menu[viTri] = monAn;
    printf("Sua mon an thanh cong!\n");
}

void xoaMonAn(int viTri) {
    if (viTri < 0 || viTri >= soLuongMonAn) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = viTri; i < soLuongMonAn - 1; i++) {
        menu[i] = menu[i+1];
    }
    soLuongMonAn--;
    printf("Xoa mon an thanh cong!\n");
}

void sapXepMenu(int tangDan) {
    for (int i = 0; i < soLuongMonAn - 1; i++) {
        for (int j = i + 1; j < soLuongMonAn; j++) {
            if ((tangDan && menu[i].price > menu[j].price) || (!tangDan && menu[i].price < menu[j].price)) {
                struct Dish temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
        }
    }
    printf("Sap xep menu thanh cong!\n");
}

void timKiemTuyenTinh(char *name) {
    int found = 0;
    for (int i = 0; i < soLuongMonAn; i++) {
        if (strcmp(menu[i].name, name) == 0) {
            printf("%d. id: %d, name: %s, price: %.2f\n", i+1, menu[i].id, menu[i].name, menu[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay mon an.\n");
    }
}

void timKiemNhiPhan(char *name) {
    int left = 0, right = soLuongMonAn - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int res = strcmp(menu[mid].name, name);
        if (res == 0) {
            printf("%d. id: %d, name: %s, price: %.2f\n", mid+1, menu[mid].id, menu[mid].name, menu[mid].price);
            return;
        }
        if (res < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Khong tim thay mon an.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nMENU\n");
        printf("1. In ra gia tri cac phan tu co trong menu mon an\n");
        printf("2. Them mot phan tu vao vi tri chi dinh\n");
        printf("3. Sua mot phan tu o vi tri chi dinh\n");
        printf("4. Xoa mot phan tu o vi tri chi dinh\n");
        printf("5. Sap xep cac phan tu\n");
        printf("6. Tim kiem phan tu theo ten\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inMenu();
                break;
            case 2: {
                int viTri;
                struct Dish monAn;
                printf("Nhap vi tri: ");
                scanf("%d", &viTri);
                printf("Nhap id: ");
                scanf("%d", &monAn.id);
                printf("Nhap ten: ");
                scanf("%s", monAn.name);
                printf("Nhap gia: ");
                scanf("%f", &monAn.price);
                themMonAn(viTri - 1, monAn);
                break;
            }
            case 3: {
                int viTri;
                struct Dish monAn;
                printf("Nhap vi tri: ");
                scanf("%d", &viTri);
                printf("Nhap id moi: ");
                scanf("%d", &monAn.id);
                printf("Nhap ten moi: ");
                scanf("%s", monAn.name);
                printf("Nhap gia moi: ");
                scanf("%f", &monAn.price);
                suaMonAn(viTri - 1, monAn);
                break;
            }
            case 4: {
                int viTri;
                printf("Nhap vi tri: ");
                scanf("%d", &viTri);
                xoaMonAn(viTri - 1);
                break;
            }
            case 5: {
                printf("a. Giam dan theo price\n");
                printf("b. Tang dan theo price\n");
                char subChoice;
                scanf(" %c", &subChoice);
                if (subChoice == 'a') {
                    sapXepMenu(0);
                } else if (subChoice == 'b') {
                    sapXepMenu(1);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            }
            case 6: {
                printf("a. Tim kiem tuyen tinh\n");
                printf("b. Tim kiem nhi phan\n");
                char subChoice;
                scanf(" %c", &subChoice);
                char name[50];
                printf("Nhap ten mon an: ");
                scanf("%s", name);
                if (subChoice == 'a') {
                    timKiemTuyenTinh(name);
                } else if (subChoice == 'b') {
                    timKiemNhiPhan(name);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            }
            case 7:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    }
}

