#include<stdio.h>
int main(){
	struct SinhVien{
		char name[20];
		int age;
		char phoneNumber[20];
	};
	
	struct SinhVien user01;
	struct SinhVien user02;
	
	printf("Moi ban nhap thong tin Sinh Vien:\n");
	printf("Name:");
	fgets(user01.name,sizeof(user01.name),stdin);
	printf("Age:");
	scanf("%d",&user01.age);
	fflush(stdin);
	printf("PhoneNumber:");
	fgets(user01.phoneNumber,sizeof(user01.phoneNumber),stdin);
	
	printf("In thong tin:\n");
	for(int i=0;i<3;i++){
		switch(i){
			case 0:
				printf(" %s",user01.name);
				break;
			case 1:
				printf(" %d\n",user01.age);
				break;
			case 2:
				printf(" %s\n",user01.phoneNumber);
				break;
		}
	}
return 0;
}

