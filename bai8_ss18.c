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
    int index=0;
    printf("Moi ban nhap vi tri muon them thong tin SV: ");
    scanf("%d", &index);
    if(0<=index && index<5){
        temp++;
        for(int i=5; i>=index; i-- ){
            strcpy(arrSv[i].name, arrSv[i-1].name);
            strcpy(arrSv[i].phoneNumber, arrSv[i-1].phoneNumber);
            arrSv[i].id=arrSv[i-1].id;
            arrSv[i].age=arrSv[i-1].age;
        }
        printf("Moi ban nhap ID sv muon them: ");
        scanf("%d", &arrSv[index].id);
        getchar();
        printf("Moi ban nhap ten sv muon them: ");
        fgets(arrSv[index].name, 50, stdin);
        for(int k=0; k< 50; k++){
            if(arrSv[index].name[k] =='\n'){
                arrSv[index].name[k]='\0';
            }
        }
        
        printf("Moi ban nhap tuoi sv can them: ");
        scanf("%d", &arrSv[index].age);
        getchar();
        printf("Moi ban nhap sdt sv can them: ");
        fgets(arrSv[index].phoneNumber, 15, stdin);
        for(int k=0; k< 15; k++){
            if(arrSv[index].phoneNumber[k] =='\n'){
                arrSv[index].phoneNumber[k]='\0';
            }
        }
        for(int i=0;i<temp; i++){
            printf("%d \t", arrSv[i].id);
            printf("%s \t", arrSv[i].name);
            printf("%d \t", arrSv[i].age);
            printf("%s \t", arrSv[i].phoneNumber);
            printf("\n");
        }
    }else if(index>=5 && index <50){
        for(int i=5; i<=index; i++ ){
            strcpy(arrSv[i].name, "**********");
            strcpy(arrSv[i].phoneNumber, "**********");
            arrSv[i].id=0;
            arrSv[i].age=0;
        }
        printf("Moi ban nhap ID sv muon them: ");
        scanf("%d", &arrSv[index].id);
        getchar();
        printf("Moi ban nhap ten sv muon them: ");
        fgets(arrSv[index].name, 50, stdin);
        for(int k=0; k< 50; k++){
            if(arrSv[index].name[k] =='\n'){
                arrSv[index].name[k]='\0';
            }
        }
        
        printf("Moi ban nhap tuoi sv can them: ");
        scanf("%d", &arrSv[index].age);
        getchar();
        printf("Moi ban nhap sdt sv can them: ");
        fgets(arrSv[index].phoneNumber, 15, stdin);
        for(int i=0;i<=index; i++){
            printf("%d \t", arrSv[i].id);
            printf("%s \t", arrSv[i].name);
            printf("%d \t", arrSv[i].age);
            printf("%s \t", arrSv[i].phoneNumber);
            printf("\n");
        }
    }else {
        printf("Vi tri can them khong hop le \n");
        return 1;
    }
        

    return 0;
}


