
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 300				//����������� 

struct Student{					//����ѧ�����ݽṹ 
	char name[10];				//�������� 
	char num[20];				//����ѧ�� 
	char localcity[30]; 		//���弮��
};
struct Data{
	int count;					//����ѧ������
	struct Student stu[MAX];	//ѧ������
}data;

void Choice(){						//�˵����� 
	system("cls");
	printf("***************��ѧ��������Ϣ��¼����****************\n");
	printf("*                    0.�˳�ϵͳ                     *\n");
	printf("*                    1.¼����Ϣ                     *\n");
	printf("*                    2.��ѯ��Ϣ                     *\n");
	printf("*                    3.�����Ϣ                     *\n");
	printf("*                    4.�޸���Ϣ                     *\n");
	printf("*                    5.ɾ����Ϣ                     *\n");
	printf("*****************************************************\n");
	printf("\t\t������һ����<0-5>\n");
	int choice;
	while(1){
		printf("������ѡ�");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				exit(0);
				break;
			case 1:
				Add();
				break;
			case 2:
				Search();
				break;
			case 3:
				Browse();
				break;
			case 4:
				Amend();
				break;
			case 5:
				Delete();
				break;
			default:
				printf("����ѡ�");
				Choice();
				break; 
		} 
	}		
} 

void Add(){					//��Ӻ��� 
	int i,flag=0;
	char choice,name[10],num[20],localcity[30];
	while(1){
		printf("�Ƿ������[y/n]");
		scanf("%s",&choice);
		if(choice!='y')
			break;
		else{
			printf("������ѧ��������ѧ�ţ����᣺");
			scanf("%s%s%s",&name,&num,&localcity);
		}
			for(i=0;i<data.count;i++){						
				if(strcmp(num,data.stu[i].num)==0){
					printf("��ѧ���Ѿ����ڣ�\n");
					flag=1;
					break; 
				}
			}
			if(flag==1){
				flag=0;
				continue;
			}else{
				int j=data.count;
				strcpy(data.stu[j].name,name);
				strcpy(data.stu[j].num,num);
				strcpy(data.stu[j].localcity,localcity);
				data.count++;
				flag=0;
			}
	}
	Save();
	Choice();
	
};

void Save(){						//���������ļ����� 
	int count=data.count,i;
	FILE *fp=fopen("data.txt","wb");
	fwrite(&count,sizeof(int),1,fp);
	for(i=0;i<count;i++)
		fwrite(&data.stu[i],sizeof(struct Student),1,fp);
	fclose(fp);
	printf("����ɹ���\n");
} 

void Load(){						//�����ļ����� 
	FILE *fp;
	int count=0;
	if(access("data.txt",0)==-1){
		fp=fopen("data.txt","wb");
		fwrite(&count,sizeof(int),1,fp);
		fclose(fp);
	}
	fp=fopen("data.txt","rb");
	fread(&count,sizeof(int),1,fp);
	data.count=count; 
	fread(data.stu,sizeof(struct Student),data.count,fp);
}

void Browse(){						//������� +
	int i;
	system("cls");
	printf("��ǰ�������ݣ�\n\n");
	printf("---------------------------------------------------------------\n");
	printf("%-10s|%-20s|%-30s|\n", "����", "ѧ��", "����");
	for(i=0;i<data.count;i++){
		printf("---------------------------------------------------------------\n");
		printf("%-10s|%-20s|%-30s|\n",data.stu[i].name,data.stu[i].num,data.stu[i].localcity);
	}
	printf("---------------------------------------------------------------\n");
	system("pause");
	Choice();
	}
	
void Amend(){						//�޸���Ϣ���� 
	char num[20],localcity[30],name[10],choice;
	int flag,key,i;
	printf("�Ƿ������[y/n]��");
	scanf("%s",&choice);
	if(choice!='y')
		Choice(); 
	printf("��������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
	scanf("%s",&num);
	for(i=0;i<data.count;i++){
		if(strcmp(num,data.stu[i].num)==0){
			flag=1;
			key=i;
			break;
		}
	}
	if(flag==1){
		int j;
	printf("����ѧ�����ݣ�\n");
	printf("---------------------------------------------------------------\n");
	printf("%-10s|%-20s|%-30s|\n", "����", "ѧ��", "����");
	printf("%-10s|%-20s|%-30s|\n",data.stu[key].name,data.stu[key].num,data.stu[key].localcity);
	printf("---------------------------------------------------------------\n");
	back:printf("�������޸ĺ��������ѧ�ţ����᣺");
	scanf("%s%s%s",&name,&num,&localcity);
	for(j=0;j<data.count;j++){
		if(strcmp(num,data.stu[j].num)==0&&j!=key){
			printf("��ѧ���Ѿ����ڣ����������룡\n");
			goto back;
			break; 
		}
	}
	strcpy(data.stu[key].name,name);
	strcpy(data.stu[key].num,num);
	strcpy(data.stu[key].localcity,localcity);
	Save();
	Amend();
	}else{
		printf("ѧ�Ų����ڣ�\n");
		Amend();
	}
} 

void Delete(){						//ɾ����Ϣ���� 
	char num[20],choice;
	int key,flag=0,i;
	printf("�Ƿ������[y/n]��");
	scanf("%s",&choice);
	if(choice!='y')
		Choice(); 
	printf("������Ҫɾ��ѧ����ѧ�ţ�");
	scanf("%s",&num);
	for(i=0;i<data.count;i++){
		if(strcmp(num,data.stu[i].num)==0){
			key=i;
			flag=1;
			break;
		}
	}
	if(flag==1){
		for(;key<data.count;key++){
		strcpy(data.stu[key].name,data.stu[key+1].name);
		strcpy(data.stu[key].num,data.stu[key+1].num);
		strcpy(data.stu[key].localcity,data.stu[key+1].localcity);
		}
		data.count--;
		Save();
		Delete();
	}else{
		printf("�����ڸ������ݣ�\n");
		Delete(); 
	}
	
}

void Search(){				//������Ϣ���� 
	system("cls");
	printf("***************��ѧ����Ϣ��ѯϵͳ��****************\n");
	printf("*                  0.������һ��                   *\n");
	printf("*                  1.��ѧ�Ų�ѯ                   *\n");
	printf("*                  2.��������ѯ                   *\n");
	printf("*                  3.�������ѯ                   *\n");
	printf("***************************************************\n");
	printf("\t\t������һ����<0-3>\n");
	int choice;
	while(1){
		printf("������ѡ�");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				Choice();
				break;
			case 1:
				Bynum();
				break;
			case 2:
				Byname();
				break;
			case 3:
				Bylocalcity();
				break;
			default:
				printf("����ѡ�");
				Search();
				break; 
		} 
	}
} 

void Bynum(){				//��ѧ�Ų�ѯ 
	char num[20];
	int key,flag=0,i;
	system("cls");
	printf("������ѧ�ţ�");
	scanf("%s",&num);
	for(i=0;i<data.count;i++){
		if(strcmp(data.stu[i].num,num)==0){
			key=i;
			flag=1;
			break;
		}
	}
	if(flag==1){
		system("cls");
		printf("����ѧ�����ݣ�\n");
		printf("---------------------------------------------------------------\n");
		printf("%-10s|%-20s|%-30s|\n", "����", "ѧ��", "����");
		printf("%-10s|%-20s|%-30s|\n",data.stu[key].name,data.stu[key].num,data.stu[key].localcity);
		printf("---------------------------------------------------------------\n");
		system("pause");
		Search();
	}else{
		printf("δ�ҵ������ݣ�\n");
		system("pause");
		Search();
	}
}

void Byname(){				//�����ֲ�ѯ 
	char name[10];
	int key,flag=0,i;
	system("cls");
	printf("������������");
	scanf("%s",&name);
	for(i=0;i<data.count;i++){
		if(strcmp(data.stu[i].name,name)==0){
			key=i;
			flag++;
			if(flag==1){
				printf("��ѯ���������ݣ�\n");
				printf("---------------------------------------------------------------\n");
			}
			printf("%-10s|%-20s|%-30s|\n",data.stu[key].name,data.stu[key].num,data.stu[key].localcity);
			
		}
	}
	if(flag!=0){
		printf("---------------------------------------------------------------\n");
		system("pause");
		Search();
	}else{
		printf("δ�ҵ������ݣ�\n");
		system("pause");
		Search();
	}
}

void Bylocalcity(){				//�������ѯ 
	char localcity[30];
	int key,flag=0,i;
	system("cls");
	printf("�����뼮�᣺");
	scanf("%s",&localcity);
	for(i=0;i<data.count;i++){
		if(strcmp(data.stu[i].localcity,localcity)==0){
			key=i;
			flag++;
			if(flag==1){
				printf("��ѯ���������ݣ�\n");
				printf("---------------------------------------------------------------\n");
			}
			printf("%-10s|%-20s|%-30s|\n",data.stu[key].name,data.stu[key].num,data.stu[key].localcity);
			
		}
	}
	if(flag!=0){
		printf("---------------------------------------------------------------\n");
		system("pause");
		Search();
	}else{
		printf("δ�ҵ������ݣ�\n");
		system("pause");
		Search();
	}
}

int main(){				//������ 
	Load();
	Choice();
	return 0;
}
