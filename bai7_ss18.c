#include<stdio.h>
#include<string.h>
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
    int count=0;
    char strName[50];
        printf("Moi ban nhap ten SV can xoa: ");
        fgets(strName, 50,stdin);
        for(int k=0; k< 50; k++){
            if(strName[k] =='\n'){
                strName[k]='\0';
            }
        }
        for(int i=0; i<temp; i++){
            if(strcmp(strName, arrSv[i].name)==0 ){
                count=1;
                temp--;
                for(int j=i; j< temp; j++){
                    strcpy(arrSv[j].name, arrSv[j+1].name);
                    strcpy(arrSv[j].phoneNumber, arrSv[j+1].phoneNumber);
                    arrSv[j].id=arrSv[j+1].id;
                    arrSv[j].age=arrSv[j+1].age;
                }
            }
        }
        if(count!=1){
            printf("SV khong ton tai \n");
            return 1;
        }
        for(int i=0;i<temp; i++){
            printf("%d \t", arrSv[i].id);
            printf("%s \t", arrSv[i].name);
            printf("%d \t", arrSv[i].age);
            printf("%s \t", arrSv[i].phoneNumber);
            printf("\n");
        }

    return 0;
}


