#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stunode
{
	char sport[20];
	char sex[10];
	char name[10];
	char college[20];
	char grade[10];
	int rank;
	struct stunode* next;
}STU;  			/*定义链表结点的结构体类型struct stunode,取别名STU*/
STU head;		/
char stu[20][20];		/
void maininterface();
void createList();
void printall();
void findperson();
void findcollege();
void freelist();
void findcollogescore();
void modify();
void allscore();
void getprize();
int getscore();
int N, M, W;		/*定义整型N，M，W，用于初始化存放参赛院系总数、男子竞赛项目数和女子竞赛项目数*/
int k = 0;		/*用于创建链表时的计数（区分首次创建链表和再次创建链表）*/
int main(int argc, char* argv[])
{
	int i;
	int select;
	head.next = NULL;		/*将头结点的next至为NULL*/
	printf("\t\t\t------------------------\n");
	printf("\t\t\t*******系统初始化*******\n");
	printf("\t\t\t1.请输入参赛院系总数：");
	scanf("%d", &N);
	printf("\t\t\t2.请输入男子竞赛项目数：");
	scanf("%d", &M);
	printf("\t\t\t3.请输入女子竞赛项目数：");
	scanf("%d", &W);
	printf("\t\t\t4.请输入参赛的院系名：");
	for (i = 0;i < N;i++)
	{
		scanf("%s", &stu[i]);
	}
	printf("\n\t\t\t-----------------------\n");
	printf("\t\t\t  运动会参赛学院有：");
	for (i = 0;i < N;i++)
	{
		printf("%s ", stu[i]);
	}
	printf("\n\t\t\t");
	system("pause");
	while (1)
	{
		maininterface();
		printf("\n*请选择需要的操作：");
		scanf("%d", &select);
		fflush(stdin);	/*清除键盘缓冲区*/
		switch (select)	/*根据用户选择，调用相应函数完成操作*/
		{
		case 1:createList();break;
		case 2:findperson();break;
		case 3:findcollege();break;
		case 4:findcollogescore();break;
		case 5:allscore();break;
		case 6:getprize();break;
		case 7:modify();break;
		case 8:printall();break;
		case 0:freelist();exit(0);
		default:printf("输入错误！\n");
		}
		system("pause");
	}
	return 0;
}
/*函数功能：显示菜单*/
void maininterface()
{
	system("cls");	/*清屏*/
	printf("\t\t--------------------------\n");
	printf("\t\t******运动会管理系统******\n");
	printf("\t\t1.输入项目获奖信息\n");
	printf("\t\t2.查询个人的比赛成绩\n");
	printf("\t\t3.查询院系的比赛信息\n");
	printf("\t\t4.查询院系的比赛成绩\n");
	printf("\t\t5.生成团体总分报表\n");
	printf("\t\t6.查看各项目获奖运动员信息\n");
	printf("\t\t7.修改项目信息\n");
	printf("\t\t8.显示所有信息\n");
	printf("\t\t0.退出\n");
	printf("\t\t--------------------------\n");
	return;
}