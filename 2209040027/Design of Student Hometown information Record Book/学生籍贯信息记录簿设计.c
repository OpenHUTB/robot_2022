
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 300				//定义最大人数 

struct Student{					//定义学生数据结构 
	char name[10];				//定义姓名 
	char num[20];				//定义学号 
	char localcity[30]; 		//定义籍贯
};
struct Data{
	int count;					//保存学生数量
	struct Student stu[MAX];	//学生数组
}data;

void Choice(){						//菜单函数 
	system("cls");
	printf("***************【学生籍贯信息记录簿】****************\n");
	printf("*                    0.退出系统                     *\n");
	printf("*                    1.录入信息                     *\n");
	printf("*                    2.查询信息                     *\n");
	printf("*                    3.浏览信息                     *\n");
	printf("*                    4.修改信息                     *\n");
	printf("*                    5.删除信息                     *\n");
	printf("*****************************************************\n");
	printf("\t\t请输入一个数<0-5>\n");
	int choice;
	while(1){
		printf("请输入选项：");
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
				printf("错误选项！");
				Choice();
				break; 
		} 
	}		
} 

void Add(){					//添加函数 
	int i,flag=0;
	char choice,name[10],num[20],localcity[30];
	while(1){
		printf("是否继续？[y/n]");
		scanf("%s",&choice);
		if(choice!='y')
			break;
		else{
			printf("请输入学生姓名，学号，籍贯：");
			scanf("%s%s%s",&name,&num,&localcity);
		}
			for(i=0;i<data.count;i++){						
				if(strcmp(num,data.stu[i].num)==0){
					printf("该学号已经存在！\n");
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

void Save(){						//保存数据文件函数 
	int count=data.count,i;
	FILE *fp=fopen("data.txt","wb");
	fwrite(&count,sizeof(int),1,fp);
	for(i=0;i<count;i++)
		fwrite(&data.stu[i],sizeof(struct Student),1,fp);
	fclose(fp);
	printf("保存成功！\n");
} 

void Load(){						//加载文件函数 
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

void Browse(){						//浏览函数 +
	int i;
	system("cls");
	printf("当前所有数据：\n\n");
	printf("---------------------------------------------------------------\n");
	printf("%-10s|%-20s|%-30s|\n", "姓名", "学号", "籍贯");
	for(i=0;i<data.count;i++){
		printf("---------------------------------------------------------------\n");
		printf("%-10s|%-20s|%-30s|\n",data.stu[i].name,data.stu[i].num,data.stu[i].localcity);
	}
	printf("---------------------------------------------------------------\n");
	system("pause");
	Choice();
	}
	
void Amend(){						//修改信息函数 
	char num[20],localcity[30],name[10],choice;
	int flag,key,i;
	printf("是否继续？[y/n]：");
	scanf("%s",&choice);
	if(choice!='y')
		Choice(); 
	printf("请输入需要修改的学生学号：");
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
	printf("该名学生数据：\n");
	printf("---------------------------------------------------------------\n");
	printf("%-10s|%-20s|%-30s|\n", "姓名", "学号", "籍贯");
	printf("%-10s|%-20s|%-30s|\n",data.stu[key].name,data.stu[key].num,data.stu[key].localcity);
	printf("---------------------------------------------------------------\n");
	back:printf("请输入修改后的姓名，学号，籍贯：");
	scanf("%s%s%s",&name,&num,&localcity);
	for(j=0;j<data.count;j++){
		if(strcmp(num,data.stu[j].num)==0&&j!=key){
			printf("该学号已经存在，请重新输入！\n");
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
		printf("学号不存在！\n");
		Amend();
	}
} 

void Delete(){						//删除信息函数 
	char num[20],choice;
	int key,flag=0,i;
	printf("是否继续？[y/n]：");
	scanf("%s",&choice);
	if(choice!='y')
		Choice(); 
	printf("请输入要删除学生的学号：");
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
		printf("不存在该条数据！\n");
		Delete(); 
	}
	
}

void Search(){				//搜索信息函数 
	system("cls");
	printf("***************【学生信息查询系统】****************\n");
	printf("*                  0.返回上一级                   *\n");
	printf("*                  1.按学号查询                   *\n");
	printf("*                  2.按姓名查询                   *\n");
	printf("*                  3.按籍贯查询                   *\n");
	printf("***************************************************\n");
	printf("\t\t请输入一个数<0-3>\n");
	int choice;
	while(1){
		printf("请输入选项：");
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
				printf("错误选项！");
				Search();
				break; 
		} 
	}
} 

void Bynum(){				//按学号查询 
	char num[20];
	int key,flag=0,i;
	system("cls");
	printf("请输入学号：");
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
		printf("该名学生数据：\n");
		printf("---------------------------------------------------------------\n");
		printf("%-10s|%-20s|%-30s|\n", "姓名", "学号", "籍贯");
		printf("%-10s|%-20s|%-30s|\n",data.stu[key].name,data.stu[key].num,data.stu[key].localcity);
		printf("---------------------------------------------------------------\n");
		system("pause");
		Search();
	}else{
		printf("未找到该数据！\n");
		system("pause");
		Search();
	}
}

void Byname(){				//按名字查询 
	char name[10];
	int key,flag=0,i;
	system("cls");
	printf("请输入姓名：");
	scanf("%s",&name);
	for(i=0;i<data.count;i++){
		if(strcmp(data.stu[i].name,name)==0){
			key=i;
			flag++;
			if(flag==1){
				printf("查询到以下数据：\n");
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
		printf("未找到该数据！\n");
		system("pause");
		Search();
	}
}

void Bylocalcity(){				//按籍贯查询 
	char localcity[30];
	int key,flag=0,i;
	system("cls");
	printf("请输入籍贯：");
	scanf("%s",&localcity);
	for(i=0;i<data.count;i++){
		if(strcmp(data.stu[i].localcity,localcity)==0){
			key=i;
			flag++;
			if(flag==1){
				printf("查询到以下数据：\n");
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
		printf("未找到该数据！\n");
		system("pause");
		Search();
	}
}

int main(){				//主函数 
	Load();
	Choice();
	return 0;
}
