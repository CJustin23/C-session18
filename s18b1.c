#include <stdio.h>
struct SinhVien {
    char name[50];
    int age;
    char phoneNumber[100];
};
int main() {
    struct SinhVien sv;
    sprintf(sv.name, "Nguyen Van A");
    sv.age = 20;
    sprintf(sv.phoneNumber, "0123456789");
    printf("Thong tin sinh vien:\n");
    printf("Name: %s\n", sv.name);
    printf("Age: %d\n", sv.age);
    printf("Phone Number: %s\n", sv.phoneNumber);
    return 0;
}

