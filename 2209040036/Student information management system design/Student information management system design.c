#include <stdio.h>
#include<string.h>
#include <stdlib.h> 
#define LEN sizeof(struct student)
//学生信息结构体 
struct student
{
	int num;
	char name[20];
	char clas[20];
	char sex[5];
	float Eng_score;
	float C_score;
	float total;
	float aver;
};
struct student stu[50];
//系统操作 
int main()
{
	void menu();
	void in();
	void delet();
	void updet();
	void select();
	void print();
	void sort();
	void max();
	void cut();
	void clea();
	menu();
	int n;
	printf("请选择功能(1-9)：\n");
	scanf("%d", &n);
	while (n)
	{
		if (n >= 1 && n <= 9)
		{
			switch (n)
			{
			case 1:in();break;
			case 2:delet();break;
			case 3:updet();break;
			case 4:select();break;
			case 5:print();break;
			case 6:sort();break;
			case 7:max();break;
			case 8:cut();break;
			case 9:clea();break;
			}
			if (n == 9)
			{
				menu();
			}
			printf("\n");
			printf("请选择功能(1-9)：");
			scanf("%d", &n);
		}

		else
		{
			printf("\n");
			printf("请重新输入:");
			scanf("%d", &n);
		}

	}

	return 0;
}
//目录 
void menu()
{
	printf("\n\n\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t||              ----------------               ||\n");
	printf("\t\t||**************学生信息管理系统***************||\n");
	printf("\t\t||              ----------------               ||\n");
	printf("\t\t||                                             ||\n");
	printf("\t\t||~~~~~~~~~~~~~~~1.录入学生信息~~~~~~~~~~~~~~~~||\n");
	printf("\t\t||~~~~~~~~~~~~~~~2.删除学生信息~~~~~~~~~~~~~~~~||\n");
	printf("\t\t||~~~~~~~~~~~~~~~3.修改学生信息~~~~~~~~~~~~~~~~||\n");
	printf("\t\t||~~~~~~~~~~~~~~~4.查询学生信息~~~~~~~~~~~~~~~~||\n");
	printf("\t\t||~~~~~~~~~~~~~~~5.显示学生信息~~~~~~~~~~~~~~~~||\n");
	printf("\t\t||~~~~~~~~~~~~~~~6.排序学生信息~~~~~~~~~~~~~~~~||\n");
	printf("\t\t||~~~~~~~~~~~~~~~7.显示最好成绩~~~~~~~~~~~~~~~~||\n");
	printf("\t\t||~~~~~~~~~~~~~~~8.分组统计成绩~~~~~~~~~~~~~~~~||\n");
	printf("\t\t||~~~~~~~~~~~~~~~9.清屏~~~~~~~~~~~~~~~~~~~~~~~~||\n");
	printf("\t\t||                                             ||\n");
	printf("\t\t||*********************************************||\n");
}
//录入学生信息 
void in()
{
	void print();
	FILE* fp;
	int i, m = 0;
	char ch[2];
	if ((fp = fopen("stu.txt", "rb")) == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&stu[m], LEN, 1, fp) == 1)
		{
			m++;
		}
	}
	fclose(fp);
	if (m == 0)
	{
		printf("文件没有内容\n");
	}
	else
	{
		print();
	}
	if ((fp = fopen("stu.txt", "ab+")) == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	printf("输入学生信息(y/n);\n");
	scanf("%s", ch);
	while (strcmp(ch, "y") == 0 || strcmp(ch, "Y") == 0)
	{
		printf("number:\n");
		scanf("%3d", &stu[m].num);
		for (i = 0;i < m;i++)
		{
			if (stu[i].num == stu[m].num)
			{
				printf("您的信息已存在\n");
				fclose(fp);
				getchar();
				return;
			}
		}
		printf("name:\n");
		scanf("%s", stu[m].name);
		printf("class:\n");
		scanf("%s", stu[m].clas);
		printf("sex:\n");
		scanf("%s", stu[i].sex);
		printf("Eng_score:\n");
		scanf("%f", &stu[m].Eng_score);
		printf("C_score:\n");
		scanf("%f", &stu[m].C_score);
		stu[i].total = stu[i].C_score + stu[i].Eng_score;
		stu[i].aver = (stu[i].C_score + stu[i].Eng_score) / 2;
		if (fwrite(&stu[m], LEN, 1, fp) != 1)
		{
			printf("不能保存\n");
			getchar();
		}
		else
		{
			printf("信息保存成功\n");

			m++;
		}
		printf("是否继续录入学生信息(y/n)：");
		scanf("%s", ch);
	}
	fclose(fp);
}

//删除学生信息 
void delet()
{
	void print();
	FILE* fp;
	int num, m = 0;
	int i, j;
	int flag = 0;
	char ch[2];
	if ((fp = fopen("stu.txt", "rb")) == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&stu[m], LEN, 1, fp) == 1)
		{
			m++;
		}
	}
	fclose(fp);
	if (m == 0)
	{
		printf("文件中没有学生信息\n");
	}
	else
	{
		print();
		printf("请输入需要删除学生信息的学号：");
		scanf("%d", &num);
	}
	for (i = 0;i < m;i++)
	{
		if (stu[i].num == num)
		{
			printf("该学生已找到，是否删除(y/n):");
			scanf("%s", ch);
			if (strcmp(ch, "y") == 0 || strcmp(ch, "Y") == 0)
			{
				for (j = i;j < m;j++)
				{
					stu[j] = stu[j + 1];
				}
				m--;
				flag = 1;
				if ((fp = fopen("stu.txt", "wb")) == NULL)
				{
					printf("文件打开失败\n");
					return;
				}
				for (j = 0;j < m;j++)
				{
					if (fwrite(&stu[j], LEN, 1, fp) != 1)
					{
						printf("不能保存\n");
						getchar();
					}
				}
				fclose(fp);
				printf("删除成功！\n");break;

			}
			else
			{
				printf("学生信息存在，不需要删除。");
				break;
			}
		}

	}
	if (m == i && flag == 0)
	{
		printf("未找到该学生");
	}

}
//修改学生信息 
void updet()
{
	void print();
	int num;
	char name[10];
	char clas[20];
	char sex[5];
	float Eng_score;
	float C_score;
	FILE* fp;
	int m = 0, a;
	int i, j;
	if ((fp = fopen("stu.txt", "rb")) == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&stu[m], LEN, 1, fp) == 1)
		{
			m++;
		}
	}
	fclose(fp);
	if (m == 0)
	{
		printf("文件中没有学生信息\n");
	}
	else
	{
		print();
		printf("请输入需要修改学生信息的学号：");
		scanf("%d", &num);
	}
	for (i = 0;i < m;i++)
	{
		if (num == stu[i].num)
		{
			printf("1:学号，2:姓名，3:班级，4:性别，5:英语成绩，6:C语言成绩\n");
			printf("该学生已被找到，请选择需要修改的内容(1-5)：");
			scanf("%d", &a);
			while (a)
			{
				switch (a)
				{

				case 1:
					printf("将%d学生的学号修改为：", num);
					scanf("%d", &num);
					stu[i].num = num;
					for (j = i + 1;j < m;j++)
					{
						if (stu[j].num == num)
						{
							printf("您修改的学号已存在\n");
							getchar();
							return;
						}
					}
					break;
				case 2:
					printf("将%d学生的姓名修改为：", num);
					scanf("%s", name);
					strcpy(stu[i].name, name);
					break;
				case 3:
					printf("将%d学生的班级修改为：", num);
					scanf("%s", clas);
					strcpy(stu[i].clas, clas);
					break;
				case 4:
					printf("将%d学生的性别修改为：", num);
					scanf("%s", sex);
					strcpy(stu[i].sex, sex);
					break;
				case 5:
					printf("将%d学生的英语成绩修改为：", num);
					scanf("%f", &Eng_score);
					stu[i].Eng_score = Eng_score;
					stu[i].total = stu[i].C_score + stu[i].Eng_score;
					stu[i].aver = (stu[i].C_score + stu[i].Eng_score) / 2;
					break;
				case 6:
					printf("将%d学生的C语言成绩修改为：", num);
					scanf("%f", &C_score);
					stu[i].C_score = C_score;
					stu[i].total = stu[i].C_score + stu[i].Eng_score;
					stu[i].aver = (stu[i].C_score + stu[i].Eng_score) / 2;
					break;
				default:
					printf("选择错误，请重新选择需要修改的内容：");
					scanf("%d", &a);
					break;
				}

				printf("请选择需要修改的内容(如果已修改完成请按0)：");
				scanf("%d", &a);
			}
			if ((fp = fopen("stu.txt", "wb")) == NULL)
			{
				printf("文件打开失败\n");
				return;
			}
			for (j = 0;j < m;j++)
			{
				if (fwrite(&stu[j], LEN, 1, fp) != 1)
				{
					printf("不能保存\n");
					getchar();
				}
			}
			fclose(fp);
			printf("修改成功！\n");
			break;
		}
	}
	if (m == i)
	{
		printf("未找到该学生\n");
	}
}
//查询学生信息 
void select()
{
	int num, m = 0;
	int i;
	FILE* fp;
	if ((fp = fopen("stu.txt", "rb")) == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&stu[m], LEN, 1, fp) == 1)
		{
			m++;
		}
	}
	fclose(fp);
	if (m == 0)
	{
		printf("文件没有内容\n");
		return;
	}
	printf("请输入学生学号进行查询：");
	scanf("%d", &num);
	for (i = 0;i < m;i++)
	{
		if (num == stu[i].num)
		{
			printf("\n");
			printf("该学生信息已被查到；\n");
			printf("学号\t姓名\t班级\t性别\t英语成绩\tC语言成绩\t总成绩\t平均成绩\n");
			printf("%3d\t%s\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t %.2f\n", stu[i].num, stu[i].name, stu[i].clas, stu[i].sex, stu[i].Eng_score, stu[i].C_score, stu[i].total, stu[i].aver);
			break;
		}
	}
	if (m == i)
	{
		printf("该学生信息不存在\n");
		return;
	}
}
//显示学生信息 
void print()
{
	int i, m = 0;
	FILE* fp;
	if ((fp = fopen("stu.txt", "rb")) == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&stu[m], LEN, 1, fp) == 1)
		{
			m++;
		}
	}
	fclose(fp);
	if (m == 0)
	{
		printf("文件中没有内容\n");
	}
	printf("学号\t姓名\t班级\t性别\t英语成绩\tC语言成绩\t总成绩\t平均成绩\n");
	for (i = 0;i < m;i++)
	{
		printf("%3d\t%s\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t %.2f\n", stu[i].num, stu[i].name, stu[i].clas, stu[i].sex, stu[i].Eng_score, stu[i].C_score, stu[i].total, stu[i].aver);
	}
}
//排序 
void sort()
{
	int i, j, m = 0;
	int ch;
	FILE* fp;
	struct student  temp;
	if ((fp = fopen("stu.txt", "rb")) == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&stu[m], LEN, 1, fp) == 1)
		{
			m++;
		}
	}
	fclose(fp);
	if (m == 0)
	{
		printf("文件中没有内容\n");
	}
	printf("1:学号升序，2:英语成绩升序，3:C语言升序，4:总成绩升序，5:平均成绩升序\n");
	printf("请选择显示形式：");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		for (i = 0;i < m;i++)
		{
			for (j = i + 1;j < m;j++)
			{
				if (stu[i].num > stu[j].num)
				{
					temp = stu[i];
					stu[i] = stu[j];
					stu[j] = temp;
				}
			}
		}
		break;
	case 2:
		for (i = 0;i < m;i++)
		{
			for (j = i + 1;j < m;j++)
			{
				if (stu[i].Eng_score > stu[j].Eng_score)
				{
					temp = stu[i];
					stu[i] = stu[j];
					stu[j] = temp;
				}
			}
		}

		break;
	case 3:
		for (i = 0;i < m;i++)
		{
			for (j = i + 1;j < m;j++)
			{
				if (stu[i].C_score > stu[j].C_score)
				{
					temp = stu[i];
					stu[i] = stu[j];
					stu[j] = temp;
				}
			}
		}

		break;
	case 4:
		for (i = 0;i < m;i++)
		{
			for (j = i + 1;j < m;j++)
			{
				if (stu[i].total > stu[j].total)
				{
					temp = stu[i];
					stu[i] = stu[j];
					stu[j] = temp;
				}
			}
		}

		break;
	case 5:
		for (i = 0;i < m;i++)
		{
			for (j = i + 1;j < m;j++)
			{
				if (stu[i].aver > stu[j].aver)
				{
					temp = stu[i];
					stu[i] = stu[j];
					stu[j] = temp;
				}
			}
		}

		break;
	}
	printf("学号\t姓名\t班级\t性别\t英语成绩\tC语言成绩\t总成绩\t平均成绩\n");
	for (i = 0;i < m;i++)
	{
		printf("%3d\t%s\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t %.2f\n", stu[i].num, stu[i].name, stu[i].clas, stu[i].sex, stu[i].Eng_score, stu[i].C_score, stu[i].total, stu[i].aver);
	}

}
//最大值 
void max()
{
	int i, j = 0;
	FILE* fp;
	int m = 0;
	if ((fp = fopen("stu.txt", "rb")) == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&stu[m], LEN, 1, fp) == 1)
		{
			m++;
		}
	}
	fclose(fp);
	if (m == 0)
	{
		printf("文件中没有内容\n");
	}
	for (i = 0;i < m;i++)
	{
		if (stu[i].total > stu[j].total)
			j = i;
	}
	printf("总成绩成绩最高的同学是：\n");
	printf("学号\t姓名\t班级\t性别\t英语成绩\tC语言成绩\t总成绩\t平均成绩\n");
	printf("%3d\t%s\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t %.2f\n", stu[j].num, stu[j].name, stu[j].clas, stu[j].sex, stu[j].Eng_score, stu[j].C_score, stu[j].total, stu[j].aver);

}
//分组统计
void cut()
{
	int i, j;
	float n;
	FILE* fp;
	int m = 0;
	if ((fp = fopen("stu.txt", "rb")) == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&stu[m], LEN, 1, fp) == 1)
		{
			m++;
		}
	}
	fclose(fp);
	if (m == 0)
	{
		printf("文件中没有内容\n");
	}
	printf("请输入按总成绩分组的值：");
	scanf("%f", &n);
	printf("总成绩大于%.2f的同学有：\n", n);
	printf("学号\t姓名\t班级\t性别\t英语成绩\tC语言成绩\t总成绩\t平均成绩\n");
	for (i = 0;i < m;i++)
	{
		if (stu[i].total >= n)
			printf("%3d\t%s\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t %.2f\n", stu[i].num, stu[i].name, stu[i].clas, stu[i].sex, stu[i].Eng_score, stu[i].C_score, stu[i].total, stu[i].aver);
	}
	printf("总成绩小于%.2f的同学有：\n", n);
	printf("学号\t姓名\t班级\t性别\t英语成绩\tC语言成绩\t总成绩\t平均成绩\n");
	for (j = 0;j < m;j++)
	{
		if (stu[j].total < n)
			printf("%3d\t%s\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t %.2f\n", stu[j].num, stu[j].name, stu[j].clas, stu[j].sex, stu[j].Eng_score, stu[j].C_score, stu[j].total, stu[j].aver);
	}
}
//清屏
void clea()
{
	system("cls");
}