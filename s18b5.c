#include<stdio.h>
struct SinhVien{
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
typedef struct SinhVien sv;
int main(void){
    sv arrSv[50]={
        {1,"Nguyen Van A",18,"0987654320"},
        {2,"Nguyen Van B",19,"0987654321"},
        {3,"Nguyen Van C",20,"0987654322"},
        {4,"Nguyen Van D",21,"0987654323"},
        {5,"Nguyen Van E",22,"0987654324"},
    };
    int temp;
    printf("Moi ban nhap id: ");
    scanf("%d", &temp);
    getchar();
    if(0<=temp && temp<=5){
        printf("Moi ban nhap ten SV moi: ");
        fgets(arrSv[temp-1].name,50,stdin);
        // xoa dau xuong dong
        for(int k=0; k< 50; k++){
            if(arrSv[temp-1].name[k] =='\n'){
                arrSv[temp-1].name[k]='\0';
            }
        }
        printf("Moi ban nhap tuoi SV moi: ");
        scanf("%d", &arrSv[temp-1].age);
        for(int i=0; i<5; i++){
            printf("%d \t", arrSv[i].id);
            printf("%s \t", arrSv[i].name);
            printf("%d \t", arrSv[i].age);
            printf("%s \t", arrSv[i].phoneNumber);
            printf("\n");
        }
    }else{
        printf("Khong tim thay thong tin sinh vien \n");
    }
    
    return 0;
}
