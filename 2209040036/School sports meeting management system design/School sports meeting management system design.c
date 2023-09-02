
<<<<<<< HEAD
typedef struct stunode
{
	char sport[20];
	char sex[10];
	char name[10];
	char college[20];
	char grade[10];
	int rank;
	struct stunode* next;
}STU;  			
STU head;		
char stu[20][20];	
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
int N, M, W;		
int k = 0;		
int main(int argc, char* argv[])
{
	int i;
	int select;
	head.next = NULL;		
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
		fflush(stdin);	
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
}/*函数功能：创建某项目的n个获奖信息*/ 
void createList()
{
	int i, n, j = 0;
	int a, b;
	float c;
	int grade1[60], grade2[60];
	int place[60];
	char sport4[20] = "跳高", sport5[20] = "跳高", sport6[20] = "铅球";
	STU* p, * tail, * p3;
	if (k == 0)		/*首次创建链表*/
	{
		k++;
		if (head.next != NULL)
		{
			printf("项目获奖链表已创建!\n");
			return;
		}
		tail = &head;			/*初始建立链表tail指向头结点head*/
		printf("*请输入参赛人数:");
		scanf("%d", &n);
		printf("\n------------------------\n");
		for (i = 1;i <= n;i++)		/*输入n个项目信息到链表中*/
		{
			p = (STU*)malloc(sizeof(STU));		/*新建立一个结点*/
			if (p == NULL)
			{
				printf("建立链表时内存分配失败！\n");
				return;
			}
			printf("项目 性别 姓名 学院 成绩\n");
			scanf("%s%s%s%s%f", p->sport, p->sex, p->name, p->college, &p->grade);
			/*将结点添加到链表尾部*/
			p->rank = 0;
			grade1[j] = p->grade;
			j++;
			tail->next = p;		/*将p所指结点的next赋给新结点的next*/
			p->next = NULL;		/*将新结点的地址赋给p所指结点的next*/
			tail = p;
		}
		if (strcmp(p->sport, sport4) == 0 || strcmp(p->sport, sport5) == 0 || strcmp(p->sport, sport6) == 0)
		{
			for (i = 0;i < j;i++)		/*初始化palce,grade2和grade1*/
			{
				place[i] = 0;
				grade2[i] = 0;
			}
			for (i = 0;i < j;i++)
			{
				grade2[i] = grade1[i];
			}
			for (a = 0;a < j - 1;a++)		/*利用冒泡法进行排序*/
			{
				for (b = 0;b < j - a - 1;b++)
				{
					if (grade2[b] < grade2[b + 1])
					{
						c = grade2[b];		/*交换数据*/
						grade2[b] = grade2[b + 1];
						grade2[b + 1] = c;
					}
				}
			}
			for (i = 0;i < j;i++)		/*比较，找到所对应的排名*/
			{
				for (a = 0;a < j;a++)
				{
					if (grade2[i] == grade1[a])
					{
						place[a] = i + 1;
					}
				}
			}
			p3 = head.next;
			for (i = 0;i < j;i++)
			{
				p3->rank = place[i];
				p3 = p3->next;
			}
		}
		else {
			for (i = 0;i < j;i++)		/*初始化palce,grade2和grade1*/
			{
				place[i] = 0;
				grade2[i] = 0;
			}
			for (i = 0;i < j;i++)
			{
				grade2[i] = grade1[i];
			}
			for (a = 0;a < j - 1;a++)		/*利用冒泡法进行排序*/
			{
				for (b = 0;b < j - a - 1;b++)
				{
					if (grade2[b] > grade2[b + 1])
					{
						c = grade2[b];		/*交换数据*/
						grade2[b] = grade2[b + 1];
						grade2[b + 1] = c;
					}
				}
			}
			for (i = 0;i < j;i++)		/*比较，找到所对应的排名*/
			{
				for (a = 0;a < j;a++)
				{
					if (grade2[i] == grade1[a])
					{
						place[a] = i + 1;
					}
				}
			}
			p3 = head.next;
			for (i = 0;i < j;i++)
			{
				p3->rank = place[i];
				p3 = p3->next;
			}
		}
		return;
	}
	if (k == 1)		/*再次创建链表（相当于在上一次创建的链表的尾部插入）*/
	{
		j = 0;
		STU* p1, * p2, * p5;
		p1 = &head;
		while (1)
		{
			if (p1->next == NULL)break;		/*当链表循环至尾部时结束循环*/
			p1 = p1->next;		/*p1指向下一个结点*/
		}
		p5 = &head;
		while (1)
		{
			if (p5->next == NULL)break;		/*当链表循环至尾部时结束循环*/
			p5 = p5->next;		/*p1指向下一个结点*/
		}
		printf("请输入参赛人数:");
		scanf("%d", &n);
		for (i = 1;i <= n;i++) {
			p2 = (STU*)malloc(sizeof(STU));		/*新建立一个结点*/
			if (p2 == NULL)
			{
				printf("动态内存分配失败！");
				return;
			}
			printf("项目 性别 姓名 学院 成绩\n");
			scanf("%s%s%s%s%f", p2->sport, p2->sex, p2->name, p2->college, &p2->grade);
			p2->rank = 0;
			grade1[j] = p2->grade;
			j++;
			p2->next = p1->next;		/*将p1所指结点的next赋给新的结点的next*/
			p1->next = p2;			/*将新的结点的地址赋给p1所指结点的next*/
			for (i = 0;i < j;i++)		/*初始化palce,grade2和grade1*/
			{
				place[i] = 0;
				grade2[i] = 0;
			}
			a = 0;
			b = 0;
			c = 0;
			if (strcmp(p2->sport, sport4) == 0 || strcmp(p2->sport, sport5) == 0 || strcmp(p2->sport, sport6) == 0)
			{
				for (i = 0;i < j;i++)		/*初始化palce,grade2和grade1*/
				{
					place[i] = 0;
					grade2[i] = 0;
				}
				for (i = 0;i < j;i++)
				{
					grade2[i] = grade1[i];
				}
				for (a = 0;a < j - 1;a++)		/*利用冒泡法进行排序*/
				{
					for (b = 0;b < j - a - 1;b++)
					{
						if (grade2[b] < grade2[b + 1])
						{
							c = grade2[b];		/*交换数据*/
							grade2[b] = grade2[b + 1];
							grade2[b + 1] = c;
						}
					}
				}
				for (i = 0;i < j;i++)		/*比较，找到所对应的排名*/
				{
					for (a = 0;a < j;a++)
					{
						if (grade2[i] == grade1[a])
						{
							place[a] = i + 1;
						}
					}
				}
				p3 = p5;
				for (i = 0;i < j;i++)
				{
					p3 = p3->next;
					p3->rank = place[i];

				}
			}
			else {
				for (i = 0;i < j;i++)		/*初始化palce,grade2和grade1*/
				{
					place[i] = 0;
					grade2[i] = 0;
				}
				for (i = 0;i < j;i++)
				{
					grade2[i] = grade1[i];
				}
				for (a = 0;a < j - 1;a++)		/*利用冒泡法进行排序*/
				{
					for (b = 0;b < j - a - 1;b++)
					{
						if (grade2[b] < grade2[b + 1])
						{
							c = grade2[b];		/*交换数据*/
							grade2[b] = grade2[b + 1];
							grade2[b + 1] = c;
						}
					}
				}
				for (i = 0;i < j;i++)		/*比较，找到所对应的排名*/
				{
					for (a = 0;a < j;a++)
					{
						if (grade2[i] == grade1[a])
						{
							place[a] = i + 1;
						}
					}
				}
				p3 = p5;
				for (i = 0;i < j;i++)
				{
					p3 = p3->next;
					p3->rank = place[i];

				}
			}
		}
		return;
	}
}
/*函数功能：输出所有项目信息*/
void printall()
{
	STU* p;
	if (head.next == NULL)
	{
		printf("未创建学生链表！\n");
		return;
	}
	p = head.next;		/*p指向第一个结点*/
	printf("-------------------------------------\n");
	printf("项目\t性别\t姓名\t学院\t成绩\t名次\n");
	while (p != NULL)		/*当p不为NULL*/
	{
		printf("%s\t%s\t%s\t%s\t%.2f\t%d\n", p->sport, p->sex, p->name, p->college, p->grade, p->rank);
		p = p->next;		/*p指向下一个结点*/
	}
	return;
}
/*函数功能：查询个人的比赛成绩*/
void findperson()
{
	int tatal, goal;
	char name1[10];
	printf("*请输入查询的运动员姓名：");
	scanf("%s", &name1);
	printf("--------------------------------------------\n");
	printf("项目\t性别\t姓名\t学院\t名次\t成绩\t得分\n");
	STU* p3;
	p3 = head.next;		/*p3指向第一个结点*/
	while (p3 != NULL)		/*当p3不为NULL*/
	{

		if (strcmp(p3->name, name1) == 0)
		{
			goal = getscore(p3->rank);		/*调用getscore函数换算出名次所对应的分数*/
			printf("%s\t%s\t%s\t%s\t%.2f\t%d\t%d\n", p3->sport, p3->sex, p3->name, p3->college, p3->grade, p3->rank, goal);
			tatal += goal;
		}
		p3 = p3->next;		/*p3指向下一个结点*/

	}
	printf("总分：%d\n", tatal);
	return;

}
/*函数功能：释放链表中所有存放运动项目信息的结点*/
void freelist()
{
	STU* p;
	p = head.next;			/*从第一个结点开始释放*/
	while (p != NULL)			/*循环释放链表中每个结点的空间*/
	{
		head.next = p->next;
		free(p);			/*释放p指向的结点空间*/
		p = head.next;		/*指针变量p指向下一个待释放的结点*/
	}
	return;
}
/*函数功能：查询学院比赛信息*/
void findcollege()
{
	STU* p4;
	p4 = head.next;		/*p4指向第一个结点*/
	char college1[10];
	printf("*请输入查询的学院：");
	scanf("%s", &college1);
	printf("-------------------------------------\n");
	printf("项目\t性别\t姓名\t学院\t成绩\t名次\n");
	while (p4 != NULL)
	{
		if (strcmp(p4->college, college1) == 0)		/*如果相等，输出链表*/
		{
			printf("%s\t%s\t%s\t%s\t%.2f\t%d\n", p4->sport, p4->sex, p4->name, p4->college, p4->grade, p4->rank);
		}
		p4 = p4->next;		/*p4指向下一个结点*/
	}
	return;
}
/*函数功能：得分计算*/
int getscore(score1)
{
	int n = 0;
	if (score1 == 1)
	{
		n = 7;
		return n;
	}
	else if (score1 == 2)
	{
		n = 5;
		return n;
	}
	else if (score1 == 3)
	{
		n = 3;
		return n;
	}
	else if (score1 == 4)
	{
		n = 2;
		return n;
	}
	else if (score1 == 5)
	{
		n = 1;
		return n;
	}
	else
	{
		n = 0;
		return n;
	}
	return;
}
/*函数信息：查看学院获奖信息*/
void findcollogescore()
{
	int tatal, goal;
	char name1[20];
	printf("*请输入查询的学院：");
	scanf("%s", &name1);
	printf("--------------------------------------------\n");
	printf("项目\t性别\t姓名\t学院\t成绩\t名次\t得分\n");
	STU* p3;
	p3 = head.next;		/*p3指向第一个结点*/
	while (p3 != NULL)
	{

		if (strcmp(p3->college, name1) == 0)		/*如果相等，输出链表*/
		{
			goal = getscore(p3->rank);
			printf("%s\t%s\t%s\t%s\t%.2f\t%d\t%d\n", p3->sport, p3->sex, p3->name, p3->college, p3->grade, p3->rank, goal);
			tatal += goal;
		}
		p3 = p3->next;		/*p3指向下一个结点*/

	}
	printf("总分：%d\n", tatal);
	return;

}
/*函数功能：生成团体团体总分报表*/
void allscore()
{
	int tatal[60], goal = 0, i, man[60], women[60], pla[60], data[60], tatal2[60], man2[60], women2[60];
	STU* p3;

	char ma[10] = { "男" };
	char wo[10] = { "女" };
	printf("-------------------------------------\n");
	printf("院系\t男子\t女子\t总分\t排名\n");
	for (i = 0;i < N;i++)
	{
		p3 = head.next;		/*p3指向第一个结点*/
		tatal[i] = 0;
		man[i] = 0;
		women[i] = 0;
		while (p3 != NULL)
		{
			if (strcmp(p3->college, stu[i]) == 0 && strcmp(p3->sex, ma) == 0)		/*判断是否为同一男子项目*/
			{
				goal = getscore(p3->rank);
				man[i] += goal;		/*计算男子总分*/
			}
			if (strcmp(p3->college, stu[i]) == 0 && strcmp(p3->sex, wo) == 0)		/*判断是否为同一女子项目*/
			{
				goal = getscore(p3->rank);
				women[i] += goal;		/*计算女子总分*/
			}
			p3 = p3->next;		/*p3指向下一个结点*/
		}
		tatal[i] = man[i] + women[i];		/*计算总分*/
	}
	for (i = 0;i < N;i++)
	{
		data[i] = tatal[i];
	}
	int a, b, c;
	for (a = 0;a < N - 1;a++)		/*利用冒泡法进行排序*/
	{
		for (b = 0;b < N - a - 1;b++)
		{
			if (data[b] < data[b + 1])
			{
				c = data[b];		/*交换数据*/
				data[b] = data[b + 1];
				data[b + 1] = c;
			}
		}
	}
	for (i = 0;i < N;i++) {		/*初始化pla*/
		pla[i] = 0;

	}
	for (i = 0;i < N;i++)		/*比较，找到所对应的排名*/
	{
		for (a = 0;a < N;a++)
		{
			if (data[i] == tatal[a])
			{
				pla[a] = i + 1;
			}
		}
	}
	int p;

	for (p = 0;p < N;p++)
	{
		p3 = head.next;		/*p3指向第一个结点*/
		man2[p] = 0;
		women2[p] = 0;
		while (p3 != NULL)
		{
			if (strcmp(p3->college, stu[p]) == 0 && strcmp(p3->sex, ma) == 0)
			{
				goal = getscore(p3->rank);
				man2[p] += goal;
			}
			if (strcmp(p3->college, stu[p]) == 0 && strcmp(p3->sex, wo) == 0)
			{
				goal = getscore(p3->rank);

				women2[p] += goal;
			}
			p3 = p3->next;		/*p3指向下一个结点*/
		}
		tatal2[p] = man2[p] + women2[p];
		printf("%s\t%d\t%d\t%d\t%d\n", stu[p], man2[p], women2[p], tatal2[p], pla[p]);
	}
	return;

}
/*函数功能：查看各项目获奖运动员*/
void getprize()
{
	STU* p;
	int i, j;
	p = &head;
	printf("-------------------------------------\n");
	printf("各项目前三名信息如下：\n");
	printf("项目\t性别\t姓名\t学院\t成绩\t名次\n");
	while (p != NULL)
	{
		if ((p->rank) >= 1 && (p->rank) <= 3)		/*选取各项目排名前三的运动员*/
		{
			printf("%s\t%s\t%s\t%s\t%.2f\t%d\n", p->sport, p->sex, p->name, p->college, p->grade, p->rank);
		}
		p = p->next;
	}
	return;
}
/*函数功能：在链表中修改指定的项目信息*/
void modify()
{
	int n, i;
	char sport1[20], sex1[10], name1[10], college1[20];
	STU* p, * p1;
	p = head.next;		/*p指向第一个结点*/
	printf("请输入要修改位置的相关信息：\n");
	printf("项目 性别 姓名 学院\n");
	scanf("%s%s%s%s", &sport1, &sex1, &name1, &college1);
	if (head.next == NULL)
	{
		printf("未创建项目链表！");
		return;
	}
	while (p != NULL)
	{
		if (strcmp(p->sport, sport1) == 0 && strcmp(p->sex, sex1) == 0 && strcmp(p->name, name1) == 0 && strcmp(p->college, college1) == 0)
		{
			p1 = p;
			break;
		}
		p = p->next;		/*p指向下一个结点*/
	}
	char sport2[10] = "项目", sex2[10] = "性别", name2[10] = "姓名", college2[10] = "学院", grade2[10] = "成绩", rank2[10] = "名次";
	char xiugai[10];
	printf("请输入要修改的信息：");
	scanf("%s", &xiugai);
	if (xiugai[1] == sport2[1])
	{
		printf("请输入修改后的内容：");
		scanf("%s", p1->sport);
		printf("修改成功！");
	}
	else if (xiugai[1] == sex2[1])
	{
		printf("请输入修改后的内容：");
		scanf("%s", p1->sex);
		printf("修改成功！");
	}
	else if (xiugai[1] == name2[1])
	{
		printf("请输入修改后的内容：");
		scanf("%s", p1->name);
		printf("修改成功！");
	}
	else if (xiugai[1] == college2[1])
	{
		printf("请输入修改后的内容：");
		scanf("%s", p1->college);
		printf("修改成功！");
	}
	else if (xiugai[1] == grade2[1])
	{
		printf("请输入修改后的内容：");
		scanf("%f", p1->grade);
		printf("修改成功！");
	}
	else if (xiugai[1] == rank2[1])
	{
		printf("请输入修改后的内容：");
		scanf("%d", &p1->rank);
		printf("修改成功！");
	}
	return;
}
=======
>>>>>>> 00d2222d1b96d07ad55272e0ad27df41e1fd7cca
