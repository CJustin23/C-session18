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
    int temp=5;
        printf("Moi ban nhap ID sv muon them: ");
        scanf("%d", &arrSv[temp-1].id);
        getchar();
        printf("Moi ban nhap ten sv muon them: ");
        fgets(arrSv[temp-1].name, 50, stdin);
        for(int k=0; k< 50; k++){
            if(arrSv[temp-1].name[k] =='\n'){
                arrSv[temp-1].name[k]='\0';
            }
        }
        
        printf("Moi ban nhap tuoi sv can them: ");
        scanf("%d", &arrSv[temp-1].age);
        getchar();
        printf("Moi ban nhap sdt sv can them: ");
        fgets(arrSv[temp-1].phoneNumber, 15, stdin);
        for(int i=0;i<temp; i++){
            printf("%d \t", arrSv[i].id);
            printf("%s \t", arrSv[i].name);
            printf("%d \t", arrSv[i].age);
            printf("%s \t", arrSv[i].phoneNumber);
            printf("\n");
        }
    return 0;
}

