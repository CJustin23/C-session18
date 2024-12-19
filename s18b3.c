#include<stdio.h>
int main(){
	struct SinhVien{
		char name[20];
		int age;
		char phoneNumber[20];
	};
	
	struct SinhVien SinhVien[5];
	
	for(int i=0;i<5;i++){
		printf("Moi ban nhap thong tin Sinh Vien %d:\n",i+1);
		printf("Name:");
		fgets(SinhVien[i].name,sizeof(SinhVien[i].name),stdin);
		printf("Age:");
		scanf("%d",&SinhVien[i].age);
		fflush(stdin);
		printf("PhoneNumber:");
		fgets(SinhVien[i].phoneNumber,sizeof(SinhVien[i].phoneNumber),stdin);
		printf("\n");
		
	}
	printf("In thong tin:\n");
	for(int i=0;i<5;i++){
		printf("Sinh vien %d\n",i+1);
		printf(" %s",SinhVien[i].name);
		printf(" %d\n",SinhVien[i].age);
		printf(" %s\n",SinhVien[i].phoneNumber);
	}
return 0;
}
