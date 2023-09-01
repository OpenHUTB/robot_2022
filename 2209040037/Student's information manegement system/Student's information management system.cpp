/*学生管理系统*/
#include<stdio.h>
#include<string.h>//包含头文件string.h
#define MAX 60//定义MAX最大值为60 
struct student{
	char name[20];
	int age;
	int id;
	char sex[10];
};

struct class_room{
	struct student st[MAX];	//定义多个学生 
	int n;	//当前班级的人数
};

void printf_menu()//打印主菜单函数 
{
	printf("        学生管理系统        \n");
	printf("----------------------------\n");
	printf("|1、添加学生信息            |\n");
	printf("|2、显示所有学生信息        |\n");
	printf("|3、查询学生信息            |\n");
	printf("|4、删除学生信息            |\n");
	printf("|5、修改学生信息            |\n");
	printf("|6、退出                    |\n");
	printf("----------------------------\n");
	printf("请输入相应的序号选择!       \n");
}

void add_student(struct class_room *WLW)//添加学生信息，其中struct class_room *WLW为结构体指针 
{
	printf("请输入学生的姓名：\n");
	scanf("%s",WLW->st[WLW->n].name);	//数组名代表首地址 
	printf("请输入学生的年龄：\n");
	scanf("%d",&WLW->st[WLW->n].age);	//取变量的地址 
	printf("请输入学生的id：\n");
	scanf("%d",&WLW->st[WLW->n].id);
	printf("请输入学生的性别：\n");
	scanf("%s",WLW->st[WLW->n].sex);
	
	WLW->n++;//班级人数加一
}

void show_student(struct class_room *WLW)//显示所有学生信息 
{
	int i;
	for(i=0;i<WLW->n;i++)//WLW->n为当前班级的人数
	{
		printf("the %d student name is %s\n",i+1,WLW->st[i].name);//第一个学生
		printf("the %d student age is %d\n",i+1,WLW->st[i].age);
		printf("the %d student id is %d\n",i+1,WLW->st[i].id);
		printf("the %d student sex is %s\n",i+1,WLW->st[i].sex);
	}
}

int find_student(struct class_room *WLW)//查找指定学生 
{
	int id,i; 
	printf("请输入要查找的学生id：\n");
	scanf("%d",&id);
	
	for(i=0;i<WLW->n;i++)
	{
		if(id==WLW->st[i].id)
		{
			printf("the student is exist!\n");
			printf("the %d student name is %s\n",i+1,WLW->st[i].name);
			printf("the %d student age is %d\n",i+1,WLW->st[i].age);
			printf("the %d student id is %d\n",i+1,WLW->st[i].id);
			printf("the %d student sex is %s\n",i+1,WLW->st[i].sex);
			return i;
		}
	}
	printf("the student is not exist!\n");
	return -1;
}

void remove_student(struct class_room *WLW)//删除指定学生 
{
	int ret,i;
	ret=find_student(WLW);
	
	if(ret!=-1)
	{
		for(i=ret;i<WLW->n-1;i++)
		{
			strcpy(WLW->st[i].name,WLW->st[i+1].name);//由于是字符串类型复制使用头文件string.h中的strcpy复制函数 
			WLW->st[i].age=WLW->st[i+1].age;
			WLW->st[i].id=WLW->st[i+1].id;
			strcpy(WLW->st[i].sex,WLW->st[i+1].sex);
		}
		
		WLW->n--;
	}
	printf("该学生已经删除成功！\n");
}

void change_student(struct class_room *WLW)//修改学生信息 
{
	int ret,choose;
	ret=find_student(WLW);
	if(ret!=-1)
	{
		loop1:
			printf("修改学生信息的哪一项？\n");
			printf("1、姓名\n");
			printf("2、年龄\n");
			printf("3、id\n");
			printf("4、性别\n");
			scanf("%d",&choose);
			
			switch(choose)
			{
				case 1:
					printf("请输入新的学生姓名：\n");
					scanf("%s",WLW->st[ret].name);//输出的代表首地址，所以不需要&取地址 
					break;
				case 2:
					printf("请输入新的学生年龄：\n");
					scanf("%d",&WLW->st[ret].age);
					break;
				case 3:
					printf("请输入新的学生id：\n");
					scanf("%d",&WLW->st[ret].id);
					break;
				case 4: 
					printf("请输入新的学生性别：\n");
					scanf("%s",WLW->st[ret].sex);
					break;
				default:
					printf("输出错误，请重新输入！\n");
					goto loop1;
			}
			
	}
}

int main() 
{
	struct class_room WLW;//定义一个班级为WLW存储学生 
	WLW.n=0;//初始化，学生人数为0 
	
	while(1)//无限循环 
	{
		loop:
			printf_menu();//调用主菜单函数输出主菜单
			int choose;//定义一个序号
			scanf("%d",&choose);
	
		switch(choose)
		{
			case 1:
				add_student(&WLW);//添加学生
				break;
			case 2:
				show_student(&WLW);//显示学生
				break;
			case 3:
				find_student(&WLW);//查询学生
				break;
			case 4:
				remove_student(&WLW);//删除学生
				break; 
			case 5:
				change_student(&WLW);//修改学生
				break;
			case 6:
				return 0;//退出程序
			default://若输出错误的序号，则跳转至重新输出
				printf("输出错误，请重新输入！\n");
				goto loop;	
		}
	
	}
}

